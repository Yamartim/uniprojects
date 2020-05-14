#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv)
{
int i; 
char nome[10];   //nome do coitado que esta jogando isso
char n[2]; //variavel do nivel em string
int nivel; // fase atual do jogo
int id; // codigo da resposta selecionada pelo jogador;	
char *dados; // dados retirados do metodo get no link (^o^)
char *copia; //copia de parte da var dados
char *img; //nome do arquivo da imagem DO PERSONAGEM e o formato.. SEM o caminho na pasta
char *cenario; //nome do arquivo da imagem do CENARIO com o formato, SEM o caminho da pasta 


//DEPOIS TIRAR ISSO DAQUI, É SÓ PRA TESTE
img = "nico.png"; 
cenario = "esc.jpg";

printf("Content-type:text/html\r\n\r\n");
printf("<meta charset = 'UTF-8'/>");
  
  //Retirada das informacoes do link por method get ^-^
   dados = getenv("QUERY_STRING"); 

    if(dados == NULL){
          printf("<P>Erro! Erro na passagem dos dados \n");
	}
	
	else{
  		
		//Pegando o nivel
		copia = strstr(dados,"lvl="); 
		strncpy(n, copia, 2);
		nivel = atoi(n);		
		 
		//Pegando o nome
		copia = strstr(dados,"nome="); 
		strcpy(nome,copia+5);
		 
		//Pegando o id da resposta
		copia = strstr(dados,"resp="); 
		strncpy(n, copia, 2);
		id = atoi(n);
		 
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
				
				//É neste printf que voce altera as imagens de cenario e da personagem~ tuturu ^3^
				printf("<div id='tela' style='background-image: url(../imagens/cenarios/%s);background-size: cover; background-repeat:no-repeat;'>",cenario);
					printf("<img class='char' src='../imagens/personagens/%s'/>",img);
					printf("<div id='texto'>");
					
					//É nesta linha que devemos printar a opcao de dialogo atual: ( ^3^) 
						printf("Olá, %s-kun !! Estava esperando por você! <br> Por que demorou tanto?!", nome);     //IMPRIME A VARIAVEL CORRESPONDENTE AO NOME DO JOGADOR INSERIDO NO FORMULARIO
					printf("</div><!--texto-->");
				printf("</div> <!--tela-->");

				printf("<div id='respostas'>");
					// Links com as opções de respostas (^-^ )
					
					printf("<a href='http://cap.dc.ufscar.br/~726395/cgi-bin/dialogo.cgi?lvl=%d&resp=0&nome=%s' id = 'resp1'> <div class='dialogo'> Resposta A</div>  </a>",nivel+=1,nome);
					printf("<a href='http://cap.dc.ufscar.br/~726395/cgi-bin/dialogo.cgi?lvl=%d&resp=1&nome=%s' id = 'resp2'> <div class='dialogo'> Resposta B</div>  </a>",nivel+=1,nome);
					
					
				printf("</div><!--respostas-->");
			printf("</div> <!--container-->");



		printf("</body>");

	}

}
