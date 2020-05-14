#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eh_numero(char x)
{
	if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' ||
		x == '5' || x == '6' || x == '7' || x == '8' || x == '9')
		return 1;
	else
		return 0;
}

int main(int argc, char** argv)
{
   char *data;
   char conteudo[200];
   char *seq, *inicio;
   int valor;


   printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
   printf("<TITLE>PROCESSANDO TESTE 1</TITLE>\n");
   data = getenv("QUERY_STRING");

   printf("data = %s\n",data);

   seq = strstr(data,"Var1=");

   if(data == NULL)
          printf("<P>Erro! Erro na passagem dos dados \n");
   else
   {

      if (seq != NULL)
      {
         strcpy(conteudo,seq+5);

		 printf("<P> conteudo : %s\n",conteudo);

		 seq = conteudo;
         inicio = seq;

		 while(eh_numero(*seq))
			 seq++;
	     *seq = '\0';

		 printf(" <P> seq : %s\n",inicio);
         valor = atoi(inicio);

      }
      else
        printf("<P>Erro! Parametro nao encontrado \n");
    }

    printf("<body> meu valor = %d </body>\n",valor);


return 0;
}

