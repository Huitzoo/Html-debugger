//libreria de nuestra pila
#include <string.h>
int i=0;
typedef struct elemento
{
	char *dato;
	struct elemento *siguiente;	
}elemento;

typedef struct pila
{
	int longitud;
	struct elemento *inicio;
}pila;

void start(pila * aux)
{
	aux->inicio = NULL;
	aux->longitud = 0;
}
void inicializar(char arreglo[], int x)
{
	for (i=0;i<x;i++)
	{
		arreglo[i]=' ';
	}
}
int push(pila *aux, char *dato)
{
	elemento *nuevo_elemento;
	if((nuevo_elemento = (elemento *) malloc (sizeof (elemento))) == NULL)
		return 1;
	
	if((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char))) == NULL)
		return 1;

	/*printf("Yo soy de pila ");
	for (i = 0; i < 12; i++)
	{
		printf("%c", dato[i]);
	}*/
	strcpy(nuevo_elemento->dato, dato);
	(nuevo_elemento->siguiente) = (aux ->inicio);
	(aux->inicio) = nuevo_elemento;
	aux->longitud++;
}

int pop(pila *aux)
{
	
	elemento *sup_elemento;
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

char* top(pila * aux)
{
	elemento *actual;
	char *palabra_pila = (char *)malloc(12*sizeof(char));
	actual = aux->inicio;
	strcpy(palabra_pila,actual->dato);
	return palabra_pila;
}








