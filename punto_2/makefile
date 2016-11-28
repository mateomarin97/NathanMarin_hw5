distribucion.pdf : datos.dat masa.py
	python masa.py
datos.dat : masa.x
	./masa.x > datos.dat
masa.x : masa.c
	gcc masa.c -lm -o masa.x
clean :
	rm -f distribucion.pdf datos.dat masa.x
