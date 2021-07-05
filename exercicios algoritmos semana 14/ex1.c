/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H. O programa recebe um vetor inteiro com um numero TAMVET de elementos e um outro inteiro e imprime o n�mero de ocorr�ncias do inteiro no vetor
Entradas: vetor de inteiros, n�mero inteiro a ser pesquisado
Saidas: n�mero de ocorr�ncias do inteiro no vetor*/
#include <stdio.h>
#define TAMVET 5

int conta_inteiro(int *vet, int tam, int num)  //fun��o que faz a contagem da apari��o de "num" no vetor "vet", a fun��o recebe como parametros o ponteiro para o vetor, o tamanho dele, e o n�mero a ser procurado.
{

    if(tam-1==-1)  //se o tamanho do vetor for igual a 0
    {
        return 0; //a fun��o retorna 0
    }
    else
    {
        if(*(vet+tam-1) ==num)  //se o conteudo do vetor na posi��o "tam-1" for igual ao numero pesquisado
        {
            return (1+conta_inteiro(vet, tam-1, num)); //retorna 1+(resultado de conta_inteiro(vet, tam-1, num)
        }
        return conta_inteiro(vet, tam-1, num); //se n�o for igual, continua pesquisando realizando novas chamadas da fun��o decrementando o indice da posi��o do vetor.
    }
}

int main()
{

    int vetor[TAMVET], num; //variaveis do vetor e do numero pesquisado

    printf("Digite os %d elementos do vetor: ", TAMVET);
    for(int i=0; i<TAMVET; i++)  //leitura do vetor
    {
        scanf("%d", &vetor[i]);
    }
    printf("Digite o inteiro a ser procurado: ");
    scanf("%d", &num); //leitura do numero a ser pesquisado
    printf("Numero de ocorrencias do numero %d no vetor: %d", num, conta_inteiro(vetor, TAMVET, num)); //impress�o do n�mero de ocorrencias do numero no vetor


    return 0;
}
