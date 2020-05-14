#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    srand(time(NULL));

    //ponteiroa!! oh boi
    /*
    //valor é a variável que
    //será apontada pelo ponteiro
    int valor = 27;

    //declaração de variável ponteiro
    int *ptr;

    //atribuindo o endereço da variável valor ao ponteiro
    ptr = &valor;

    printf("Utilizando ponteiros\n\n");
    printf ("Conteudo da variavel valor: %d\n", valor);
    printf ("Endereço da variavel valor: %p\n", &valor);
    printf ("Conteudo da variavel ponteiro ptr: %p\n", ptr);
    printf ("Endereco do ptr: %p", &ptr);
    */

    //troca devariaveis com ponteiro?
    /*
    int a, b;
    a=10;
    b=20;

    printf("A = %d \nB = %d\n\n", a, b);
    troca(&a, &b);
    printf("A = %d \nB = %d\n\n", a, b);
    */

    //media de dois vetores e desvio padrao, tranformar menores que a media em -1, dar maior e menor elementos com uma funcao so

    int v1[50], t1, v2[50], t2, i, desv;

    printf("tamanho do vetor 1 e 2:\n");
    scanf("%d", &t1);
    scanf("%d", &t2);

    printf("\n\n");
    for(i=0; i<t1; i++){
        v1[i] = rand() % 20;
        printf("%d, ", v1[i]);
    }

    printf("\n");
    for(i=0; i<t2; i++){
        v2[i] = rand() % 20;
        printf("%d, ", v2[i]);
    }



    /*
    int tot=0;
    int num=0;
    for(i=0; i<50; i++){

    }
    */

printf("\n\n");
}
