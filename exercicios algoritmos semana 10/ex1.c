/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automação, Turma H.
O programa deve receber 1 string e 1 caractere, remover o caractere recebido da string e imprimir na tela a string sem o caractere e o número de caracteres removidos.
Entradas: String 1, Caractere a ser removido.
Saídas: String modificada(sem o caractere), número de caracteres removidos.
*/
#include <stdio.h>
//declaração da função q elimina o caractere da string:
int elimina_caractere(char *str1, char *str2, char caracrem){ //a função recebe o endereço da string original e por "*str1" ser um ponteiro, tem acesso ao conteudo do endereço da string original, o mesmo acontece com "*str2". "caracrem" é a variavel que armazena o caractere a ser removido.
int contcarac = 0; //inicializa o contador das vezes q o caractere foi removido como 0
while(*str1 != '\0'){ //repetir o laço enquanto o conteúdo da string for diferente do marcador de final padrão das strings( "\0")
    if(*str1==caracrem){ //se o caractere da string original for igual ao caractere a ser removido
        contcarac++; //incremento em 1 a contagem de caracteres removidos
        str1++; //e pulo esse caractere da string original
    }else{ //se os caracteres forem diferentes, copio o caractere da string original para a modificada e incremento em 1 as 2 strings.
        *str2=*str1;
        str1++;
        str2++;
    }
}
return contcarac; //no final da função, retorno o valor de caracteres removidos.
}


int main(){
char string[50]; //string original
char stringmod[50]; //string modificada
char crem; //variavel q armazena o caractere a ser removido

printf("Digite uma string: ");
fgets(string, 50, stdin); //leitura da string original
printf("Digite o caractere a ser removido da string: ");
scanf("%c", &crem); // leitura do caractere a ser removido
elimina_caractere(string, stringmod, crem); // chamo a função para no printf abaixo ja poder mostrar a string modificada
printf("\nString modificada: %s", stringmod);
printf("Numero de caracteres '%c' removidos: %d", crem, elimina_caractere(string, stringmod, crem)); //imprimo o numero de caracteres removidos, que é o retorno da função q elimina o caractere.

return 0;
}
