/*Main para empezar el programa*/
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "html.h"
#include "validar_etiquetas.h"
/*lista de etiquetas que no necesitan pareja*/
int main(int argc, char **argv)
{
	char *signo = (char *)malloc(1*sizeof(char));
	struct pila *l_signo = (struct pila *)malloc(1*sizeof(struct pila));
	struct pila *l_etiquetas = (struct pila *)malloc(12*sizeof(struct pila));
	FILE *ar;
	char caracter;
	start(l_signo);
	start(l_etiquetas);
	printf("\t\tDepurador html.\n\n\t**Recuerda que tus etiquetas \n\tcomo recomendacion deben estar en minusculas**\n\n");
	ar = fopen("test2.html","r");
	if(ar==NULL)
	{
		printf("Error 1\nChecar Leeme.txt\n");
		return 0;
	}
	//parte donde se hacen las cosas
	else
	{
		caracter = fgetc(ar); //obtiene el primer caracter
	    while (caracter != EOF)
	    {
	    do
	    {
	    	if(caracter=='<') //encuentra apertura de etiqueta
			{
				*signo=caracter;
				push(l_signo, signo);
				caracter=fgetc(ar);
				caracter=validar_etiqueta(caracter, ar, signo, l_signo, l_etiquetas);
				if(caracter==0)
				{
					exit(0);
				}
				else
				{

				}

			}
	  	}while(caracter=='<');
	  		caracter = fgetc(ar);	
	  	}
	}
	fclose(ar);
	printf("SU archivo html esta correcto\n\n");
	return 0;
}






