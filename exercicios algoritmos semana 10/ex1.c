/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H.
O programa deve receber 1 string e 1 caractere, remover o caractere recebido da string e imprimir na tela a string sem o caractere e o n�mero de caracteres removidos.
Entradas: String 1, Caractere a ser removido.
Sa�das: String modificada(sem o caractere), n�mero de caracteres removidos.
*/
#include <stdio.h>
//declara��o da fun��o q elimina o caractere da string:
int elimina_caractere(char *str1, char *str2, char caracrem){ //a fun��o recebe o endere�o da string original e por "*str1" ser um ponteiro, tem acesso ao conteudo do endere�o da string original, o mesmo acontece com "*str2". "caracrem" � a variavel que armazena o caractere a ser removido.
int contcarac = 0; //inicializa o contador das vezes q o caractere foi removido como 0
while(*str1 != '\0'){ //repetir o la�o enquanto o conte�do da string for diferente do marcador de final padr�o das strings( "\0")
    if(*str1==caracrem){ //se o caractere da string original for igual ao caractere a ser removido
        contcarac++; //incremento em 1 a contagem de caracteres removidos
        str1++; //e pulo esse caractere da string original
    }else{ //se os caracteres forem diferentes, copio o caractere da string original para a modificada e incremento em 1 as 2 strings.
        *str2=*str1;
        str1++;
        str2++;
    }
}
return contcarac; //no final da fun��o, retorno o valor de caracteres removidos.
}


int main(){
char string[50]; //string original
char stringmod[50]; //string modificada
char crem; //variavel q armazena o caractere a ser removido

printf("Digite uma string: ");
fgets(string, 50, stdin); //leitura da string original
printf("Digite o caractere a ser removido da string: ");
scanf("%c", &crem); // leitura do caractere a ser removido
elimina_caractere(string, stringmod, crem); // chamo a fun��o para no printf abaixo ja poder mostrar a string modificada
printf("\nString modificada: %s", stringmod);
printf("Numero de caracteres '%c' removidos: %d", crem, elimina_caractere(string, stringmod, crem)); //imprimo o numero de caracteres removidos, que � o retorno da fun��o q elimina o caractere.

return 0;
}
