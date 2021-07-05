/*Vitor Simon de Souza, 00325102 - Engenharia de Controle e Automação, Turma H. O programa deve abrir, ler e imprimir os highscores de um documento com o nome digitado pelo usuario, receber um novo score de um jogador, e se a
pontuação do jogador tiver entre as 5 maiores, adicionar ao ranking de highscores, imprimir o ranking atualizado e perguntar o nome do arquivo em que vai ser salvo o ranking atualizado.
Entradas: nome do arquivo base, nome e score do jogador, nome do arquivo de saida.
Saídas: a tabela com os highscores, o arquivo novo com o ranking atualizado.
*/

#include <stdio.h>
#include <string.h>

typedef struct tipo_jogador //definição da estrutura de highscores dada no exercicio
{
    char nome[40];
    int score;
} TIPO_JOGADOR;


int le_arquivo(char *nome_arquivo, TIPO_JOGADOR *arranjo)  //a função recebe o ponteiro que aponta para a string que indica o nome do arquivo base e recebe tbm o ponteiro do arranjo de estruturas em que será armazenado o conteudo do arquivo.
{
    FILE *arquivo; //declaração do ponteiro do arquivo
    int i=0; //variavel para contar a quantidade de dados realmente lidos

    arquivo=fopen(nome_arquivo, "rb"); //abertura do arquivo em modo leitura
    if(arquivo == NULL)  //se a abertura devolver null, algo deu errado então imprimir que deu um erro ao abrir o arquivo na tela e retornar -1.
    {
        printf("Erro ao abrir o arquivo!");
        return -1;
    }
    else   //se deu tudo certo
    {
        while(fread(arranjo+i, sizeof(TIPO_JOGADOR), 1, arquivo) == 1 )  //ler e armazenar no arranjo de estruturas a quantidade de dados lidos
        {
            i++; //ao mesmo tempo que essa variavel age como indice do armazenamento no arranjo, ela tb serve para indicar a quantidade de dados realmente lidos.
        }
    }
    fclose(arquivo); //fechamento do arquivo
    return i; //retorna o numero de dados lidos se deu tudo certo.
}

void imprime_scores(TIPO_JOGADOR *jogadores, int num_elementos)  //a função recebe o ponteiro do vetor de estruturas que indica cada jogador e o numero de jogadores
{
    printf("Nome:                    Score:\n");
    for(int i=0; i<num_elementos; i++)  //laço para imprimir os dados de nome e score de cada jogador
    {
        for(int i2=0; ((*(jogadores+i)).nome[i2])!='\0'; i2++)  //mas antes de imprimir, eu uso esse laço para retirar o "\n" que o fgets lê no final da string para poder imprimir todos os nomes na mesma linha dos scores
        {
            if((*(jogadores+i)).nome[i2] == '\n' )  //se for encontrado algum "\n" nas strings de nome, o programa substitui por "\0" antes de imprimir a string
            {
                (*(jogadores+i)).nome[i2] = '\0';
            }
        }
        printf("%-25s%-10d\n", (*(jogadores+i)).nome, (*(jogadores+i)).score); //impressão do nome e score
    }
}




char insere_score(TIPO_JOGADOR nova_entrada, TIPO_JOGADOR *arranjo)  //a função recebe a entrada do novo nome e score do jogador e o arranjo onde esta armazenada a tabela de highscores
{
    int flag=0; //essa variavel serve para indicar quando e se for encontrada um score que entre entre os highscores.
    TIPO_JOGADOR aux; //estrutura auxiliar para ajudar na organização da tabela

    for(int i=0; i<5; i++)
    {
        if( (*(arranjo+i)).score < nova_entrada.score )  //se para algum score da tabela, o score de entrada for maior
        {
            flag=1; // a flag vai se tornar 1, indicando que existe um score maior q algum da tabela
        }
        if(flag == 1)  //se tiver um score maior q o da tabela
        {
            strcpy(aux.nome, (*(arranjo+i)).nome); //copio o nome e score da posição q é menor para a estrutura auxiliar
            aux.score=(*(arranjo+i)).score;

            strcpy((*(arranjo+i)).nome, nova_entrada.nome); //coloco no lugar a estrutura nova q é maior q a anterior
            (*(arranjo+i)).score=nova_entrada.score;
            for(int i2=4; i2>i; i2--)  //e para todos os scores abaixo dela, é como se eu empurrasse eles para baixo na tabela de maneira decrescente
            {
                strcpy((*(arranjo+i2+1)).nome, (*(arranjo+i2)).nome); //copio os dados do penultimo lugar e coloco no ultimo lugar da tabela
                (*(arranjo+i2+1)).score= (*(arranjo+i2)).score;
            }
            strcpy((*(arranjo+i+1)).nome, aux.nome); //no lugar do jogador q fica abaixo do que entrou na tabela agr ficará um repetido, então pego e coloco no lugar dele o que estava no lugar do player novo
            (*(arranjo+i+1)).score=aux.score;
            i=5; //coloco a variavel q percorre os arranjos como 5 para sair do laço
        }
    }
    if(flag==1) //se foi encontrado algum jogador com dado q entra na tabela, a flag em 1 indica isso
        return 's';
    else//senao retorna n
        return 'n';
}

void escreve_arquivo(char *nome_arquivo, TIPO_JOGADOR *arranjo, int num)  // a função recebe o ponteiro para o nome do arquivo novo, o arranjo de estruturas com a tabela atualizada e o numero de jogadores efetivamente lidos
{
    FILE *nomearq; //declaracao do ponteiro do arquivo
    nomearq=fopen(nome_arquivo, "wb"); //abertura do arquivo
    if(nomearq == NULL)  //se ao ser aberto o arquivo der erro, vai aparecer aqui pq o retorno da abertura vai ser null
    {
        printf("Erro ao abrir o arquivo!");
    }
    else
    {
        for(int i=0; i<num; i++)  //se der td certo, escrevo os dados no arquivo novo
        {
            fwrite((arranjo+i), sizeof(TIPO_JOGADOR), 1, nomearq);
        }
    }
    fclose(nomearq); //fecho o arquivo
}


int main()
{

    char nome_arquivo[20], nome_arquivosaida[20]; //strings dos arquivos de base e novo
    TIPO_JOGADOR dadosplayers[5]; //o arranjo de estruturas onde ficará a tabela
    TIPO_JOGADOR nova_entrada; //estrutura da entrada do novo jogador
    int lidos; //variavel q indica quantos dados foram lidos
    printf("Digite o nome do arquivo: ");
    fflush(stdin);
    fgets(nome_arquivo, 20, stdin); //o programa le o nome do arquivo de base
    if(nome_arquivo[(strlen(nome_arquivo)-1)]=='\n')
        nome_arquivo[(strlen(nome_arquivo)-1)] = '\0'; //retira o \n do final da string dele


    lidos = le_arquivo(nome_arquivo, dadosplayers); //chama a função da leitura do arquivo e armazena em "lidos" quantos dados foram efetivamente lidos
    if(lidos == -1){
        return 0;
    }
    imprime_scores(dadosplayers, lidos); //imprime a tabela

    printf("Digite o nome do player: ");
    fflush(stdin);
    fgets(nova_entrada.nome, 40, stdin); //recebe os dados do novo jogador
    printf("Digite o score: ");
    fflush(stdin);
    scanf(" %d", &nova_entrada.score);

    if(insere_score(nova_entrada, dadosplayers)== 's')  //se o novo jogador estiver entre os highscores
    {
        printf("\nRanking atualizado:\n");
        imprime_scores(dadosplayers, lidos); //imprimo a tabela atualizada

        printf("Nome do arquivo com a versao do ranking atualizado: ");
        fflush(stdin);
        fgets(nome_arquivosaida, 20, stdin);  //peço um nome para o arquivo de saida com a tabela atualizada
        if(nome_arquivosaida[(strlen(nome_arquivosaida)-1)]=='\n')
            nome_arquivosaida[(strlen(nome_arquivosaida)-1)] = '\0'; //retiro o \n do nome



        escreve_arquivo(nome_arquivosaida, dadosplayers, lidos); //chamo a função para escrever no arquivo de saida

    }
    return 0;
}
