#include "pila.h"
int cont=0;
void start(struct pila * aux)
{
	aux->inicio = NULL;
	aux->longitud = 0;
}
void inicializar(char arreglo[], int x)
{
	for (cont=0;cont<x;cont++)
	{
		arreglo[cont]=' ';
	}
}
int push(struct pila *aux, char *dato)
{
	struct elemento *nuevo_elemento;
	if((nuevo_elemento = (struct elemento *) malloc (sizeof (struct elemento))) == NULL)
	{
		return 1;
	}
	if((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char))) == NULL)
	{
		return 1;
	}
	strcpy(nuevo_elemento->dato, dato);
	(nuevo_elemento->siguiente) = (aux ->inicio);
	(aux->inicio) = nuevo_elemento;
	aux->longitud++;
	return 0;
}
int pop(struct pila *aux)
{
	struct elemento *sup_elemento;
	if((sup_elemento = (struct elemento *) malloc (sizeof (struct elemento))) == NULL)
	{	
		return 1;
	}
	if(aux->longitud==0)
	{
		return 1;
	}
	else
	{
		(sup_elemento) = (aux->inicio);
		(aux->inicio) = (aux->inicio->siguiente);
		free(sup_elemento->dato);
		free(sup_elemento);
		aux->longitud--;
	}
	return 0;
}

char* top(struct pila *aux)
{
	struct elemento *actual = (struct elemento *)malloc(sizeof (struct elemento));
	char *palabra_pila = (char *)malloc(12*sizeof(char));
	actual = aux->inicio;
	strcpy(palabra_pila,actual->dato);
	return palabra_pila;
}








