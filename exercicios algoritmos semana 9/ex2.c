/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H.
O programa recebe do utilizador 3 valores e testa se eles formam um triangulo, imprimindo na tela o tipo de triangulo e seu perímetro.
Se os lados não formarem um triangulo, o programa exibe essa informação.

Entradas: os 3 lados do triangulo
Saidas: tipo de triângulo e seu perimetro(se os valores não formarem um triangulo, o programa imprime isso) */
#include <stdio.h>

char triangulo(float, float, float, float*); //protótipo da função que diz o tipo e se é um triangulo ou não

int main(){
float a, b, c, perimetro; //variaveis dos lados do possivel triangulo: a, b, c  //variavel onde será armazenado o perimetro: perimetro

printf("Digite os valores para os lados A, B e C: ");//o programa pede os valores dos lados do possivel triangulo e faz a coerencia para que sejam todos positivos
scanf(" %f%f%f", &a, &b, &c);
while(a<=0 || b<=0 || c<=0){ //caso algum dos valores seja negativo ou 0, o programa pede para o usuário digitar novos valores
    printf("Valores invalidos! Digite valores positivos e maiores que 0 para os lados A, B e C: ");
    scanf(" %f%f%f", &a, &b, &c);
}
switch(triangulo(a, b, c, &perimetro)){ //chama o resultado da função informando os valores de A, B e C e o endereço da variavel que conterá o valor do perímetro no programa principal
case 'n': //caso o caracter retornado da função triangulo seja "n", o programa imprime que os valores informados não correspondem a um triangulo
    printf("Os valores informados nao formam um triangulo!");
    break;
case 'q': //caso o caracter retornado da função triangulo seja "q", o programa imprime que os valores informados correspondem a um triangulo equilatero e imprime junto seu perimetro
    printf("O triangulo eh equilatero, seu perimetro eh: %f", perimetro);
    break;
case 'i': //caso o caracter retornado da função triangulo seja "i", o programa imprime que os valores informados correspondem a um triangulo isosceles e imprime junto seu perimetro
    printf("O triangulo eh isosceles, seu perimetro eh: %f", perimetro);
    break;
case 'e': //caso o caracter retornado da função triangulo seja "e", o programa imprime que os valores informados correspondem a um triangulo escaleno e imprime junto seu perimetro
    printf("O triangulo eh escaleno, seu perimetro eh: %f", perimetro);
    break;
}
return 0;
}
//declaração da função que calcula se os valores formam um triangulo ou não, o tipo de triangulo e o perimetro:
char triangulo(float a, float b, float c, float *perimetro){//a, b e c são as variaveis dos lados do triangulo, "*perimetro" é usado para retornar o valor do perimetro na variavel do programa principal

if( ((a+b)>c) && ((a+c)>b) && ((c+b)>a) ){ // se a soma de 2 lados for maior que o terceiro os valores são considerados lados de um triangulo
    *perimetro=(a+b+c); //calculo do perimetro do triangulo
    if(a==b && b==c) //se os lados forem todos iguais, a função retorna o caracter "q"
        return 'q';

    if(a==b || b==c || c==a) //se somente 2 lados forem iguais, a função retorna o caracter "i"
        return 'i';

    if(a!=b && b!=c && c!=a) //se nenhum dos lados forem iguais, a função retorna o caracter "e"
        return 'e';

}else{ //se a soma de 2 lados NÃO for maior que o terceiro os valores NÃO são considerados lados de um triangulo e a função define a variavel correspondente ao perimetro no programa principal como "-1" e retorna o caracter "n"
*perimetro= -1;
return 'n';
}
}
