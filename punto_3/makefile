distribucion.pdf : datos.dat coeficientes.py
	python coeficientes.py
datos.dat : coeficientes.x
	 ./coeficientes.x > datos.dat
coeficientes.x : coeficientes.c
	gcc coeficientes.c -lm -o coeficientes.x
clean :
	rm -f distribucion.pdf datos.dat coeficientes.x
