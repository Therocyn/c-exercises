/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H
O programa lê o numero de valores que vai ser digitado(max 20), os próprios valores, imprime na tela a média deles e após isso lê um número de referencia,
calcula e imprime na tela quais desses valores tem distancia ate a media menor do que o numero de referencia.
Entradas: numero de valores, os valores, valor de referencia.
Saídas: média dos valores no arranjo, valores que tem distancia ate a media menor do que o numero de referencia.
 */
#include <stdio.h>
#include <math.h>

int main(){

int cont;
int n; //numero de valores
float xi[20]; //valores
float media=0;
float t; //valor 2
float valorcalculo; //usei essa variavel para armazenar o modulo de "xi-media"

printf("Digite o numero de valores a ser digitado(valor maximo:20): ");
scanf("%d", &n);
while(n<0 || n>20){
    printf("Digite uma quantidade de valores valida: ");
    scanf("%d", &n);
}

for(cont=0; cont<n; cont++){
    printf("Digite o %do valor real: ", cont+1);
    scanf("%f", &xi[cont]);
    media=media+xi[cont];
}
media=media/n;
printf("A media dos valores lidos eh: %.2f", media);

printf("\n\nDigite o valor do limiar de comparacao(numero real positivo): ");
scanf("%f", &t);
while(t<0){
    printf("Digite um valor valido: ");
    scanf("%f", &t);
}

printf("Os elementos do arranjo com distancia ate a media menor do que o limiar sao: ");
for(cont=0; cont<n; cont++){
    valorcalculo=fabs(xi[cont] - media);
    if(valorcalculo<t){
        printf("\n%.2f", xi[cont]);
    }
}

return 0;
}
