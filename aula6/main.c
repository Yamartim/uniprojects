#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 5
#define COL 5

int main()
{
    srand(time(NULL));

    int i, j;

    int mat[LIN][COL], mat1[LIN][COL], mat2[LIN][COL], mat3[LIN][COL];

    int T[LIN][COL];
    int M[LIN][COL];
    int I[LIN][COL]=
    {
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1}
    };
    int iden=1;


    //imprimir matriz aleatoria
    /*



    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++)
            mat[i][j] = rand() %10;

    for(i=0; i<LIN; i++){
        printf("\n");
        for(j=0; j<COL; j++)
            printf(" %3d", mat[i][j]);
    }
*/


    //conta zeros
/*
    int zeros = 0;

    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++)
            if(!mat[i][j])
                zeros++;

    printf("\n\n %d zeros", zeros);
*/

    //conta numeros de 0 a 9
/*
    int nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++)
            nums[mat[i][j]]++;

    printf("\n %d zeros", nums[0]);
    printf("\n %d uns", nums[1]);
    printf("\n %d doiss", nums[2]);
    printf("\n %d tress", nums[3]);
    printf("\n %d quatros", nums[4]);
    printf("\n %d cincos", nums[5]);
    printf("\n %d seiss", nums[6]);
    printf("\n %d setes", nums[7]);
    printf("\n %d oitos", nums[8]);
    printf("\n %d noves", nums[9]);
*/

    //trocar colunas da matriz
/*
    int pega[COL], qp, troca[COL], qt;

    printf("\n\npegar a coluna: ");
    scanf("%d", &qp);
    printf("trocar pela coluna: ");
    scanf("%d", &qt);

    for(i=0; i<COL; i++){
        pega[i]= mat[i][qp];
        troca[i]= mat[i][qt];
    }

    for(i=0; i<COL; i++){
        mat[i][qp]= troca[i];
        mat[i][qt]= pega[i];
    }


    printf("\n\nnova matriz:\n");
    for(i=0; i<LIN; i++){
        printf("\n");
        for(j=0; j<COL; j++)
            printf(" %3d", mat[i][j]);
    }
*/

    //soma de matrizes


/*
    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++)
        {
            mat1[i][j] = rand() %10;
            mat2[i][j] = rand() %10;
            mat3[i][j] = mat1[i][j]+mat2[i][j];
        }


    for(i=0; i<LIN; i++){
        printf("\n");
        for(j=0; j<COL; j++)
            printf(" %3d", mat1[i][j]);
    }

    printf("\n\n+\n");

    for(i=0; i<10; i++){
        printf("\n");
        for(j=0; j<10; j++)
            printf(" %3d", mat2[i][j]);
    }

    printf("\n\n=\n");

    for(i=0; i<10; i++){
        printf("\n");
        for(j=0; j<10; j++)
            printf(" %3d", mat3[i][j]);
    }
*/
    //matriz transposta
/*
    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++)
            mat1[i][j] = rand() %10;

    for(i=0; i<LIN; i++){
        printf("\n");
        for(j=0; j<COL; j++){
            printf(" %3d", mat1[i][j]);
            mat2[i][j] = mat1[j][i];
        }
    }

    printf("\n\ntransposta:\n");

    for(i=0; i<LIN; i++){
        printf("\n");
        for(j=0; j<COL; j++)
            printf(" %3d", mat2[i][j]);
    }
*/
    //testar matriz indentidade

    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++)
            M[i][j] = rand() %10;

    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++)
            T[i][j]=I[i][j];

    for(i=0; i<LIN; i++){
        printf("\n");
        for(j=0; j<COL; j++)
            printf(" %3d", T[i][j]);
    }

    if(LIN!=COL)
        iden=0;

    for(i=0; i<LIN; i++)
        for(j=0; j<COL; j++){
            if(i==j){
                if(T[i][j]!=1){
                    iden=0;
                }
            }else
                if(T[i][j]!=0){
                    iden=0;
                }
        }

    if(iden)
        printf("\n\neh identidade");
    else
        printf("\n\nnao eh identidade");

}
