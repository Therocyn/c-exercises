/* exercicio 1: o programa l� os lados e a diagonal ac do quadril�tero e imprime na tela se ele � um quadrado, ret�ngulo, losango, paralelogramo ou se n�o � nenhum dos anteriores

entradas:
    lados: ab,bc,cd,da
    diagonal: diagac
sa�das internas do programa: diagquadrado, aux1, diagtret, aux2
*/
#include <stdio.h>
#include <math.h>

int main(){

//defini��o das vari�veis de entrada:
float ab;
float bc;
float cd;
float da;
float diagac;
//defini��o das vari�veis de sa�da internas do programa:
float diagquadrado;
float aux1;
float diagtret;
float aux2;

//o programa pede para o usu�rio digitar os lados e a diagonal ac:
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

//se os lados forem todos iguais ele define se o quadril�tero � um quadrado ou losango:
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
//se os lados ab e cd forem iguais e ao mesmo tempo ab e bc forem diferentes, o programa indica se o quadril�tero � um ret�ngulo ou um paralelogramo:
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

//se o lado ab for diferente de cd, o programa indica que o quadril�tero n�o consta no banco de dados, j� que essa condi��o n�o � prevista pelo programa:
if(ab != cd)
    printf("O quadrilatero nao consta no banco de dados!");

return 0;
}
