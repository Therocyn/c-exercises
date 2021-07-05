/* Vitor Simon de Souza, 00325102 - Eng. de controle e automação, turma H.
O programa deve ler 1 valor real, a operação a ser feita(+,-,* ou /) e realizar a operação com o próximo número lido,
assim consecutivamente até o usúario informar a operação "=", então o valor total calculado será informado na tela. */
#include <stdio.h>

int main(){

float valor1; //variaveis para o primeiro
float valor2; //e segundo valor
float operacaototal=0; //variavel que informa o valor total calculado no final do programa sendo iniciada como "0" por motivos de coerencia do programa.
float valoperacao; //variavel auxiliar para realização dos calculos
char operacao; //variavel onde fica armazenada a operação a ser realizada com os números
int continuar; //variavel usada para interromper o laço do while quando o usúario digitar "="

 //o programa pede para que o usuario digite o primeiro valor
 printf("Digite o valor: ");
 scanf(" %f", &valor1);
do{
 //já dentro do laço "do-while" o programa pede para que o usuario digite a operação a ser feita
 printf("Digite a operacao: ");
 scanf(" %c", &operacao);
 //se a operação for "=", o programa altera a variável continuar para "0", fazendo com que o programa saia do laço e exiba o resultado.
 if(operacao=='=')
    continuar=0;
//senão ele pede o segundo valor e realiza a operação, tudo isso infinitas vezes até que o usuário digite "=" como operação
else{
 printf("Digite o valor: ");
 scanf(" %f", &valor2);

 //aqui o programa analisa qual operação vai ser realizada entre os números:
  switch(operacao)
    {
    case '+':
        valoperacao=valor1+valor2;
        operacaototal=operacaototal+valoperacao;
        valor1=0;
        break;
    case '-':
        valoperacao=valor1-valor2;
        operacaototal=operacaototal+valoperacao;
        valor1=0;
        break;
    case '*':
        if(operacaototal == 0){ //quando a variavel operacaototal é igual a 0 quer dizer que o programa n realizou nenhuma outra operação anteriormente ou que a operação anterior resultou em 0,
        operacaototal=1;        //e com as outras operações retornando valor1=0 isso faz com que igualar operacaototal=1 nesses casos matenha o resultado do calculo "correto"
        valoperacao=valor1*valor2;
        operacaototal=operacaototal*valoperacao;
        valor1=0;
        }else{ //se o operacaototal for diferente de 0, mostrando que o programa já realizou outras operações, ele só calcula a multiplicação do resultado anterior pelo valor requisitado
        operacaototal=operacaototal*valor2;
        valor1=0;
        }
        break;
    case '/':
        if(operacaototal == 0){ //a lógica do if-else aqui é praticamente a mesma que na multiplicação.
        operacaototal=1;
        valoperacao=valor1/valor2;
        operacaototal=valoperacao/operacaototal;
        valor1=0;
        }else{
        operacaototal=operacaototal/valor2;
        valor1=0;
        }
        break;
    }
}
}while(continuar != 0); //quando o usuário digitar "=" para a operação, o programa sai da laço e e informa o valor total calculado das operações
printf("O valor total calculado e: %f", operacaototal);
return 0;
}
