/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H.
O programa atua tirando a raiz cubica de um n�mero digitado pelo usu�rio. O usu�rio digita o n�mero que quer a raiz cubica, o valor inicial para a
aproxima��o da raiz e a toler�ncia entre a diferen�a das 2 ultimas aproxima��es calculadas.

Entradas: valor que o usu�rio quer a raiz, valor inicial para aproxima��o, toler�ncia entre a diferen�a das aproxima��es
Sa�da: raiz cubica do n�mero pedido pelo usu�rio
*/

#include <stdio.h>
#include <math.h>
//declara��o da fun��o real em que � calculada a raiz cubica.
float raizcubica(float r, float xn, float tol) //a variavel "r" � o numero que o usuario quer a raiz, "xn" � o numero para aproxima��o inicial e "tol" a toler�ncia
{

float xn1; //resultado da raiz cubica
float dif; //variavel usada para armazenar a diferen�a entre as aproxima��es.
dif=tol+1; //dif � iniciada com um valor maior que a tolerancia para entrar pelo menos 1 vez no la�o while

while (dif>tol){ //enquanto a diferen�a das duas ultimas aproxima��es for maior q a toler�ncia o la�o ser� executado

    xn1=(((2*pow(xn,3))+r)/(3*(pow(xn,2)))); //formula para aproxima��o
    dif=fabs(xn1-xn); // "dif" � o valor absoluto da diferen�a entre as duas ultimas aproxima��es
    xn=xn1; //passa o valor calculado da ultima itera��o para a variavel da penultima antes de reiniciar o la�o
}
return xn1; //a fun��o retorna o valor do resultado da raiz cubica
}


int main(){
float xn; //numero para aproxima��o inicial
float tol; //toler�ncia
float r; //numero que o usuario quer a raiz
//o programa solicita que o usu�rio digite:
printf("Digite o valor para tirar a raiz cubica: ");
scanf(" %f", &r); //o numero que o usuario quer a raiz
printf("Digite o valor para a aproximacao inicial: ");
scanf(" %f", &xn); //o valor para a aproxima��o inicial
printf("Digite o valor da tolerancia: ");
scanf(" %f", &tol); //o valor de tolerancia
//o programa chama a fun��o e j� retorna seu resultado diretamente no printf:
printf("\nO valor estimado para a raiz cubica de %.4f eh: %.4f", r, raizcubica(r, xn, tol));

return 0;
}
