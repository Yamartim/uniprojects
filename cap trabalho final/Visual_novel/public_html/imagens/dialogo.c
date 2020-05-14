int main(){

char nome = "FULANINHO";

printf("<!-DOCTYPE html>");
printf("<html>");
	printf("<header>");
		printf("<meta charset = 'UTF-8'/>");
		printf("<link rel='stylesheet' type='text/css' href='style.css'/>");
		printf("<title>");
		printf("</title>");
	printf("</header>");
	
	printf("<body style='background-image: url(imagens/cenarios/fundo.png)'>");
		printf("<div id='container'>");
			printf("<div id='tela' style='background-image: url(imagens/cenarios/esc.jpg);background-size: cover; background-repeat:no-repeat;'>");
				printf("<img class='char' src='imagens/personagens/nico.png'/>");
				printf("<div id='texto'>");
					printf("%s", nome);     //IMPRIME A VARIAVEL CORRESPONDENTE AO NOME DO JOGADOR INSERIDO NO FORMULARIO
				printf("</div><!--texto-->");
			printf("</div> <!--tela-->");
			
			printf("<div id='respostas'>");
				printf("<a href='#' id = 'resp1'> <div class='dialogo'>  RESPOSTA A</div>  </a>"); 
				printf("<a href='#' id = 'resp2'> <div class='dialogo'>  RESPOSTA B</div>  </a> ");
			printf("</div><!--respostas-->");
		printf("</div> <!--container-->");
		
		
	
	printf("</body>");
	
printf("</html>");
}