/* exercicio 1: o programa lê os lados e a diagonal ac do quadrilátero e imprime na tela se ele é um quadrado, retângulo, losango, paralelogramo ou se não é nenhum dos anteriores

entradas:
    lados: ab,bc,cd,da
    diagonal: diagac
saídas internas do programa: diagquadrado, aux1, diagtret, aux2
*/
#include <stdio.h>
#include <math.h>

int main(){

//definição das variáveis de entrada:
float ab;
float bc;
float cd;
float da;
float diagac;
//definição das variáveis de saída internas do programa:
float diagquadrado;
float aux1;
float diagtret;
float aux2;

//o programa pede para o usuário digitar os lados e a diagonal ac:
printf("Insira o lado AB: ");
scanf("%f", &ab);
printf("Insira o lado BC: ");
scanf("%f", &bc);
printf("Insira o lado CD: ");
scanf("%f", &cd);
printf("Insira o lado DA: ");
scanf("%f", &da);
printf("Insira o valor da diagonal AC: ");
scanf("%f", &diagac);

//se os lados forem todos iguais ele define se o quadrilátero é um quadrado ou losango:
if(ab == bc && bc == cd && cd == da){

    diagquadrado = (ab*(sqrt(2)));
    aux1 = (diagquadrado-diagac);

        if(fabs(aux1) < 0.001){
        printf("O quadrilatero eh um quadrado!");
        }
        else{
        printf("O quadrilatero eh um losango!");
        }
}
//se os lados ab e cd forem iguais e ao mesmo tempo ab e bc forem diferentes, o programa indica se o quadrilátero é um retângulo ou um paralelogramo:
if(ab == cd && ab != bc){

   diagtret = sqrt(((ab*ab)+(bc*bc)));
   aux2 = (diagtret - diagac);

        if(fabs(aux2) < 0.001){
        printf("O quadrilatero eh um retangulo!");
        }
        else{
        printf("O quadrilatero eh um paralelogramo!");
        }
}

//se o lado ab for diferente de cd, o programa indica que o quadrilátero não consta no banco de dados, já que essa condição não é prevista pelo programa:
if(ab != cd)
    printf("O quadrilatero nao consta no banco de dados!");

return 0;
}
