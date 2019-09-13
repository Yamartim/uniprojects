//Martim Fernandes Ribeiro Lima
//BCC
//RA: 756187

#include <stdio.h>
#include <stdlib.h>
#define MAX 300

int *ConvSeq(int n, char *str); // fun��o que converte a string da entrada para um vetor de inteiros
int NumMuta(int n, int *seq); // fun��o que determina o numero de mutacoes gen�micas

int main() {
	
	int n;
	int *seq;
	char strseq[MAX];
	
	printf("forneca o tamanho da sequencia genetica: "); // entrada do tamanho da sequ�ncia
	scanf("%d", &n);
	fflush(stdin);
	
	printf("forneca a sequencia genetica: "); // entrada da sequ�ncia
	gets(strseq);
	fflush(stdin);
	
	seq = (int*) malloc(n * sizeof(int)); // aloca��o din�mica do vetor da sequ�ncia
	seq = ConvSeq(n, strseq); // conver��o da string inserida pelo usu�rio

	printf("\n\n");
	printf("numero de mutacoes na sequencia: %d", NumMuta(n, seq)); //sa�da com o n�mero de muta��es
	
	free(seq); // libera��o da mem�ria alocada
	
	return 0;
}

int *ConvSeq(int n, char *str)
{

	int i, j, k, l;
	int *seq = (int*) malloc(n * sizeof(int));
	char auxstr[MAX]; // usando uma string auxiliar
	
	i=0;
	l=1;
	
	seq[0] = atoi(str); // ja preenchendo a primeira posi��o do vetor com a fun��o atoi()

	while(str[i] != '\0') // percorre-se a string at� o final
	{
		if(str[i] == ' ') // e a cada espa�o se identifica um numero novo
		{
			j=i;
			for(k=0; k<MAX; k++) // preenche-se a string auxiliar a partir do espa�o
			{
				auxstr[k] = str[j];
				j++;
			}
		
			seq[l] = atoi(auxstr); // de novo usando atoi() na string auxiliar para pegar o pr�ximo n�mero na sequencia
			l++;
			if(l == n) // caso o usuario tenha entrado com n�meros em excesso, o loop se quebra quando o tamanho especificado � preenchido
				break;
		}
		i++;
	}
	return seq; // retorna o ponteiro para a sequ�ncia cnvertida
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
		
	}while(!arranj); // aplica��o de bubble sort no vetor, com contagem do n�mero de trocas

	return mutcount; // retorno do n�mero de muta��es realizadas pelo genoma
}

