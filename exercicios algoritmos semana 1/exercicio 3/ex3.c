//exercicio 3
//o programa lê 3 números digitados(n0, r e t), passa eles por uma função exponencial e retorna o valor inteiro aproximado do resultado do calculo(resultado_inteiro).

#include <math.h> //inclusão da biblioteca de funções matemáticas
#include <stdio.h>

int main(){

//declaração de variaveis
int resultado_inteiro;
float resultado;
float n0;
float r;
float t;

//o programa pede para o usuario digitar os 3 dados necessários para jogar na função exponencial
printf("A função é: N(t)= N0e^rt \nDigite o N0:");
scanf("%f", &n0);
printf("Digite o r:");
scanf("%f", &r);
printf("Digite o t:");
scanf("%f", &t);

//calculo realizado na função exponencial apresentada para o exercicio
resultado=n0*(exp(r*t));
resultado_inteiro= ceil(resultado);

//impressão do calculo realizado juntamente com o resultado do calculo
printf("\nCalculo: %d=%f*(10^(%f*%f))\n", resultado_inteiro, n0, r, t);

return 0;
}
