distribucion.pdf : datos.dat epicentro.py
	python epicentro.py
datos.dat : epicentro.x
	./epicentro.x > datos.dat
epicentro.x : epicentro.c
	gcc epicentro.c -lm -o epicentro.x
clean :
	rm -f epicentro.x datos.dat distribucion.pdf
