/*exercicio 2: o programa pede para o usuario digitar 2 coordenadas(x,y) e diz se o ponto referente �s coordenadas pertence � regi�o A, B, C ou nenhuma das 3.

entradas: x, y
*/
#include <stdio.h>

int main(){

float x, y;     //declara��o das vari�veis x, y
int foradereg = 0;  //essa vari�vel foi usada como auxiliar para definir quando o ponto n�o est� em nenhuma regi�o coberta pelo programa

//o programa pede para o usu�rio digitar as coordenadas x e y:
printf("Digite as coordenadas X e Y:");
scanf("%f%f", &x, &y);

//se o x for maior que 2 e y menor que 0, o programa exibe que o ponto pertence � regi�o C e soma 1 na vari�vel foradereg:
if( x > 2 && y < 0){
    printf("O ponto informado pertence a regiao C!");
    foradereg++;
}
//se x for ao mesmo tempo menor que 2 e maior que 0, e y menor que 4 e maior que 0, o programa exibe que o ponto pertence � regi�o B e soma 1 na vari�vel foradereg:
if( (x < 2 && x > 0) && (y < 4 && y > 0) ){
    printf("O ponto informado pertence a regiao B!");
    foradereg++;
}
//se x for menor que 0 e y maior que 4, o programa exibe que o ponto pertence � regi�o A e soma 1 na vari�vel foradereg:
if( x < 0 && y > 4 ){
    printf("O ponto informado pertence a regiao A!");
    foradereg++;
}
//se a vari�vel foradereg n�o tiver sido incrementada em +1 no programa inteiro, o programa exibe que o ponto informado n�o consta em nenhuma das regi�es:
if(foradereg==0)
    printf("O ponto informado nao pertence a nenhuma regiao inclusa no programa!");

}
