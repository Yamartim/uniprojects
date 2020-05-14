#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

int main()
{
  /*  ////imprimir numeros primos de 1 a 1000
 int i, j, d, prim, total;
 total=2;
 printf("numeros primos entre 0 e 1000:\n");
 printf("2\n3\n");

    for(i=3; i<=1000; i+=2){
        prim = 1;
        for(j=3;j<i;j++){
            d=i%j;
            if(d==0){
                prim = 0;
            }
        }
        if(prim == 1){
            printf("%d\n", i);
            total++;
        }
    }

printf("\n\no numero de primos entre 0 e 1000 eh %d\n", total);
*/

/*
////contar numero de palavras em uma frase

char frase[100];
int tam, spc, i;

printf("manda a frase bb:\n");
gets(frase);
spc=1;
for(i=0; i<strlen(frase); i++){
    if(frase[i]==' ' && frase[i-1]!=' '){
        spc++;
    }
}
printf("num de palavras eh %d", spc);
*/

/*
////maior entre10 valores
int i, m, M;

scanf("%d", &M);
for(i=1; i<10; i++){
    scanf("%d", &m);
    if(m>M)
        M=m;
}
printf("o maior eh %d", M);
*/

//cosseno de uma angulo

/*
   float rad, cossen, conver;

   printf("manda o angulao\n");
   scanf("%f", &rad);
   conver = PI / 180.0;
   cossen = cos( rad*conver );//funcao cosseno le radianos por isso convercao
   printf("o cosseno de %f graus eh %f \n", rad, cossen);
*/

//serie de taylor pra calcular seno oh boy partiu

int i, prec;
float sen facto, expo, sinal;

printf("declare o grau de precisao\nquanto maior o numero mais precisao: ");
scanf("%d", &prec);
sinal=1

}
