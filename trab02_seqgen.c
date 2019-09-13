//Martim Fernandes Ribeiro Lima
//BCC
//RA: 756187

#include <stdio.h>
#include <stdlib.h>
#define MAX 300

int *ConvSeq(int n, char *str); // função que converte a string da entrada para um vetor de inteiros
int NumMuta(int n, int *seq); // função que determina o numero de mutacoes genômicas

int main() {
	
	int n;
	int *seq;
	char strseq[MAX];
	
	printf("forneca o tamanho da sequencia genetica: "); // entrada do tamanho da sequência
	scanf("%d", &n);
	fflush(stdin);
	
	printf("forneca a sequencia genetica: "); // entrada da sequência
	gets(strseq);
	fflush(stdin);
	
	seq = (int*) malloc(n * sizeof(int)); // alocação dinâmica do vetor da sequência
	seq = ConvSeq(n, strseq); // converção da string inserida pelo usuário

	printf("\n\n");
	printf("numero de mutacoes na sequencia: %d", NumMuta(n, seq)); //saída com o número de mutações
	
	free(seq); // liberação da memória alocada
	
	return 0;
}

int *ConvSeq(int n, char *str)
{

	int i, j, k, l;
	int *seq = (int*) malloc(n * sizeof(int));
	char auxstr[MAX]; // usando uma string auxiliar
	
	i=0;
	l=1;
	
	seq[0] = atoi(str); // ja preenchendo a primeira posição do vetor com a função atoi()

	while(str[i] != '\0') // percorre-se a string até o final
	{
		if(str[i] == ' ') // e a cada espaço se identifica um numero novo
		{
			j=i;
			for(k=0; k<MAX; k++) // preenche-se a string auxiliar a partir do espaço
			{
				auxstr[k] = str[j];
				j++;
			}
		
			seq[l] = atoi(auxstr); // de novo usando atoi() na string auxiliar para pegar o próximo número na sequencia
			l++;
			if(l == n) // caso o usuario tenha entrado com números em excesso, o loop se quebra quando o tamanho especificado é preenchido
				break;
		}
		i++;
	}
	return seq; // retorna o ponteiro para a sequência cnvertida
}

int NumMuta(int n, int *seq)
{
	int i, aux, arranj, mutcount=0;
	
	do{ 
		for(i=1; i<n; i++)
		{
			if(seq[i-1]>seq[i])
			{
				aux = seq[i-1];
				seq[i-1] = seq[i];
				seq[i] = aux;
				mutcount++;
			}
		}
		
		arranj=1;
		for(i=1; i<n; i++)
			if(seq[i-1]>seq[i])
				arranj = 0;
		
	}while(!arranj); // aplicação de bubble sort no vetor, com contagem do número de trocas

	return mutcount; // retorno do número de mutações realizadas pelo genoma
}

