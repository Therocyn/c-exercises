/*exercicio 2: o programa pede para o usuario digitar 2 coordenadas(x,y) e diz se o ponto referente às coordenadas pertence à região A, B, C ou nenhuma das 3.

entradas: x, y
*/
#include <stdio.h>

int main(){

float x, y;     //declaração das variáveis x, y
int foradereg = 0;  //essa variável foi usada como auxiliar para definir quando o ponto não está em nenhuma região coberta pelo programa

//o programa pede para o usuário digitar as coordenadas x e y:
printf("Digite as coordenadas X e Y:");
scanf("%f%f", &x, &y);

//se o x for maior que 2 e y menor que 0, o programa exibe que o ponto pertence à região C e soma 1 na variável foradereg:
if( x > 2 && y < 0){
    printf("O ponto informado pertence a regiao C!");
    foradereg++;
}
//se x for ao mesmo tempo menor que 2 e maior que 0, e y menor que 4 e maior que 0, o programa exibe que o ponto pertence à região B e soma 1 na variável foradereg:
if( (x < 2 && x > 0) && (y < 4 && y > 0) ){
    printf("O ponto informado pertence a regiao B!");
    foradereg++;
}
//se x for menor que 0 e y maior que 4, o programa exibe que o ponto pertence à região A e soma 1 na variável foradereg:
if( x < 0 && y > 4 ){
    printf("O ponto informado pertence a regiao A!");
    foradereg++;
}
//se a variável foradereg não tiver sido incrementada em +1 no programa inteiro, o programa exibe que o ponto informado não consta em nenhuma das regiões:
if(foradereg==0)
    printf("O ponto informado nao pertence a nenhuma regiao inclusa no programa!");

}
