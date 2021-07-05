// exercicio 2
// o programa l� um n�mero de 4 digitos e imprime na tela o mesmo n�mero ao contr�rio. ex: 1234 >>>>>> 4321.

#include <stdio.h>

int main()
{
//variavel de entrada dos 4 digitos
int entrada;

//variaveis de saida pros 4 digitos inversos
int p;
int s;
int t;
int q;

//o programa pede pro usuario digitar os 4 digitos
printf("Digite um numero de 4 digitos:");
scanf("%d", &entrada);

//l�gica por tr�s da separa��o de algarismos:
//o primeiro algarismo � obtido dividindo o numero de entrada por 1000
//o segundo � obtido dividindo por 100, depois dividindo por 10, sendo ent�o o resto dessa divis�o
//o terceiro � obtido dividindo por 10, ap�s por 100 e usando seu resto para dividir por 10, sendo ent�o o resto dessa ultima divis�o
//o quarto � o resto das divis�es da entrada por 1000, 100 e 10
p= entrada/1000;
s= (entrada/100) % 10;
t= ((entrada/10) %100) %10;
q= ((entrada %1000) %100) %10;

printf("Aqui estao os digitos ao contrario: %d%d%d%d", q,t,s,p);

return 0;
}
