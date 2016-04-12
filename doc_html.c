/*FUNCION PARA CHECAR LAS ETIQUETAS QUE NO NECESITAN CIERRE*/
#include "doc_html.h"
int checar_etiqueta(char palabra[], int x)
{
	FILE *et;
	int h=0;
	char ultimo;
	char html[12];
	et = fopen("html.txt","r");
	if(et==NULL)
	{
		printf("Error 1\nChecar Leeme.txt\n");
		return 0;
	}
	/*PARTE DONDE SE VERIFICA*/
	else
	{
		inicializar(html, 12);
		ultimo=fgetc(et);
	    while (ultimo != EOF)
	    {
	    	for (h=0;h<12;h++)
			{
				if(ultimo != '\n')
				{
					html[h] = ultimo;
					ultimo=fgetc(et);
				}
				else
				{
					h=12;
				}
			}
			if((strncmp(palabra,html,12))==0)
			{	
				return 0;
			}
			else
			{
			
			}
		ultimo= fgetc(et);		
		}
		fclose(et);
		return 1;
	}

}
