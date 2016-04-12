run: a.out
		./a.out
pila.o: pila.c
	gcc -c pila.c -Wall

doc_html.o: doc_html.c
	gcc -c doc_html.c -Wall

validar_etiquetas.o: validar_etiquetas.c
	gcc -c validar_etiquetas.c -Wall

main.o: main.c
	gcc -c main.c -Wall

a.out: main.o pila.o validar_etiquetas.o doc_html.o
	gcc main.o pila.o validar_etiquetas.o doc_html.o

clean:
	rm a.out main.o pila.o validar_etiquetas.o doc_html.o

 
