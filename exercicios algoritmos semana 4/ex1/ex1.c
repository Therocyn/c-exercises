/* Vitor Simon de Souza, 00325102 - Eng. de controle e automa��o, turma H.
O programa deve ler 1 valor real, a opera��o a ser feita(+,-,* ou /) e realizar a opera��o com o pr�ximo n�mero lido,
assim consecutivamente at� o us�ario informar a opera��o "=", ent�o o valor total calculado ser� informado na tela. */
#include <stdio.h>

int main(){

float valor1; //variaveis para o primeiro
float valor2; //e segundo valor
float operacaototal=0; //variavel que informa o valor total calculado no final do programa sendo iniciada como "0" por motivos de coerencia do programa.
float valoperacao; //variavel auxiliar para realiza��o dos calculos
char operacao; //variavel onde fica armazenada a opera��o a ser realizada com os n�meros
int continuar; //variavel usada para interromper o la�o do while quando o us�ario digitar "="

 //o programa pede para que o usuario digite o primeiro valor
 printf("Digite o valor: ");
 scanf(" %f", &valor1);
do{
 //j� dentro do la�o "do-while" o programa pede para que o usuario digite a opera��o a ser feita
 printf("Digite a operacao: ");
 scanf(" %c", &operacao);
 //se a opera��o for "=", o programa altera a vari�vel continuar para "0", fazendo com que o programa saia do la�o e exiba o resultado.
 if(operacao=='=')
    continuar=0;
//sen�o ele pede o segundo valor e realiza a opera��o, tudo isso infinitas vezes at� que o usu�rio digite "=" como opera��o
else{
 printf("Digite o valor: ");
 scanf(" %f", &valor2);

 //aqui o programa analisa qual opera��o vai ser realizada entre os n�meros:
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
        if(operacaototal == 0){ //quando a variavel operacaototal � igual a 0 quer dizer que o programa n realizou nenhuma outra opera��o anteriormente ou que a opera��o anterior resultou em 0,
        operacaototal=1;        //e com as outras opera��es retornando valor1=0 isso faz com que igualar operacaototal=1 nesses casos matenha o resultado do calculo "correto"
        valoperacao=valor1*valor2;
        operacaototal=operacaototal*valoperacao;
        valor1=0;
        }else{ //se o operacaototal for diferente de 0, mostrando que o programa j� realizou outras opera��es, ele s� calcula a multiplica��o do resultado anterior pelo valor requisitado
        operacaototal=operacaototal*valor2;
        valor1=0;
        }
        break;
    case '/':
        if(operacaototal == 0){ //a l�gica do if-else aqui � praticamente a mesma que na multiplica��o.
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
}while(continuar != 0); //quando o usu�rio digitar "=" para a opera��o, o programa sai da la�o e e informa o valor total calculado das opera��es
printf("O valor total calculado e: %f", operacaototal);
return 0;
}
