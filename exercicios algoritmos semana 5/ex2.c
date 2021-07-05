/* Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H.
O programa l� a quantidade de bins(max 10) no intervalo de 0 � 1, valores reais de 0 � 1, e ap�s isso imprime na tela em quais bins esses valores est�o.
Entrada: Quantidade de bins, n�meros reais de 0 � 1.
Sa�da: Quantidade de elementos em cada bin.
*/
#include <stdio.h>

int main(){


int array[10]={0}; //esse vetor � usado para contabilizar a quantidade de elementos no bin designado pela variavel "cont"
int cont; //qual bin est�
float bins; //quantidade de bins
float val=1;

//variaveis auxiliares usadas para limitar o periodo de cada bin:
float auxbin;
float aux2bin;

printf("Digite o numero de bins(maximo 10): "); //o programa l� a quantidade de bins digitada pelo usu�rio e checa se o valor � menor que 10
scanf("%f", &bins);
while(bins>10){
    printf("Digite uma quantidade de bins valida: ");
    scanf("%f", &bins);
}

while(val>0 && val<=1){ //aqui ocorre a leitura dos valores reais digitados pelo usu�rio enquanto os valores forem menores ou iguais a 1 e maiores que 0
    printf("Digite um valor real de 0 a 1: ");
    scanf("%f", &val);

    for(cont=0; cont<bins; cont++){  //esse la�o faz a varredura de em qual bin o valor digitado est�
      auxbin=cont/bins; //limite inferior do bin
      aux2bin=(cont+1)/bins; //limite superior do bin
      if(auxbin<val && aux2bin>=val){ //se o valor estiver entre o limite inferior e o superior, a variavel daquele bin � incrementada em +1
        array[cont]++;
      }
    }
}

for(cont=0; cont<bins; cont++){ //aqui � impressa na tela a quantidade de elementos por bin
    printf("Bin %d tem %d elementos\n", cont, array[cont]);
}
return 0;
}
