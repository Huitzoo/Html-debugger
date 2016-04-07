/*Libreria para las etiquetas html*/

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
int p=-1;
int checar_etiqueta(char palabra[], int x)
{
	if((strcmp(palabra,area))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,base))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,basefont))==0)
	{
		p=0;
	} 
	else if((strcmp(palabra,br))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,col))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,embed))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,img))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,frame))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,hr))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,input))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,keygen))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,lin))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,meta))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,param))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,source))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,track))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,wbr))==0)
	{
		p=0;
	}
	else if((strcmp(palabra,DOCTYPE))==0)
	{
		p=0;
	}
	else
	{
		p=1;
	}
	return p;
}