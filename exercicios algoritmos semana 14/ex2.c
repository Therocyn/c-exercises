/*Vitor Simon de Souza, 00325102 - Turma H, Eng. de Controle e Automação. O programa deve receber os valores de X e Y, realizar a divisão entre eles, exibir o quociente e o número de chamadas da função que realiza a divisão.
Entradas: X e Y
Saidas: Quociente e o numero de chamadas da função */
#include <stdio.h>

int quociente(int x, int y, int *chamadas)  //declaração da função, recebe como parâmetros os valores de X e Y e o ponteiro da variável em que será armazenado o número de chamadas que a função realizou
{
    printf("saease: %d", *chamadas);
    if(x>y)  //se X for maior q Y
    {
        (*chamadas)++; //incrementa o número de chamadas
        return 1+quociente(x-y, y, chamadas); //retorna 1+(resultado da função quociente com os parametros de X=x-y e Y=y.
    }
    if(x<y)  //se X for menor que Y
    {
        (*chamadas)++; //incrementa o número de chamadas
        return 0; //e retorna 0

    }
    if(x==y)  //se X for igual a Y
    {
        (*chamadas)++; //incrementa o número de chamadas
        return 1; //e retorna 1
    }
}

int main()
{
    int x, y, chamadas=0; //declaração das variaveis em que são armazenados os valores de x, y e o numero de chamadas

    printf("Digite os numeros de X e Y: ");
    scanf("%d%d", &x, &y); //o usuario digita os valores de x e y

    printf("Quociente da divisão entre %d e %d eh: %d", x, y, quociente(x, y, &chamadas)); //o programa printa o valor do quociente
    printf("\nNumero de chamadas da funcao: %d\n", chamadas); //e o numero de chamadas recursivas que a função realizou

    return 0;
}
