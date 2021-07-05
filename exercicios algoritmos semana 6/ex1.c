/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H
O programa deve ler uma cadeia de caracteres digitada pelo usuario, informar na tela quantas letras minusculas essa cadeia tem, em seguida ler 2 caracteres
e substituir o 1o pelo 2o na string digitada pelo usuario, apresentando a string modificada na tela.

Entradas: String, Caracter 1, Caracter 2
Saídas: Quantidade de letras minusculas, String modificada */


#include <stdio.h>

int main(){

char str[30] = {0};
char car1, car2;
int cont, letrasmin=0;


printf("Digite uma string: ");
fgets(str, 30, stdin);

for(cont=0; cont<30; cont++)
    if(str[cont]>=97 && str[cont]<=122)
        letrasmin++;

printf("A frase tem %d letras minusculas.", letrasmin);
printf("\nDigite o caracter original e o pelo qual vai ser substituido: ");
scanf(" %c %c", &car1, &car2);

for(cont=0; cont<30; cont++)
    if(str[cont]==car1)
        str[cont]=car2;


printf("String modificada trocando '%c' por '%c': %s", car1, car2, str);
return 0;
}
