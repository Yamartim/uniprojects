#include <stdio.h>
#include <stdlib.h>

int main()
{
    //numeros perfeitos de 1 a 1000
/*
    int soma, i, j;

    for(i=1; i<1000; i++){
        soma = 0;
        for(j=1;j<i;j++){
            if(i%j==0){
                soma+= j;
            }
        }
        if (soma == i)
            printf(" %d", i);

    }
    */

    //calcuular piiiiiiiii

    /*
    float den, pi= 0;
    int i, p, sin;
    sin = 1;
    den = 1.0;

    printf("precision, manda ae: ");
    scanf("%d", &p);

    for(i=0; i<p; i++){
        pi += 1.0/den*sin;
        den+=2.0;
        sin = -sin;
    }
    printf("pi: %f", pi*4);
    */

    //milhar centena dezena unidade
    /*
    printf("manda um numero de 4 digitos\n");
    int n, m, c, d, u;
    scanf("%d", &n);
    m = n/1000;
    c = n/100 -10*m;
    d = n/10 -10*c -100*m;
    u = n -10*d -100*c -1000*m;

    printf("%d milhares\n%d centenas\n%d dezenas\n%d unidades", m, c, d, u);
    */

    //funcionarios atrasados

    /*
    int i, h, m;
    int C=0;
    int F=0;
    int J=0;
    int P=0;
    char codigo[50]="a";
    i=0;

    while(codigo[i]!='x'){

        printf("em que hora o funcionario entrou:\n");
        scanf("%d", &h);
        fflush(stdin);
        printf("em que minuto o funcionario entrou:\n");
        scanf("%d", &m);
        fflush(stdin);
        printf("\no funcionario entrou as %dh%d\n\ninforme o codigo do funcionario: ", h, m);

        scanf("%c", &codigo);
        fflush(stdin);

        if(h>8 || (h==8 && m>0)){
            switch(codigo[i]){

            case 'c': C++;
            break;

            case 'f': F++;
            break;

            case 'j': J++;
            break;

            case 'p': P++;
            break;
            }
        }*/
    }
    printf("\nempregados atrasados:\n%d comunicacao\n%d judiciario\n%d pessoal\n%d financas", C, J, P, F);



}
