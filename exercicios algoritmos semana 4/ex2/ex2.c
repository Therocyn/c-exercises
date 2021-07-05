/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H
O programa pede que o usuário digite uma tolerância minima em que os termos da fórmula de Leibniz para o pi podem chegar, e então cálcula e imprime na tela
o número de termos usados e o valor aproximado de pi baseado nessa tolerância.
 */
#include <stdio.h>
#include <math.h>

int main(){
//declaração das variaveis
double tol;
double termos;
double somatermos=0;
int n=0;
//o programa pede para o usuário digitar um valor de tolerância
printf("Digite a tolerancia(valor real e positivo): ");
scanf(" %lf", &tol);
for(tol; tol<=0;){ //Se o valor de tolerância digitado não for positivo e real, o laço for faz com que o programa peça que o usuário digite novamente um valor até que ele esteja dentro dessa condição
    printf("Digite um valor positivo e real para a tolerancia: ");
    scanf(" %lf", &tol);
}
do{   //o do-while é usado para realizar o cálculo da fórmula de Leibniz até que o último termo da fórmula seja menor que a tolerância.
termos= (4*(pow((-1), n)))/((2*n)+1);
somatermos=termos+somatermos;
n++;
printf("%f", termos);
}while(fabs(termos)>=tol);

somatermos=somatermos-termos;  //aqui eu diminuo o último termo da fórmula do valor total calculado e 1 do valor de "n" antes de tudo ser impresso na tela pelo fato
printf("O valor aproximado de pi eh: %.10f\n", somatermos);  //do do-while realizar a checagem de condição somente no final do comando.
printf("Foram usados %d termos na aproximacao", n-1);

return 0;
}
