#include <stdio.h>
#include <stdlib.h>

#define T 10
#define PREC 50
#define PI 3.1415


float seno(int ang)//fucc up
{
    int num, den, rad, i, j;
    float seno, x, aux;


    //x=ang*//alguma coisa ai
    aux=x;

    num=-1;
    den=1;

    seno=0;

    for(i=0;i<PREC;i++){

        for(j=1; j<=i; j++)
            num = -num;
        for(j=1; j<=(2*i+1); j++)
            den = den*j;
        for(j=1; j<=(2*i+1); j++)
            x = x*aux;

        seno = seno + (num/den*x);

    }

    return(seno);
}

int soma(int a,int b)
{
    int c;
    c = a+b;
    return c;
}

int maior(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int elmaior(int v[T])
{
    int el=v[0]
    for(i=0;i<(T-1);i++)
        if(v[i]>v[i+1])
            //faz um bubble sort ai fodasse
}

int elpert(int el, int v[T])
{
    int pert=0;
    int i;
    for(i=0;i<T;i++)
        if(el==v[i])
            pert=1;
    return pert;
}

int main()
{
    //funcao soma
    /*
    int A, B;

    printf("primeiro termo: ");
    scanf("%d", &A);

    printf("\nsegundo termo: ");
    scanf("%d", &B);

    printf("\na soma eh: %d", soma(a, b);
    */

    //funcao maior de 4 numeros
    /*
    int a, b, c, d;

     printf("primeiro numero: ");
    scanf("%d", &a);

     printf("segundo numero: ");
    scanf("%d", &b);

     printf("terceiro numero: ");
    scanf("%d", &c);

     printf("quarto numero: ");
    scanf("%d", &d);

    printf("%d eh o maior", maior(maior(a, b), maior(c, d)));
    */

    //suncao seno, raiz quadrada lol foda se

    //funcao maior elemento de um vetor, elemento pertence ao vetor


    printf("\n\n");
}


