/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H.
O programa recebe a quantidade de elementos de 2 conjuntos, os elementos deles, e após isso imprime os conjuntos sem elementos repetidos e o conjunto intersecção dos 2. */
#include <stdio.h>
//declaração da função usada para remover elementos repetidos:
int remove_duplicados(int *vet_entrada, int n_entrada, int *vet_saida){ //"*vet_entrada" é a variavel do vetor original contendo elementos repetidos, "n_entrada" é o numero de elementos do conjunto original, "*vet_saida" é vetor do conjunto já sem elementos repetidos.
int n_saida=0; //variavel onde será armazenado o numero de elementos do vetor sem elementos repetidos.
int repete; // variavel q indica se um numero X é repetido ou não.
for(int i=0; i<n_entrada;i++){ //o laço percorre em primeiro plano o vetor original
        repete=0; //para cada iteração no vetor original iniciamos a variavel que armazena se o número é repetido ou não como 0.
        for(int j=0; j<n_saida; j++){ //percorremos o vetor de saida até o elemento "n_saida" atual do vetor de saida.
            if(*(vet_entrada+i)== *(vet_saida+j)){ //se o vetor de entrada em um indice "i" qualquer tiver valor igual já armazenado em um indice "j" qualquer do vetor de saida, a variavel "repete" é incrementada em 1, de forma a mostrar que aquele elemento já existe no vetor de saida.
                repete++;
            }
        }
        if(repete==0){ //se o vetor de saida é percorrido e não é encontrado nenhum elemento igual ao da iteração "i" do vetor de entrada, a variavel "repete" se mantém em 0
            *(vet_saida+n_saida)=*(vet_entrada+i); //é passado o valor do vetor de entrada para o vetor de saida.
            n_saida++; // e é incrementado o numero de elementos do vetor de saida em 1.
        }
    }

return n_saida; //o programa retorna o número de elementos final do conjunto sem elementos repetidos.
}
//declaração da função usada para fazer a intersecção de dois conjuntos:
int interseccao(int *vet1, int num1, int *vet2, int num2, int *intersec){ //"*vet1" é o conjunto 1 já sem elementos repetidos, "num1" é o numero de elementos do conjunto 1, "*vet2" é o conjunto 2 já sem elementos repetidos, "num2" é o numero de elementos do conjunto 2, "*intersec* é vetor no programa principal que será transformado no conjunto intersecção.
int n_saida=0; //variavel em que será armazenado o numero de elementos do conjunto intersecção.
for(int i=0; i<num1; i++){ //percorremos o conjunto 1

    for(int j=0; j<num2; j++){//para cada iteração onde percorremos o conjunto 1, percorremos o conjunto 2 inteiro.
        if(*(vet1+i)==*(vet2+j)){ //se algum elemento do conjunto 2 for igual ao do conjunto 1 naquela iteração, o valor é passado para o conjunto intersecção e é incrementado em 1 o indice da intersecção, de forma a ir para o proximo elemento pois já sabemos que nos conjuntos não temos nenhum elemento duplicado.
            *(intersec+n_saida)=*(vet1+i);
            n_saida++;
        }
    }
}
return n_saida;//a função retorna o número de elementos final do conjunto intersecção
}


int main(){
#define TAM_MAX_VET 15
//vetor que armazena o conjunto 1 c/ elementos repetidos:       //vetor que armazena o conjunto 2 c/ elementos repetidos:       //vetor que armazena o conjunto 1 SEM elementos repetidos:      //vetor que armazena o conjunto 2 SEM elementos repetidos:              //vetor intersecção dos conjuntos 1 e 2:
            int conjunto1[TAM_MAX_VET],                                 conjunto2[TAM_MAX_VET],                                       conjunto11[TAM_MAX_VET],                                      conjunto22[TAM_MAX_VET],                                                intersec[TAM_MAX_VET];
int num1, num2; //"num1" é o numero de elementos do conjunto 1, "num2" é o numero de elementos do conjunto 2
int i; //variavel usada para percorrer o indice dos vetores na impressão e leitura dos elementos

//o programa pede para que o usuário digite a quantidade de elementos dos conjuntos e os elementos deles:
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
for(i=0; i<(remove_duplicados(conjunto1, num1, conjunto11)); i++){ //a condição do for ser uma função é pq o retorno dessa função é o numero de elementos do conjunto 1 sem elementos repetidos.
printf(" %d", conjunto11[i]); //impressão do conjunto 1 sem elementos repetidos
}
printf("\nConjunto 2 sem elementos repetidos:");
for(i=0; i<(remove_duplicados(conjunto2, num2, conjunto22)); i++){
printf(" %d", conjunto22[i]);
}
//o programa imprime o conjunto intersecção dos conjuntos:
printf("\n\nConjunto interesccao:");
for(i=0; i<(interseccao(conjunto11, remove_duplicados(conjunto1, num1, conjunto11), conjunto22, remove_duplicados(conjunto2, num2, conjunto22),intersec)); i++){ //a condição do for ser uma função é pq o retorno dessa função dá a quantidade de elementos do conjunto intersecção. //as vezes em que aparece a função "remove_duplicados" como parâmetro da função "intersecção" é pq o retorno da "remove_duplicados" dá o valor de elementos do conjunto sem elementos repetidos.
printf(" %d", intersec[i]);
}

return 0;
}
