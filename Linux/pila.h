//libreria de nuestra pila
#ifndef pilah
#define pilah
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct elemento
{
	char *dato;
	struct elemento *siguiente;
};
struct pila
{
	int longitud;
	struct elemento *inicio;
};
void start(struct pila * aux);
void inicializar(char arreglo[], int x);
int push(struct pila *, char *);
int pop(struct pila *);
char* top(struct pila *);
#endif






