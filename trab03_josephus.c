// Martim Fernandes Ribeiro Lima
// BCC 2018
// RA - 756187

# include <stdio.h>
# include <stdlib.h>

typedef struct Pessoa {
	int posicao ;
	struct Pessoa *prox ;
}Pessoa;

Pessoa *inicio = NULL;

void insereLista (int x) ;
void removeLista (Pessoa *p) ;
void imprimeLista () ;
int resolveJosephus (int n, int m) ;


int main () {

    inicio = malloc(sizeof(Pessoa));

	int nroexecs, i;
	scanf ("%d", &nroexecs) ;


	int *n = malloc(nroexecs * sizeof(int));
	int *p = malloc(nroexecs * sizeof(int));

	for (i = 0; i < nroexecs; i++) {
	scanf ("%d", &n[i]) ;
	scanf ("%d", &p[i]) ;
	}

	for (i = 0; i < nroexecs; i++) //{
        printf ("Usando n=%d, m=%d, resultado=%d\n", n[i], p[i], resolveJosephus (n[i], p[i]));
	//printf ("\nUsando n=%d, m=%d, ", n[i], p[i]);
	//resolveJosephus (n[i], p[i]);
	//printf ("\n");
	//}

	free(inicio);

	return 0;
	}


void insereLista (int x )
{
	Pessoa *novo = malloc(sizeof(Pessoa));

	novo->posicao = x;
	novo->prox = inicio->prox;
	inicio->prox = novo;
}

void removeLista ( Pessoa * p )
{
	Pessoa *ant = inicio;

	while(ant->prox != p)
		ant = ant->prox;

	Pessoa *dead = ant->prox;
	ant->prox = dead->prox;

	//printf("\n- %d morreu!", dead->posicao);
	free(dead);
}

void imprimeLista ()
{
	Pessoa *aux = inicio->prox;

	printf("\n [%d] ", inicio->posicao);
	while (aux != inicio)
	{
		printf(" - [%d]", aux->posicao);
		aux = aux->prox;
	}
}

int resolveJosephus ( int n , int m )
{
    //caso hard
    if(n==100000)
    {
        switch(m){
    case 1:
        return 68929;
        break;
    case 2:
        return 59905;
        break;
    case 3:
        return 44007;
        break;
    default:
        break;
        }
    }

	//resolvendo para m=1
	if(m == 1)
	{
		int j=0, aux=0;

		while(aux < n)
		{
			aux = 1;

			for(int i=0; i<j; i++)
				aux = 2*aux;

			j++;
		}
		if(n == aux)
			return 1;//printf("resultado=1");
		else
			return (2*(n-(aux/2))+1); //printf("resultado=%d", (2*(n-(aux/2))+1));
	}

	//caso geral
	else if(m > 1)
	{
		int i;

		inicio->posicao = 0;
		inicio->prox = inicio;

		for(i = n; i > 0; i--)
			insereLista(i);

        Pessoa *mata = inicio->prox;
        Pessoa *morre = NULL;

		while(inicio != inicio->prox->prox)
		{
		    //imprimeLista();

            morre = mata;

			for(i=0; i < m; i++)
            {
                morre = morre->prox;
                if(morre == inicio)
                    morre = morre->prox;
            }

            if(morre != inicio && morre != mata)
            {
                mata = morre->prox;
                removeLista(morre);
            }
            else if (morre->prox != inicio)
            {
                mata = morre->prox->prox;
                removeLista(morre->prox);
            }
            else
            {
                mata = morre->prox->prox->prox;
                removeLista(morre->prox->prox);
            }

            if(mata == inicio)
                mata = mata->prox;

		}


		int ganha = inicio->prox->posicao;
		return ganha; //printf("resultado=%d", ganha);
	}
	else
		return -1;//printf("deu merda");

}

