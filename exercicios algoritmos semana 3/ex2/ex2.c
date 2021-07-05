/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H.
o programa pede para o usu�rio digitar os valores de b e n, e retorna imprimindo na tela os valores
aproximado e exato da integral de 1/x para limite superior=b e n�mero de intervalos=n.

entradas: b, n.
saidas: valor aproximado da integral, valor exato da integral.

 */
#include <stdio.h>
#include <math.h>

int main(){
//defini��o das vari�veis
float b;
float n;
float auxn;
int a;
int i;
float xim1;
float xi;
float h;
float auxsomatorio;
float somatorio;

//o programa pede para o usu�rio digitar o valor de b, sendo que se o valor for menor que 1 ele pede para que o usu�rio digite outro valor.
printf("Digite um valor real maior ou igual a 1 para b: ");
scanf("%f", &b);
for(b; b<1;){
    printf("Numero invalido, digite um novo valor para b: ");
    scanf("%", &b);
}

//o programa pede para o usu�rio digitar o valor de n, sendo que se o valor for negativo ou n�o for inteiro ele pede para que o usu�rio digite outro valor.
printf("Digite um valor inteiro positivo para n: ");
scanf("%f", &n);
auxn= n - round(n);
for(n; auxn!= 0 || n<0; auxn= n - round(n)){
    printf("Numero invalido, digite um novo valor para n: ");
    scanf("%f", &n);
}

//aqui � feito o c�lculo do valor aproximado da integral, onde a fun��o "for" faz o trabalho de "contar" o n�mero de intervalos na realiza��o do calculo.
somatorio = 0;
for(i=1; i<=n; i++){
a=1;
h=(b-a)/n;
xim1=a+((i-1)*h);
xi=a+(i*h);
auxsomatorio= (((1/xim1) + (1/xi))/2)*h;
somatorio = somatorio+auxsomatorio;
}

//o programa imprime na tela os valores aproximado e exato da integral.
printf("Valor aproximado da integral: %.4f", somatorio);
printf("\nValor exato da integral: %.4f\n", log(b));

return 0;
}
