#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_NIVEIS 8

#define PERGUNTA 0
#define FALA 1
#define FIM 2

#define RESP_POS 0
#define RESP_NEG 1
#define SEM_RESP -1


typedef struct dados_cena//struct que contem os dados necessarios para determinar como o cenario d o jogo eve aparecer
{
    int fundo;
    int reacao;
    int tipocena;

} CENA;


char *buscafrase(char linha[20], FILE *arq, int pos);// funcao que busca uma frase de um arquivo texto e armazena em uma string

void imprimeFundoExpre(CENA c, int pontuacao);//funcao que aplica ao cenario o plano de fundo devido e a expressao da personagem

void cenaFala(int est, int resp, char nome[10]);//funcao que imprime interface de dialogo
void cenaPerg(int est, char nome[10]);//funcao que imprime interface de pergunta com opcoes de resposta
void cenaFinal(int est, int pontuacao, char nome[10]);//funcao que imprime a vena final do jogo


int main()
{

    char nome[10];   //nome do coitado que esta jogando isso
    char n[2]; //variavel do nivel em string
    char *copia; //copia de parte da var dados

    char *dados;
    int env_estado;//recebidos no htmal getenv, estado++ avança o jogo
    int env_pontos;
    int env_resposta;


    dados = getenv("QUERY_STRING");

    if(dados == NULL){
          printf("<P>Erro! Erro na passagem dos dados \n");
          return 1;
	}

  			//Pegando o nome
    copia = strstr(dados,"nome=");
    strcpy(nome,copia+5);

		//Pegando o nivel
    copia = strstr(dados,"lvl=");
    strncpy(n, copia, 2);
    env_estado = atoi(n);

//FALTA PEGAR O ACUMULO DA PONRUACAO
//emv_pontos

		//Pegando o id da resposta
    copia = strstr(dados,"resp=");
    strncpy(n, copia, 2);
    env_resposta = atoi(n);




    CENA todos[NUM_NIVEIS];//vetor que contem dados de todos os cenarios do jogo em sequencia


    int conttodos[3][NUM_NIVEIS]=//matriz que contem os dados do jogo
    {
        {0, 0, 0, 2, 2, 1, 1, -1},
        {2, 3, env_resposta, 2, env_resposta, 4, env_resposta, -1},
        {FALA, PERGUNTA, FALA, PERGUNTA, FALA, PERGUNTA, FALA, FIM}
    };

    int i;
    for(i=0;i<NUM_NIVEIS;i++)//conversao dos dados da matriz para o vetor CENA
    {
        todos[i].fundo = conttodos[0][i];
        todos[i].reacao = conttodos[1][i];
        todos[i].tipocena = conttodos[2][i];
    }
    CENA atual=todos[env_estado];//atribuicao dos elementos necessarios no nivel atual para uma unica variavel

    switch(env_resposta)//contagem da pontuacao
    {
     case RESP_POS://jogador ganha um ponto ao responder corretamente
        env_pontos++;
     break;

     case RESP_NEG://e perde ao responder incorretamente
        env_pontos--;
     break;

     case SEM_RESP://quando nao ha uma pergunta para ser respondida nada acontece com a pontuacao
     break;
    }


    printf("Content-type:text/html\r\n\r\n");
    printf("<meta charset = 'UTF-8'/>");

            printf("<header>");
			printf("<meta charset = 'UTF-8'/>");
			printf("<link rel='stylesheet' type='text/css' href='../style.css'/>");
			printf("<title>");
			printf("</title>");

		//musiquinha ( >-<)
        printf("<audio style='display:none' controls autoplay><source src='../musica.mp3' type='audio/mpeg'> </audio>");


		printf("</header>");

		printf("<body style='background-image: url(../imagens/cenarios/fundo.png)'>");
			printf("<div id='container'>");


    imprimeFundoExpre(atual, env_pontos);//imprime as imagens correspondentes ao cenario atual



    switch(atual.tipocena)//imprime a a parte de dialogo da cena atual
    {
     case PERGUNTA:
        cenaPerg(env_estado, nome);
     break;

     case FALA:
        cenaFala(env_estado, env_resposta, nome);
     break;

     case FIM:
        cenaFinal(env_estado, env_pontos, nome);
        return 1;
     break;
    }

    printf("</body>");

    return 0;
}

char *buscafrase(char linha[20], FILE *arq, int pos)
{
    fseek(arq, 17*pos*sizeof(char), SEEK_SET);//pula se linhas baseado na posicao informada
    fgets(linha, 20, arq);//obtem a linha desejada
}


void imprimeFundoExpre(CENA c, int pontuacao)
{
    char *cenario = "esc.jpg";//colocar nomes das imagens nos cases depois
    char *expressao = "nico.png";

    if(c.tipocena==FIM)
    {
        if(pontuacao>NUM_NIVEIS/6)//final bom
        {
            c.fundo = -1;
            c.reacao = -1;
        }
        else if (pontuacao<-NUM_NIVEIS/6)//finalruim
        {
            c.fundo = -2;
            c.reacao = -2;
        }
        else//final neutro
        {
            c.fundo = -3;
            c.reacao = -3;
        }
    }

    switch(c.fundo)
    {
     case 0:
        printf("html fundo 0\n");
     break;

     case 1:
        printf("html fundo 1\n");
     break;

     case 2:
        printf("html fundo 2\n");
     break;


     //em caso do final do jogo
     case -1:
        printf("html fundo fimbom\n");
     break;

     case -2:
        printf("html fundo fimruim\n");
     break;

     case -3:
        printf("html fundo fimneutro\n");
     break;
    }

    switch(c.reacao)
    {
     case RESP_POS:
        printf("html expressao boa\n");
     break;

     case RESP_NEG:
        printf("html expressao ruim\n");
     break;


     case 2:
        printf("html expressao 2\n");
     break;

     case 3:
        printf("html expressao 3\n");
     break;

     case 4:
        printf("html expressao 4\n");
     break;

     //em caso do final do jogo
     case -1:
        printf("html expressao fimbom\n");
     break;

     case -2:
        printf("html expressao fimruim\n");
     break;

     case -3:
        printf("html expressao fimneutro\n");
     break;
    }

    //É neste printf que voce altera as imagens de cenario e da personagem~ tuturu ^3^
    printf("<div id='tela' style='background-image: url(../imagens/cenarios/%s);background-size: cover; background-repeat:no-repeat;'>", cenario);
        printf("<img class='char' src='../imagens/personagens/%s'/>", expressao);
        printf("<div id='texto'>");

}


//FALTA HTML AQUI
void cenaFala(int est, int resp, char nome[10])
{
    char frase[20];
    FILE *arq;

    if(est==0)//introducao
    {
        arq = fopen("ESPECIAL.txt", "r");
        if(arq == NULL)
            printf("Erro na abertura do arquivo est!");
    }
    else if(resp==RESP_POS)
    {
        arq = fopen("REACAO1.txt", "r");
        if(arq == NULL)
            printf("Erro na abertura do arquivo re1!");
    }
    else if(resp==RESP_NEG)
    {
        arq = fopen("REACAO2.txt", "r");
        if(arq == NULL)
            printf("Erro na abertura do arquivo re2!");
    }

    buscafrase(frase, arq, est);
//FALTA HTML AQUI
    printf("\n\n--CENAFALAhtml.... %s\n\n", frase);

                    //link que avanca pra proxima pagina
					//printf("<a href='http://cap.dc.ufscar.br/~726395/cgi-bin/dialogo.cgi?lvl=%d&resp=0&nome=%s' id = 'resp1'> <div class='dialogo'> Resposta A</div>  </a>",env_estado+=1,nome);


}

//FALTA HTML AQUI
void cenaPerg(int est, char nome[10])
{
    srand(time(NULL));

    char frase[20];

    FILE *perg;
    perg = fopen("PERGUNTAS.txt", "r");
    if(perg == NULL)
    {
        printf("Erro na abertura de pergunta!");
    }

    FILE *op1;
    op1 = fopen("OPCAO1.txt", "r");
    if(op1 == NULL)
    {
        printf("Erro na abertura de op1!");
    }

    FILE *op2;
    op2 = fopen("OPCAO2.txt", "r");
    if(op2 == NULL)
    {
        printf("Erro na abertura de op2!");
    }


    buscafrase(frase, perg, est);
                        printf("%s", frase);//localizacao e impressao da pergunta correta
    //É nesta linha que devemos printar a opcao de dialogo atual: ( ^3^)
						//printf("Olá, %s-kun !! Estava esperando por você! <br> Por que demorou tanto?!", nome);     //IMPRIME A VARIAVEL CORRESPONDENTE AO NOME DO JOGADOR INSERIDO NO FORMULARIO talvez nao de pouque arquivps
					printf("</div><!--texto-->");
				printf("</div> <!--tela-->");

//FALTA HTML AQUI
    if(rand()%2)//a ordem da imprecao das opcoes eh definida aleatoriamente
    {
        buscafrase(frase, op1, est);
        printf("\nhtml.... %s", frase);

        buscafrase(frase, op2, est);
        printf("\nhtml.... %s\n\n", frase);
    }
    else
    {
        buscafrase(frase, op2, est);
        printf("\nhtml.... %s", frase);

        buscafrase(frase, op1, est);
        printf("\nhtml.... %s\n\n", frase);
    }


				printf("<div id='respostas'>");
					// Links com as opções de respostas (^-^ )

					printf("<a href='http://cap.dc.ufscar.br/~726395/cgi-bin/dialogo.cgi?lvl=%d&resp=0&nome=%s' id = 'resp1'> <div class='dialogo'> Resposta A</div>  </a>",est+=1,nome);
					printf("<a href='http://cap.dc.ufscar.br/~726395/cgi-bin/dialogo.cgi?lvl=%d&resp=1&nome=%s' id = 'resp2'> <div class='dialogo'> Resposta B</div>  </a>",est+=1,nome);


				printf("</div><!--respostas-->");
			printf("</div> <!--container-->");

}

//FALTA HTML AQUI
void cenaFinal(int est, int pontuacao, char nome[10])
{
    char falafinal[20];
    int f;

    FILE *esp;
    esp = fopen("ESPECIAL.txt", "r");
    if(esp == NULL)
    {
        printf("Erro na abertura de esp!");
    }

    if(pontuacao>NUM_NIVEIS/6)//calculo para determinar qual final o jogador consegue
        f=1;//final bom
    else if (pontuacao<-NUM_NIVEIS/6)
        f=2;//finalruim
    else
        f=3;//final neutro

    buscafrase(falafinal, esp, f);
//FALTA HTML AQUI
    printf("\n\nFIMALhtml.... %s", falafinal);
}


