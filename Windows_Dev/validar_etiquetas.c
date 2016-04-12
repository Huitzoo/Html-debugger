/*FUNCION PARA VALIDAR LA PALABRA Y EL CIERRE DE CADA ETIQUETA*/
#include "validar_etiquetas.h"
#include "doc_html.h"
char validar_etiqueta(char x, FILE *ar, char *signo, struct pila *l_signo, struct pila *l_etiquetas)
{
	char palabra[12];
	char cerrar[12];
	char auxi;
	/*variables para guardar palabra*/
	char *etiquetas = (char *)malloc(12*sizeof(char));
	char *dato_pila = (char *)malloc(12*sizeof(char));
	char *signo_pila = (char *)malloc(1*sizeof(char));
	/*Variables para guardar < */
	int i=0;
	int j=0;
	int p=0;
	int k=0;
	inicializar(cerrar,12);
	inicializar(palabra,12);
	if(x=='/') //checa si se trata de una etiqueta de cierre o inicio, en este caso si es de cierre hace lo siguiente
	{
		k=0;
		x=fgetc(ar);//obtiene el siguiente x de nuestra etiqueta
		if(x=='>')
		{
			printf("Error 3 consulte Leeme.txt\n");//desbordamiento de etiqueta
    		printf("No balanceado\n");
    		return 0;
		}
		else
		{
		//como son de cierre solo se tiene que verificar que se haya cerrado la etiqueta antes de continuar.
			j=0;
			for(i=0;i<12;i++)
			{
					if(x!='>')
					{
						if((x=='\n') | (x=='<'))
						{
							printf("Error 3 consulte Leeme.txt\n");//desbordamiento de 
    						printf("No balanceado\n");
							printf("\tSe esperaba un: >\n");
							signo_pila=top(l_signo);
							printf("\tLa etiqueta en cuestion fue: ");
							for (i=0;i<k;i++)
							{
								printf("%c",cerrar[i]);
							}
							printf("\n");
							printf("\tUtilmo dato en pila de signos: %c\n", *signo_pila);
							return 0;
						}
						else 
						{
    						cerrar[i]=x;
							k++;
						}
					}
					else
					{
						pop(l_signo);
						for(j=i;j<12;j++)
						{
							cerrar[j]=' ';
						}
						i=12;
					}
				x=fgetc(ar);
			}//Aqui termina el for
			if(k>=12)// si el for temina y k es igual a 11 entonces...
			{
	    		printf("Error 2 consulte Leeme.txt\n");//desbordamiento de etiqueta
	    		printf("Etiqueta de error: ");
				for(i=0;i<12;i++)
				{
					printf("%c",cerrar[i]);
				}
				printf("\n");
    			printf("No balanceado\n");
				return 0;
			}
			else //Aqui se compara el ultimo dato de la pila con cerrada
			{
				dato_pila=top(l_etiquetas);
				if((strncmp(dato_pila,cerrar, 12))==0)
				{
					pop(l_etiquetas);
				}						
				else
				{
	    			printf("Error 4 consulte Leeme.txt\n");//desbordamiento de etiqueta
	    			printf("No balanceado\n");
					printf("Ultima etiqueta de apertura: ");
					for(i=0;i<12;i++)
					{
						printf("%c",dato_pila[i]);
					}
					printf("\n");
					printf("Etiqueta encontrada de cierre: ");
					for(i=0;i<k;i++)
					{
						printf("%c",cerrar[i]);
					}
					printf("\n");
					return 0;
				}
			}
		}
	}
	else
	{
		k=0;
		if(x=='>')
		{
			printf("Error 3 consulte Leeme.txt\n");//desbordamiento de etiqueta
    		printf("No balanceado\n");
    		return 0;

		}
		else
		{
			/*si no es una etiqueta de cierre es de abrir
			Lo primero que se hace es obtener la palabra que esta dentro de la etiqueta bebé y que este cerrada la etiqueta*/
			j=0;
			for(i=0;i<12;i++)//entra para guardar la palabra
			{
				//obtiene la letra que sigue de mi etiqueta y empezamos a comparar.
				if(x!='>')//si es diferente al cierre de una etiqueta
				{
					if(x==' ')//si x es igual a un espacio
					{
						auxi=x;
						for(j=i;j<12;j++)
						{
							palabra[j]=' ';
						}
						i=12;
					}
					else if(x=='\n')
					{
	    					printf("Error 3 consulte Leeme.txt\n");//desbordamiento de etiqueta
	    					printf("No balanceado\n");
							printf("\tSe esperaba un: >\n");
							signo_pila=top(l_signo);
							printf("\tLa etiqueta en cuestion fue: ");
							for (i=0;i<k;i++)
							{
								printf("%c",palabra[i]);
							}
							printf("\n");
							printf("\tUltimomo dato en pila de signos: %c\n", *signo_pila);
							return 0;
					}
					else
					{
						palabra[i]=x;
						k++;
					}
				}	
				else
				{
					auxi=x;
					for(j=i;j<12;j++)
					{
						palabra[j]=' ';
					}
					i=12;
				}
				x=fgetc(ar);
			}	
			if(k>=12)// si el for temina e i es igual a 11 entonces...
			{
	    		printf("Error 2 consulte Leeme.txt\n");//desbordamiento de etiqueta
				printf("Etiqueta de error: ");
				for(i=0;i<12;i++)
				{
					printf("%c",palabra[i]);
				}
				printf("\n");
    			printf("No balanceado\n");
				return 0;
			}
			else
			{
				if(auxi==' ')
				{	
					do
					{
						x=fgetc(ar);
						if((x=='<') | (x=='\n'))
						{
	    					printf("Error 3 consulte Leeme.txt\n");//desbordamiento de etiqueta
	    					printf("No balanceado\n");
							printf("\tSe esperaba un: >\n");
							signo_pila=top(l_signo);
							printf("\tLa etiqueta en cuestion fue: ");
							for (i=0;i<k;i++)
							{
								printf("%c",palabra[i]);
							}
							printf("\n");
							printf("\tUtilmo dato en pila de signos: %c\n", *signo_pila);
							return 0;
						}

					}while(x!='>');
					pop(l_signo);
				}
				else
				{
					pop(l_signo);
				}
				/* VERIFICA QUE LA ETIQUETA QUE ESTA EN PALABRA SEA UNA ETIQUETA QUE NECESITA UN CIERRE*/
				p=checar_etiqueta(palabra, 12);
				if(p==0)
				{}
				else /*MANDA A LA PILA LO QUE SE GUARDÓ EN PALABRA*/
				{
					strcpy(etiquetas,palabra);
					push(l_etiquetas,etiquetas);
				}

			}
		}	/*TERMINA EL ELSE DE GUARDADO DE ETIQUETA*/ 
	}/*TERMINA IF DE <*/
	return x;

}
