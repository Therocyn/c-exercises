//exercicio 3
//o programa l� 3 n�meros digitados(n0, r e t), passa eles por uma fun��o exponencial e retorna o valor inteiro aproximado do resultado do calculo(resultado_inteiro).

#include <math.h> //inclus�o da biblioteca de fun��es matem�ticas
#include <stdio.h>

int main(){

//declara��o de variaveis
int resultado_inteiro;
float resultado;
float n0;
float r;
float t;

//o programa pede para o usuario digitar os 3 dados necess�rios para jogar na fun��o exponencial
printf("A fun��o �: N(t)= N0e^rt \nDigite o N0:");
scanf("%f", &n0);
printf("Digite o r:");
scanf("%f", &r);
printf("Digite o t:");
scanf("%f", &t);

//calculo realizado na fun��o exponencial apresentada para o exercicio
resultado=n0*(exp(r*t));
resultado_inteiro= ceil(resultado);

//impress�o do calculo realizado juntamente com o resultado do calculo
printf("\nCalculo: %d=%f*(10^(%f*%f))\n", resultado_inteiro, n0, r, t);

return 0;
}
