#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    //ler 100 numeros afim de arranjar um vetor com 10 numeros primos distintos

    /*
    int primos[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, j, n, encheu, cont, ehprimo, ehrepet, posicao;
    i=0;
    encheu=0;
    posicao=0;

    do{

        scanf("%d", &n);
        fflush(stdin);

        ehprimo=1;
        if(n%2==0 && n!=2)
            ehprimo=0;
        for(j=3; j<n; j+=2){
            if(n%j==0)
                ehprimo=1;
        }

        ehrepet=0;
        for(j=0; j<10; j++){
            if(primos[j]==n)
                ehrepet=1;
        }

        if(ehprimo && !ehrepet){
            primos[posicao]=n;
            posicao++;
        }

        cont=0;
        for(j=0; j<10; j++){
            if(primos[j])
                cont++;
        }
        if(cont==10)
            encheu=1;

    }while (i<100 && !encheu);

    printf("os numeros primos digitados sao:\n");
    for(j=0; j<10; j++)
        printf("%3d, ", primos[j]);

    */

    //matriz de dimensoes maleaveis, trocar diagonal principal com secundaria, imprimir tudo em um unico vetor INCOMPLETO
    /*

    int i, j, k, d, mat[10][10], matd[10][10], vtot[100];

    printf("informe a dimensao da matriz (de 2 a 10)\n");
    scanf("%d", &d);
    if(d<2)
        d=2;
    if(d>10)
        d=10;

    printf("matriz gerada: \n");
    for(i=0; i<d; i++){
        printf("\n");
        for(j=0; j<d; j++){
            mat[i][j]= rand()%50;
            printf("%3d, ", mat[i][j]);
        }
    }



    printf("\n\n\n");
    printf("troca diagonal: \n");

    for(i=0; i<d; i++){
        printf("\n");
        for(j=0; j<d; j++){

            matd[i][j]=mat[i][j];

            printf("%3d, ", matd[i][j]);
        }
    }


    printf("\n\n\n");
    printf("vetor da matriz:\n");

    k=0;
    for(i=0; i<d; i++){
        for(j=0; j<d; j++){
            vtot[k]= mat[i][j];
            k++;
            printf("%d, ", vtot[k]);
        }
    }
    */

    //problema da quitanda/armazem

    int i, j, plan[10][12];

    printf("\n J F M A M J J A S O N D\n");
    for(i=0; i<10; i++){
        printf("\n");
        for(j=0; j<12; j++){
            plan[i][j]= rand()%10;
            printf(" %d", plan[i][j]);
        }
    }

}
