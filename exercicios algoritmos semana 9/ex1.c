/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H.
O programa atua tirando a raiz cubica de um número digitado pelo usuário. O usuário digita o número que quer a raiz cubica, o valor inicial para a
aproximação da raiz e a tolerância entre a diferença das 2 ultimas aproximações calculadas.

Entradas: valor que o usuário quer a raiz, valor inicial para aproximação, tolerância entre a diferença das aproximações
Saída: raiz cubica do número pedido pelo usuário
*/

#include <stdio.h>
#include <math.h>
//declaração da função real em que é calculada a raiz cubica.
float raizcubica(float r, float xn, float tol) //a variavel "r" é o numero que o usuario quer a raiz, "xn" é o numero para aproximação inicial e "tol" a tolerância
{

float xn1; //resultado da raiz cubica
float dif; //variavel usada para armazenar a diferença entre as aproximações.
dif=tol+1; //dif é iniciada com um valor maior que a tolerancia para entrar pelo menos 1 vez no laço while

while (dif>tol){ //enquanto a diferença das duas ultimas aproximações for maior q a tolerância o laço será executado

    xn1=(((2*pow(xn,3))+r)/(3*(pow(xn,2)))); //formula para aproximação
    dif=fabs(xn1-xn); // "dif" é o valor absoluto da diferença entre as duas ultimas aproximações
    xn=xn1; //passa o valor calculado da ultima iteração para a variavel da penultima antes de reiniciar o laço
}
return xn1; //a função retorna o valor do resultado da raiz cubica
}


int main(){
float xn; //numero para aproximação inicial
float tol; //tolerância
float r; //numero que o usuario quer a raiz
//o programa solicita que o usuário digite:
printf("Digite o valor para tirar a raiz cubica: ");
scanf(" %f", &r); //o numero que o usuario quer a raiz
printf("Digite o valor para a aproximacao inicial: ");
scanf(" %f", &xn); //o valor para a aproximação inicial
printf("Digite o valor da tolerancia: ");
scanf(" %f", &tol); //o valor de tolerancia
//o programa chama a função e já retorna seu resultado diretamente no printf:
printf("\nO valor estimado para a raiz cubica de %.4f eh: %.4f", r, raizcubica(r, xn, tol));

return 0;
}
