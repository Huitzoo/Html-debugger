/*Main para empezar el programa*/
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/*lista de tags que no necesitan pareja*/
char area[]		="area        ";
char base[]		="base        ";
char basefont[]	="basefont    ";
char br[]		="br          ";
char col[]		="col         ";
char embed[]	="embed       ";
char img[]		="img         ";
char frame[]	="frame       ";
char hr[]		="hr          ";
char input[]	="input       ";
char keygen[]	="keygen      ";
char lin[]		="link        ";
char meta[]		="meta        ";
char param[]	="param       ";
char source[]	="source      ";
char track[]	="track       ";
char wbr[]		="wbr         ";
char DOCTYPE[]	="!DOCTYPE    ";

int main(int argc, char **argv)
{
	int linea=1;
	int i=0;
	int j=0;
	int k=0;
	int cont=0;
	FILE *ar;
	char palabra[12];
	char palabra_pila[12];
	char cerrar[12];
	char caracter;
	char auxi;
	/*variables para guardar palabra*/
	char *tags = (char *)malloc(12*sizeof(char));
	char *dato_pila = (char *)malloc(12*sizeof(char));
	pila *l_tags = (pila *)malloc(1*sizeof(elemento));
	/*Variables para guardar < */
	char *signo = (char *)malloc(12*sizeof(char));
	char *signo_pila = (char *)malloc(12*sizeof(char));
	pila *l_signo = (pila *)malloc(1*sizeof(elemento));
	/*empieza el programa*/
	start(l_signo);
	start(l_tags);
	inicializar(cerrar,12);
	inicializar(palabra,12);
	ar = fopen("index.html","r");
	if(ar==NULL)
	{
		printf("Error 1\nChecar Errores.txt");
		return 0;
	}
	//parte donde se hacen las cosas
	else
	{
		caracter = fgetc(ar); //obtiene el primer caracter
	    while (caracter != EOF)
	    {
	    	if(caracter=='<') //encuentra apertura de etiqueta
			{
				*signo=caracter;
				push(l_signo, signo);
				//iniciamos un contador y obtenemos el siguiente valor de nuestra etiqueta
				caracter=fgetc(ar);
				if(caracter=='/') //checa si se trata de una etiqueta de cierre o inicio, en este caso si es de cierre hace lo siguiente
				{
					linea++;
					k=0;
					caracter=fgetc(ar);//obtiene el siguiente caracter de nuestra etiqueta
					//como son de cierre solo se tiene que verificar que se haya cerrado la etiqueta antes de continuar.
						for(i=0,j=0;i<12;i++)
						{
								if(caracter!='>')
								{
									if(caracter!='\n'&caracter!='<')
									{
										cerrar[i]=caracter;
										k++;
									}
									else 
									{
										printf("\tError 3, para mas información consulta Errores.txt. \n\tError linea: %d ,%d o %d\n", linea-1, linea, linea+1);
										printf("\tSe esperaba un: >\n");
										signo_pila=top(l_signo);
										printf("\tLa etiqueta en cuestion fue: ");
										for (i=0;i<12;i++)
										{
											printf("%c",cerrar[i]);
										}
										printf("\n");
										printf("\tUtilmo dato en pila de signos: %c\n", *signo_pila);
										exit(0);
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
							caracter=fgetc(ar);
						}//Aqui termina el for
					if(k>=12)// si el for temina e i es igual a 11 entonces...
					{
						printf("Error 2, para mas información consulta Errores.txt; Error linea: %d ,%d o %d\n", linea-1, linea, linea+1);
						exit(0);
					}
					else //Aqui se compara el ultimo dato de la pila con cerrada
					{
						dato_pila=top(l_tags);
						if((strcmp(dato_pila,cerrar))==0)
						{
							pop(l_tags);
						}						
						else
						{
							printf("Error 4, para mas información consulta Errores.txt; Error linea: %d ,%d o %d\n", linea-1, linea, linea+1);
							printf("Ultima etiqueta de apertura: ");
							for(i=0;i<12;i++)
							{
								printf("%c",dato_pila[i]);
							}
							printf("\n");
							printf("Etiqueta encontrada de cierre: ");
							for(i=0;i<12;i++)
							{
								printf("%c",cerrar[i]);
							}
							printf("\n");
							exit(0);
						}
					}
				}

				else
				{
					k=0;
				/*si no es una etiqueta de cierre es de abrir
				Lo primero que se hace es obtener la palabra que esta dentro de la etiqueta bebé y que este cerrada la etiqueta*/
					for(i=0,j=0;i<12;i++)//entra para guardar la palabra
					{
						//obtiene la letra que sigue de mi etiqueta y empezamos a comparar.
						if(caracter!='>')//si es diferente al cierre de una etiqueta
						{
							if(caracter==' ')//si caracter es igual a un espacio
							{
								auxi=caracter;
								for(j=i;j<12;j++)
								{
									palabra[j]=' ';
								}
								i=12;
							}
							else if(caracter=='\n')
							{
									printf("\tError 3, para mas información consulta Errores.txt. \n\tError linea: %d ,%d o %d\n", linea-1, linea, linea+1);
									printf("\tSe esperaba un: >\n");
									signo_pila=top(l_signo);
									printf("\tLa etiqueta en cuestion fue: ");
									for (i=0;i<12;i++)
									{
										printf("%c",palabra[i]);
									}
									printf("\n");
									printf("\tUtilmo dato en pila de signos: %c\n", *signo_pila);
									exit(0);
									exit(0);
							}
							else
							{
								palabra[i]=caracter;
								k++;
							}
						}	
						else
						{
							auxi=caracter;
							for(j=i;j<12;j++)
							{
								palabra[j]=' ';
							}
							i=12;
						}
						caracter=fgetc(ar);
					}	
					if(k>=12)// si el for temina e i es igual a 11 entonces...
					{
						printf("Error 2, para mas información consulta Errores.txt; Error linea: %d ,%d o %d\n", linea-1, linea, linea+1);
						exit(0);
					}
	    			else
	    			{
	    				if(auxi==' ')
	    				{	
	    					do
	    					{
	    						caracter=fgetc(ar);
	    						if(caracter=='<'|caracter=='\n')
	    						{
									printf("\tError 3, para mas información consulta Errores.txt. \n\tError linea: %d ,%d o %d\n", linea-1, linea, linea+1);
									printf("\tSe esperaba un: >\n");
									signo_pila=top(l_signo);
									printf("\tLa etiqueta en cuestion fue: ");
									for (i=0;i<12;i++)
									{
										printf("%c",palabra[i]);
									}
									printf("\n");
									printf("\tUtilmo dato en pila de signos: %c\n", *signo_pila);
									exit(0);
									exit(0);
	    						}

	    					}while(caracter!='>');
	    					pop(l_signo);
	    				}
	    				else
	    				{
	    					pop(l_signo);
	    				}
	    					/*Mandar a la pila  lo que se guarde en palabra
		    				SOlo mandar a la pila aquellas etiquetas que necesitan pareja para cerrarse*/
			    		if((strcmp(palabra,area))==0)
		    			{}
		    			else if((strcmp(palabra,base))==0)
		    			{}
		    			else if((strcmp(palabra,basefont))==0)
		    			{} 
		    			else if((strcmp(palabra,br))==0)
		    			{}
		    			else if((strcmp(palabra,col))==0)
		    			{}
		    			else if((strcmp(palabra,embed))==0)
		    			{}
		    			else if((strcmp(palabra,img))==0)
		    			{}
	    				else if((strcmp(palabra,frame))==0)
	    				{}
	    				else if((strcmp(palabra,hr))==0)
	    				{}
	    				else if((strcmp(palabra,input))==0)
	    				{}
	    				else if((strcmp(palabra,keygen))==0)
	    				{}
	    				else if((strcmp(palabra,lin))==0)
	    				{}
	    				else if((strcmp(palabra,meta))==0)
	    				{}
	    				else if((strcmp(palabra,param))==0)
	    				{}
	    				else if((strcmp(palabra,source))==0)
	    				{}
	    				else if((strcmp(palabra,track))==0)
	    				{}
	    				else if((strcmp(palabra,wbr))==0)
	    				{}
	    				else if((strcmp(palabra,DOCTYPE))==0)
	    				{}
		    			else
		    			{
		    				strcpy(tags,palabra);
		    				push(l_tags,tags);
		    			}
	    			}	//Aqui termina el else de / 
	    		}
	    	}//Aqui termina if de <
	  		else if(caracter=='\n')
	  		{
	  			linea++;
	  		}
	  		caracter = fgetc(ar);	
	  	}
	}
	fclose(ar);
	printf("OK\n");
	return 0;
}







