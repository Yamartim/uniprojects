#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define OU ||
#define E &&


//typedef struct

/*
typedef struct Dados_Academicos
{
char nome [50];
int RA;
float notas[3];
float media;
} TDA;

void leia(TDA *alunos, int x)
{
int i;
float soma = 0;
printf("Entre com os dados do aluno %d",x);
printf(" RA: ");
scanf("%d",&alunos->RA);
printf(" Nome: ");
scanf("%s",alunos->nome);
printf(" Nota 1: ");
scanf("%f",&alunos->notas[0]);
printf(" Nota 2: ");
scanf("%f",&alunos->notas[1]);
printf(" Nota 3: ");
scanf("%f",&alunos->notas[2]);

printf("\n");
printf("RA => %d\n",alunos->RA);
printf("Nome => %s\n",alunos->nome);
for (i=0;i<3;i++)
{
soma += alunos->notas[i];
printf(" Nota [%d] => %f\n",i,alunos->notas[i]);
}
alunos->media = soma/3.0;
printf("Media => %f\n",alunos->media);

}

void imprima(TDA alunos[5])
{
int i;

printf("\n");

for (i=0;i<5;i++)
printf("%5d %20s %5.2f %5.2f %5.2f => %5.2f\n ",alunos[i].RA, alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].media);
}

void troca(TDA *a1, TDA *a2)
{
TDA aux;

aux = *a1;
*a1 = *a2;
*a2 = aux;
}

void ordena(TDA *alunos, int campo)
{
int i, j;
if (campo == 0)
{
for (i=0;i<5;i++)
for (j=0;j<4;j++)
if (alunos[j].RA > alunos[j+1].RA)
troca (&alunos[j], &alunos[j+1]);
}
if (campo == 1)
{
for (i=0;i<5;i++)
for (j=0;j<4;j++)
if (strcmp(alunos[j].nome, alunos[j+1].nome)> 0)
troca (&alunos[j], &alunos[j+1]);

}
}


int main()
{
int i;
TDA alunos[5];

for (i=0;i<5;i++)
leia(&alunos[i], i);

imprima (alunos);

ordena(alunos, 0);

imprima (alunos);

ordena(alunos, 1);

imprima (alunos);

return 0;
}
*/


//tyoedef struct com matrizes


typedef struct M
{
int L, C;
int dados[10][10];
} MAT;

int gera_matriz(int L, int C, MAT *X)
{
int i, j;
if (L > 9 OU C > 9 OU L < 1 OU C < 1)
{
return 0;
}
else
{
X->L = L;
X->C = C;
for (i=0;i<L;i++)
for (j=0;j<C;j++)
X->dados[i][j] = rand()%20;
return 1;
}
}

MAT cria_matriz(int L, int C)
{
MAT D;
int i, j;

if (L > 0 E C > 0 E L < 9 E C < 9)
{
D.L = L;
D.C = C;
for (i=0;i<L;i++)
for (j=0;j<C;j++)
D.dados[i][j] = rand()%10;
}
else
{
D.L = 0;
D.C = 0;
}
return D;
}


void imprima_matriz(MAT W)
{
int i, j;

for (i=0;i<W.L; i++)
{
for (j=0;j<W.C; j++)
printf("%3d ",W.dados[i][j]);
printf("\n");
}

}

// solução A
int multiplica_matriz(MAT A, MAT B, MAT *C)
{
int i, j, k;

if (B.L != A.C)
return 0;
else
{
C->L = B.L;
C->C = A.C;

for (i=0;i<A.L;i++)
for (j=0;j<B.C;j++)
{
C->dados[i][j] = 0;
for (k=0;k<B.L;k++)
C->dados[i][j] += A.dados[i][k]*B.dados[k][j];
}
return 1;
}

}

// solução B
MAT matxf(MAT A, MAT B)
{
int i, j, k;

MAT R;

if (A.C == B.L)
{
R.L = B.L;
R.C = A.C;

for (i=0;i<A.L;i++)
for (j=0;j<B.C;j++)
{
R.dados[i][j] = 0;
for (k=0;k<B.L;k++)
R.dados[i][j] += A.dados[i][k]*B.dados[k][j];
}
}
else
{
R.L = 0;
R.C = 0;
}
return R;

}

int main()
{
MAT A, B, C;

if (gera_matriz(12,10,&A))
printf(" gerou\n");
else
printf(" nao gerou\n");

A = cria_matriz(3,3);
B = cria_matriz(3,3);

C = matxf(A,B);

imprima_matriz(A); printf("\n");
imprima_matriz(B); printf("\n");
imprima_matriz(C); printf("\n");

return 0;
}
