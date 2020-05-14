#include <stdio.h>
#include <stdlib.h>

typedef int TIPOPF (int x, float y);


int main()
{
    //ponteiro funcao (integral)

    //TIPOPF *pfunc;


    //malloc: alocacao dinamica de memoria

    int *v = (int*) malloc(5*sizeof(int));
//pra fazer uma matriz assim tem que usar ponteiro de ponteiro **v
    v[0]=4; v[1]=15; v[2]=5;
    int media = (v[0]+v[1]+v[2])/3;

    printf("%d", media);

    fread(v);

}
