/*Vitor Simon de Souza, 00325102 - Eng. de Controle e Automa��o, Turma H. O programa deve receber a matriz 4x8 em formato txt do arqueiro, salvar uma c�pia em disco com um nome
escolhido pelo usu�rio, criar um novo "desenho" para o arqueiro feito pelo usu�rio e salvar esse novo arqueiro em disco com um nome tbm escolhido pelo usu�rio.
Entradas: nome do arquivo do arqueiro base, nome para a c�pia do arqueiro base, desenho do arqueiro novo, nome para o arquivo do arqueiro novo
Sa�das: copia do arqueiro base, arquivo com o arqueiro novo*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_arqueiro(FILE *arq, char *arqueiro) //essa fun��o recebe o ponteiro para o arquivo do arqueiro base e a matriz em que dever� preencher e devolve a matriz preenchida
{
    int i=0; //i � uma variavel que serve para mudar o indice de linhas na leitura do arquivo
    char aux[4][10]; //matriz auxiliar para armazenar os dados do arquivo

    while(fgets(&aux[i][0], 10, arq )!=0 ) //enquanto ainda tiverem linhas a serem lidas a itera��o ir� se repetir
    {
        i++; // incremento em +1 para realizar a mudan�a de linhas na leitura
    }
    for(int i2=0; i2<4; i2++) //esses 2 for servem para percorrer a matriz auxiliar enquanto devolve os dados para a matriz principal na fun��o main
    {
        for(int i3=0; i3<8; i3++)
        {
            *(arqueiro+i2*8+i3) = aux[i2][i3]; //passagem dos dados da matriz auxiliar para a principal
        }
    }
}

void escreve_arqueiro(char *nome_arq, char *arqueiro) //a fun��o recebe o nome do arquivo que dever� ser salva a matriz e a matriz tbm. A partir desses 2 parametros ela realiza o salvamento do arquivo.
{
    FILE *arquivo; //ponteiro para o arquivo

    arquivo = fopen(nome_arq, "w"); //abertura do arquivo
    if(arquivo == NULL) //verifica��o se a abertura foi realizada corretamente
    {
        printf("Erro ao abrir o arquivo de saida!");
    }
    else //se a abertura foi realizada corretamente sera realizada a impress�o da matriz no arquivo
    {

        for(int i=0; i<4; i++)
        {
            fwrite(arqueiro+i*8, 1, 8, arquivo); //nesse fwrite eu estou salvando por linhas, onde i � a linha q esta sendo salva as 8 colunas
            if(i<3)
                fwrite("\n", 1, 1, arquivo); //pra cada linha eu dou um \n no final dela p ir pra proxima
        }
    }
    fclose(arquivo); //fecho o arquivo no final
}

void preenche_arqueiro(char *arqueiro) //essa fun��o preenche a matriz e devolve ela preenchida pra fun��o main
{
    int flag; //variavel usada para saber se uma condi��o � preenchida
    char aux[4][10]; //declara��o de uma matriz auxiliar para preenchimento

    for(int i=0; i<4; i++)//for para percorrer o numero de linhas da matriz
    {
        fflush(stdin);
        fgets(&aux[i][0], 10, stdin); //fgets pra preencher a linha "i"

        if(aux[i][8] != '\n' ) //se a penultima coluna da matriz n�o for um \n isso quer dizer que a coluna foi preenchida com dados a mais ou a menos do que o esperado
        {
            flag=0; //inicio como 0 a variavel q � usada para procurar onde est�o as colunas n�o preenchidas
            for(int i2=0; i2<10; i2++) //for usado para percorrer as colunas da linha que n�o foi preenchida corretamente
            {
                if( aux[i][i2] == '\0' ) //quando for encontrada a coluna em que est� o "\0" saberemos at� onde a coluna foi preenchida corretamente
                {
                    flag=1; //coloco a variavel em 1 para indicar que � na coluna "i2" em que foi encontrado o "\0"
                }
                if(flag==1) //e a partir da coluna anterior a ela, q � onde ficaria o "\n", eu preencho com espa�os at� o final
                {
                    aux[i][i2-1] = ' ';
                }
            }
        }
    }
    for(int i2=0; i2<4; i2++) //ap�s isso s�o usados esses 2 for para realizar a passagem da matriz auxiliar para a principal
    {
        for(int i3=0; i3<8; i3++)
        {
            *(arqueiro+i2*8+i3) = aux[i2][i3]; //passagem dos caracteres
        }
    }
}


int main()
{

    char nomearq[50], nomearq2[50], nomearq3[50], matriz[4][8]; //variaveis usadas para armazenar o nome do arquivo do arqueiro base, a c�pia, o nome do arquivo do novo arqueiro, e por fim a matriz em que ser� copiado o arqueiro
    FILE *arquivo; //ponteiro para o arquivo

    printf("Digite o nome do arquivo de entrada: ");
    fflush(stdin);
    fgets(nomearq, 50, stdin); //digita��o do nome do arquivo q contem a matriz do arqueiro
    if(nomearq[strlen(nomearq)-1] == '\n')
        nomearq[strlen(nomearq)-1] = '\0'; //retirada do "\n" da string do nome do arquivo de entrada

    arquivo = fopen(nomearq, "r"); //abertura do arquivo
    if(arquivo == NULL) //se a abertura do arquivo der errado
    {
        printf("Erro ao abrir o arquivo de entrada!"); //imprimo uma mensagem de erro
        return 1; //e encerro o programa
    }
    else //mas se der certo, sigo o programa normalmente
    {

        le_arqueiro(arquivo, matriz[0]); //chamo a fun��o le_arqueiro usando como parametros o ponteiro para o arquivo do arqueiro base e a matriz em que ele dever� ser copiado
    }
    fclose(arquivo); //fecho o arquivo

    printf("Digite o nome do arquivo de saida: ");
    fflush(stdin);
    fgets(nomearq2, 50, stdin); //digita��o do nome do arquivo de saida que ser� a c�pia do arqueiro base
    if(nomearq2[strlen(nomearq2)-1] == '\n')
        nomearq2[strlen(nomearq2)-1] = '\0'; //retirada do "\n" da string do nome do arquivo de saida

    escreve_arqueiro(nomearq2, matriz[0]); //chamo a fun��o escreve_arqueiro para salvar a copia do arqueiro usando como parametros os ponteiros do nome do arquivo da c�pia e a matriz em que o arqueiro base est�


    printf("\nDesenhe o novo arqueiro:\n");
    preenche_arqueiro(matriz[0]); //chamo a fun��o para desenhar o modelo do novo arqueiro usando como parametro a matriz em que ele ser� salvo

    printf("\nDigite o nome do arquivo do novo arqueiro: ");
    fflush(stdin);
    fgets(nomearq3, 50, stdin); //recebo o nome do arquivo em q ser� salvo o novo arqueiro
    if(nomearq3[strlen(nomearq3)-1] == '\n')
        nomearq3[strlen(nomearq3)-1] = '\0'; //retirada do "\n" da string do nome do arquivo de saida

    escreve_arqueiro(nomearq3, matriz[0]); //chamo a fun��o escreve_arqueiro dnv para salvar o novo modelo do arqueiro.

    return 0;
}
