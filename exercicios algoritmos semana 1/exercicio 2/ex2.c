// exercicio 2
// o programa lê um número de 4 digitos e imprime na tela o mesmo número ao contrário. ex: 1234 >>>>>> 4321.

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

//lógica por trás da separação de algarismos:
//o primeiro algarismo é obtido dividindo o numero de entrada por 1000
//o segundo é obtido dividindo por 100, depois dividindo por 10, sendo então o resto dessa divisão
//o terceiro é obtido dividindo por 10, após por 100 e usando seu resto para dividir por 10, sendo então o resto dessa ultima divisão
//o quarto é o resto das divisões da entrada por 1000, 100 e 10
p= entrada/1000;
s= (entrada/100) % 10;
t= ((entrada/10) %100) %10;
q= ((entrada %1000) %100) %10;

printf("Aqui estao os digitos ao contrario: %d%d%d%d", q,t,s,p);

return 0;
}
