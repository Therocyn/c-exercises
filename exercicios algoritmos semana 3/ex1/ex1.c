/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H
o programa l� um n�mero inteiro de 2 digitos entre 20 e 99 e imprime na tela o n�mero por extenso e a m�dia geom�trica dos algarismos
entradas: o n�mero
sa�das: o n�mero por extenso e a m�dia geom�trica dos dois algarismos
*/
#include <stdio.h>
#include <math.h>

int main(){

//declara��o das vari�veis
int numero;
int d1;
int d2;
float mediageo;

//o programa pede ao usu�rio que digite o n�mero
printf("Digite um numero inteiro dentro do intervalo de 20 a 99: ");
scanf("%d", &numero);

//se o n�mero digitado for maior que 99 ou menor que 20, o programa entra no la�o do comando "for" at� que o usu�rio digite um n�mero dentro do intervalo de 20 � 99
for(numero; numero<20 || numero>99;){
    printf("Numero invalido, digite um numero dentro do intervalo de 20 a 99:");
    scanf("%d", &numero);
}

//separa��o dos algarismos do n�mero digitado:
d1= numero/10;
d2= numero%10;

/*aqui ocorre a impress�o do n�mero por extenso, onde � verificado o primeiroalgarismo do n�mero e � feita a impress�o por extenso de sua parte correspondente.
Em seguida, � feita a verifica��o do segundo algarismo e impressa sua parte correspondente do n�mero */
switch(d1){
case 2:
    printf("Numero por extenso: Vinte ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
case 3:
    printf("11Numero por extenso: Trinta ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
case 4:
    printf("Numero por extenso: Quarenta ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
case 5:
    printf("Numero por extenso: Cinquenta ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
case 6:
    printf("Numero por extenso: Sessenta ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
case 7:
    printf("Numero por extenso: Setenta ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
case 8:
    printf("Numero por extenso: Oitenta ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
case 9:
    printf("Numero por extenso: Noventa ");

    switch(d2){

    case 0:
    break;

    case 1: printf("e um");
    break;

    case 2: printf("e dois");
    break;

    case 3: printf("e tres");
    break;

    case 4: printf("e quatro");
    break;

    case 5: printf("e cinco");
    break;

    case 6: printf("e seis");
    break;

    case 7: printf("e sete");
    break;

    case 8: printf("e oito");
    break;

    case 9: printf("e nove");
    break;
    }
break;
}

//aqui � feita a m�dia geom�trica dos algarismos e � impresso na tela o seu valor
mediageo = sqrt(d1*d2);
printf("\nA media geometrica entre os algarismos eh: %.2f\n", mediageo);

return 0;
}
