#include <stdio.h>
#define DIM 3
// Curso C Progressivo: www.cprogessivo.net
// O melhor curso de C, Online e gratuito !
// Artigos, apostilas, tutoriais e vídeo-aulas sobre
// a linguagem de programação C !

void preencher(int matriz[][DIM])
{
    int linha,
        coluna;

    for(linha=0 ; linha < DIM ; linha++)
        for(coluna=0 ; coluna < DIM ; coluna++)
        {
            printf("Entre com o elemento matriz[%d][%d]: ", linha+1, coluna+1);
            scanf("%d", &matriz[linha][coluna]);
        }
}

void exibir(int matriz[][DIM])
{
    int linha,
        coluna;

    for(linha=0 ; linha < DIM ; linha++)
    {
        for(coluna=0 ; coluna < DIM ; coluna++)
            printf("%3d ", matriz[linha][coluna]);

        printf("\n");
    }

}

void gerar(int matriz [][DIM])
{

    srand(time(NULL));

    int linha,
        coluna;

    for(linha=0 ; linha < DIM ; lin   ha++)
        for(coluna=0 ; coluna < DIM ; coluna++)
        {
            matriz[linha][coluna] = rand()%5;
        }

}

int traco(int matriz[][DIM])
{
    int count,
        traco=0;

    for(count=0 ; count < DIM ; count++)
        traco += matriz[count][count];

    return traco;
}

int main(void)

{

    int matriz[DIM][DIM];

    gerar(matriz);
    exibir(matriz);

    printf("\nTraco da matriz: %d\n", traco(matriz));
    return 0;

}
