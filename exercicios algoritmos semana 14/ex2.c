/*Vitor Simon de Souza, 00325102 - Turma H, Eng. de Controle e Automa��o. O programa deve receber os valores de X e Y, realizar a divis�o entre eles, exibir o quociente e o n�mero de chamadas da fun��o que realiza a divis�o.
Entradas: X e Y
Saidas: Quociente e o numero de chamadas da fun��o */
#include <stdio.h>

int quociente(int x, int y, int *chamadas)  //declara��o da fun��o, recebe como par�metros os valores de X e Y e o ponteiro da vari�vel em que ser� armazenado o n�mero de chamadas que a fun��o realizou
{
    printf("saease: %d", *chamadas);
    if(x>y)  //se X for maior q Y
    {
        (*chamadas)++; //incrementa o n�mero de chamadas
        return 1+quociente(x-y, y, chamadas); //retorna 1+(resultado da fun��o quociente com os parametros de X=x-y e Y=y.
    }
    if(x<y)  //se X for menor que Y
    {
        (*chamadas)++; //incrementa o n�mero de chamadas
        return 0; //e retorna 0

    }
    if(x==y)  //se X for igual a Y
    {
        (*chamadas)++; //incrementa o n�mero de chamadas
        return 1; //e retorna 1
    }
}

int main()
{
    int x, y, chamadas=0; //declara��o das variaveis em que s�o armazenados os valores de x, y e o numero de chamadas

    printf("Digite os numeros de X e Y: ");
    scanf("%d%d", &x, &y); //o usuario digita os valores de x e y

    printf("Quociente da divis�o entre %d e %d eh: %d", x, y, quociente(x, y, &chamadas)); //o programa printa o valor do quociente
    printf("\nNumero de chamadas da funcao: %d\n", chamadas); //e o numero de chamadas recursivas que a fun��o realizou

    return 0;
}
