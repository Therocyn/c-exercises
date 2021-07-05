/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H.
O programa recebe os valores de numero de linhas e colunas de uma matriz, os valores da matriz, e em seguida pede para o usuario decidir qual norma matricial ele quer
que seja calculada entre a norma L-1, norma infinito e norma frobenius. Após informada, o programa calcula a norma desejada e apresenta o valor do calculo na tela.

Entradas: Numero de linhas, Numero de colunas, Valores da matriz.
Saidas: Valor calculado da norma desejada. */
#include <stdio.h>
#include <math.h>

int main(){

float somatorio=0, max, resulfinal;
int n, m, contlinha, contcoluna, norma;
float matriz[10] [10] = {0};

printf("Digite o numero de linhas e colunas(maximo 10 cada): ");
scanf(" %d %d", &n, &m);
while(n<1 || n>10){
    printf("Digite um numero valido de linhas: ");
    scanf(" %d", &n);
}
while(m<1 || m>10){
    printf("Digite um numero valido de colunas: ");
    scanf(" %d", &m);
}

for(contlinha=0; contlinha<n; contlinha++){
    printf("Digite os %d elementos da linha %d: ", m, contlinha+1);
    for(contcoluna=0; contcoluna<m; contcoluna++)
        scanf(" %f", &matriz[contlinha][contcoluna]);
    }

printf("\n\nNormas disponiveis:\n1- Norma L-1\n2- Norma L-infinito\n3- Norma Frobenius\nOpcao desejada (1-3): ");
scanf(" %d", &norma);

switch(norma)
    {
        case 1://Norma L-1: começo assumindo que o valor maximo(max) é o somatorio dos modulos dos valores da primeira coluna, e após isso faço a varredura das outras e comparo com a primeira.
            max=0;
            for(contlinha=0; contlinha<n; contlinha++)
                max=max+fabs(matriz[contlinha][0]);
            for(contcoluna=0; contcoluna<m; contcoluna++){
                somatorio=0;
                for(contlinha=0; contlinha<n; contlinha++)
                    somatorio=somatorio + fabs(matriz[contlinha][contcoluna]);
                if(somatorio>max)
                    max=somatorio;
                }
            resulfinal=max;
            break;

        case 2://Norma L-infinito: mesma coisa que na norma L-1, só que ao invés de usar as colunas, uso as linhas.
            max=0;
            for(contcoluna=0; contcoluna<m; contcoluna++)
                max=max+fabs(matriz[0][contcoluna]);
            for(contlinha=0; contlinha<n; contlinha++){
                somatorio=0;
                for(contcoluna=0; contcoluna<m; contcoluna++)
                    somatorio=somatorio + fabs( matriz[contlinha][contcoluna]);
                if(somatorio>max)
                    max=somatorio;
                }
            resulfinal=max;
            break;

        case 3:
            for(contlinha=0; contlinha<n; contlinha++)
                for(contcoluna=0; contcoluna<m; contcoluna++){
                    somatorio=somatorio + pow(matriz[contlinha][contcoluna], 2);
                    resulfinal=sqrt(somatorio);
                }
            break;
    }

printf("Resultado final: %.2f\n", resulfinal);

return 0;
}
