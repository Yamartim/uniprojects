#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20


int main()
{
    //abaixo da media
/*
    int n[10];
    int soma=0;
    int men=0;
    int i;
    float media;

    for(i=0; i<10; i++){
        scanf("%d", &n[i]);
        fflush(stdin);
        soma+=n[i];
    }

    media=soma/10.0;

    for(i=0; i<10; i++){
        if(n[i]<media)
            men++;
    }

    printf("%d elementos sao menores que a media", men);
*/

/*
    //mais distante da media

    int i, soma, maior, n[10];
    float media, desvn[10];

    soma=0;
    for(i=0; i<10; i++){
        scanf("%d", &n[i]);
        fflush(stdin);
        soma+=n[i];
    }

    media=soma/10.0;

    for(i=0; i<10; i++){
        desvn[i]=media-n[i];
        if(desvn[i]<0)
            desvn[i]= -desvn[i];
    }

    maior=0;
    for(i=0; i<10; i++){
        if(desvn[i]>maior)
            maior=n[i];
    }
    printf("%d eh o numero mais distante da media", n[1]);
*/

    //elemento repetido no vetor

    int v[N], vx[N], i, j, rep, aux;

    srand(time(NULL));

    for(i=0; i<N; i++){
        //scanf("%d", &v[i]);
        //fflush(stdin);
        v[i] = rand()%(3*N);
        printf("%3d, ", v[i]);
    }

    //Bubble sort!
    for(i=0; i<N-1; i++){
        for(j=0; j<N-1; j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }

    rep=0;
    for(i=0; i<N-1; i++){
        for(j=i+1; j<N; j++){
            if(v[i]==v[j])
                rep=1;
        }
    }

    if(rep)
        printf("ha repeticao");
    else
        printf("nao ha repeticao");
}
