/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H
O programa pede que o usu�rio digite uma toler�ncia minima em que os termos da f�rmula de Leibniz para o pi podem chegar, e ent�o c�lcula e imprime na tela
o n�mero de termos usados e o valor aproximado de pi baseado nessa toler�ncia.
 */
#include <stdio.h>
#include <math.h>

int main(){
//declara��o das variaveis
double tol;
double termos;
double somatermos=0;
int n=0;
//o programa pede para o usu�rio digitar um valor de toler�ncia
printf("Digite a tolerancia(valor real e positivo): ");
scanf(" %lf", &tol);
for(tol; tol<=0;){ //Se o valor de toler�ncia digitado n�o for positivo e real, o la�o for faz com que o programa pe�a que o usu�rio digite novamente um valor at� que ele esteja dentro dessa condi��o
    printf("Digite um valor positivo e real para a tolerancia: ");
    scanf(" %lf", &tol);
}
do{   //o do-while � usado para realizar o c�lculo da f�rmula de Leibniz at� que o �ltimo termo da f�rmula seja menor que a toler�ncia.
termos= (4*(pow((-1), n)))/((2*n)+1);
somatermos=termos+somatermos;
n++;
printf("%f", termos);
}while(fabs(termos)>=tol);

somatermos=somatermos-termos;  //aqui eu diminuo o �ltimo termo da f�rmula do valor total calculado e 1 do valor de "n" antes de tudo ser impresso na tela pelo fato
printf("O valor aproximado de pi eh: %.10f\n", somatermos);  //do do-while realizar a checagem de condi��o somente no final do comando.
printf("Foram usados %d termos na aproximacao", n-1);

return 0;
}
