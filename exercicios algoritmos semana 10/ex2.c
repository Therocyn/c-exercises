/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H.
O programa recebe a quantidade de elementos de 2 conjuntos, os elementos deles, e ap�s isso imprime os conjuntos sem elementos repetidos e o conjunto intersec��o dos 2. */
#include <stdio.h>
//declara��o da fun��o usada para remover elementos repetidos:
int remove_duplicados(int *vet_entrada, int n_entrada, int *vet_saida){ //"*vet_entrada" � a variavel do vetor original contendo elementos repetidos, "n_entrada" � o numero de elementos do conjunto original, "*vet_saida" � vetor do conjunto j� sem elementos repetidos.
int n_saida=0; //variavel onde ser� armazenado o numero de elementos do vetor sem elementos repetidos.
int repete; // variavel q indica se um numero X � repetido ou n�o.
for(int i=0; i<n_entrada;i++){ //o la�o percorre em primeiro plano o vetor original
        repete=0; //para cada itera��o no vetor original iniciamos a variavel que armazena se o n�mero � repetido ou n�o como 0.
        for(int j=0; j<n_saida; j++){ //percorremos o vetor de saida at� o elemento "n_saida" atual do vetor de saida.
            if(*(vet_entrada+i)== *(vet_saida+j)){ //se o vetor de entrada em um indice "i" qualquer tiver valor igual j� armazenado em um indice "j" qualquer do vetor de saida, a variavel "repete" � incrementada em 1, de forma a mostrar que aquele elemento j� existe no vetor de saida.
                repete++;
            }
        }
        if(repete==0){ //se o vetor de saida � percorrido e n�o � encontrado nenhum elemento igual ao da itera��o "i" do vetor de entrada, a variavel "repete" se mant�m em 0
            *(vet_saida+n_saida)=*(vet_entrada+i); //� passado o valor do vetor de entrada para o vetor de saida.
            n_saida++; // e � incrementado o numero de elementos do vetor de saida em 1.
        }
    }

return n_saida; //o programa retorna o n�mero de elementos final do conjunto sem elementos repetidos.
}
//declara��o da fun��o usada para fazer a intersec��o de dois conjuntos:
int interseccao(int *vet1, int num1, int *vet2, int num2, int *intersec){ //"*vet1" � o conjunto 1 j� sem elementos repetidos, "num1" � o numero de elementos do conjunto 1, "*vet2" � o conjunto 2 j� sem elementos repetidos, "num2" � o numero de elementos do conjunto 2, "*intersec* � vetor no programa principal que ser� transformado no conjunto intersec��o.
int n_saida=0; //variavel em que ser� armazenado o numero de elementos do conjunto intersec��o.
for(int i=0; i<num1; i++){ //percorremos o conjunto 1

    for(int j=0; j<num2; j++){//para cada itera��o onde percorremos o conjunto 1, percorremos o conjunto 2 inteiro.
        if(*(vet1+i)==*(vet2+j)){ //se algum elemento do conjunto 2 for igual ao do conjunto 1 naquela itera��o, o valor � passado para o conjunto intersec��o e � incrementado em 1 o indice da intersec��o, de forma a ir para o proximo elemento pois j� sabemos que nos conjuntos n�o temos nenhum elemento duplicado.
            *(intersec+n_saida)=*(vet1+i);
            n_saida++;
        }
    }
}
return n_saida;//a fun��o retorna o n�mero de elementos final do conjunto intersec��o
}


int main(){
#define TAM_MAX_VET 15
//vetor que armazena o conjunto 1 c/ elementos repetidos:       //vetor que armazena o conjunto 2 c/ elementos repetidos:       //vetor que armazena o conjunto 1 SEM elementos repetidos:      //vetor que armazena o conjunto 2 SEM elementos repetidos:              //vetor intersec��o dos conjuntos 1 e 2:
            int conjunto1[TAM_MAX_VET],                                 conjunto2[TAM_MAX_VET],                                       conjunto11[TAM_MAX_VET],                                      conjunto22[TAM_MAX_VET],                                                intersec[TAM_MAX_VET];
int num1, num2; //"num1" � o numero de elementos do conjunto 1, "num2" � o numero de elementos do conjunto 2
int i; //variavel usada para percorrer o indice dos vetores na impress�o e leitura dos elementos

//o programa pede para que o usu�rio digite a quantidade de elementos dos conjuntos e os elementos deles:
printf("Entre o numero de elementos do conjunto 1: ");
scanf(" %d", &num1);
printf("Entre os elementos do conjunto 1: ");
for(i=0; i<num1; i++){
    scanf(" %d", &conjunto1[i]);
}
printf("Entre o numero de elementos do conjunto 2: ");
scanf("%d", &num2);
printf("Entre os elementos do conjunto 2: ");
for(i=0; i<num2; i++){
    scanf("%d", &conjunto2[i]);
}

//o programa imprime os conjuntos sem elementos repetidos:
printf("\nConjunto 1 sem elementos repetidos:");
for(i=0; i<(remove_duplicados(conjunto1, num1, conjunto11)); i++){ //a condi��o do for ser uma fun��o � pq o retorno dessa fun��o � o numero de elementos do conjunto 1 sem elementos repetidos.
printf(" %d", conjunto11[i]); //impress�o do conjunto 1 sem elementos repetidos
}
printf("\nConjunto 2 sem elementos repetidos:");
for(i=0; i<(remove_duplicados(conjunto2, num2, conjunto22)); i++){
printf(" %d", conjunto22[i]);
}
//o programa imprime o conjunto intersec��o dos conjuntos:
printf("\n\nConjunto interesccao:");
for(i=0; i<(interseccao(conjunto11, remove_duplicados(conjunto1, num1, conjunto11), conjunto22, remove_duplicados(conjunto2, num2, conjunto22),intersec)); i++){ //a condi��o do for ser uma fun��o � pq o retorno dessa fun��o d� a quantidade de elementos do conjunto intersec��o. //as vezes em que aparece a fun��o "remove_duplicados" como par�metro da fun��o "intersec��o" � pq o retorno da "remove_duplicados" d� o valor de elementos do conjunto sem elementos repetidos.
printf(" %d", intersec[i]);
}

return 0;
}
