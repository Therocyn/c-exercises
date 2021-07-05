/*Vitor Simon de Souza, 00325102 - Engenharia de Controle e Automa��o, Turma H. O programa deve receber nome e score dos jogadores at� um maximo estabelecido ou at� o usuario pressionar enter na linha de digita��o do nome do jogador.
A partir disso, o programa deve imprimir os nomes e pontua��es, ordenar de maneira decrescente com rela��o as pontua��es e imprimir de novo na tela os nomes e pontua��es j� ordenados.

Entradas: nomes e pontua��es
Sa�das: tabela de pontua��es antes de ser ordenada e depois de ser ordenada
*/
#include <stdio.h>
#include <string.h>
#define MAXSCORE 5 //numero maximo de jogadores/scores que o programa pode receber

typedef struct tipo_jogador //estrutura de jogadores contendo nome e score.
{
    char nome[40];
    int score;
} TIPO_JOGADOR; //o sinonimo da estrutura ser�: TIPO_JOGADOR

int preenche_scores(TIPO_JOGADOR *jogadores){ //a fun��o recebe o ponteiro do vetor de estruturas que indica cada jogador
int cont=0; //variavel que contabiliza o numero de jogadores realmente contabilizados
for(int i=0; i<MAXSCORE; i++){ //enquanto "i" for menor que o maximo de jogadores, o programa receber� os dados de nome e score para cada jogador.
printf("Digite o nome do jogador: ");
fflush(stdin); //limpo o buffer antes do fgets pq sen�o o enter do score da itera��o anterior faz com que o programa saia do la�o
fgets( (*(jogadores+i)).nome, 40, stdin); //leitura da string do nome e armazenamento dela no vetor de jogador de indice "i" e campo "nome" que � a string onde ela vai ficar
if(jogadores[i].nome[0] == '\n') //se o usuario pressionar enter na tela de digita��o do nome
    i=MAXSCORE; // o programa ir� setar a variavel "i" com o valor maximo de jogadores para sair do la�o e parar de receber nomes e scores
if(i<MAXSCORE){ //se o enter n�o for pressionado na 1a coluna do campo de nome o programa ir� receber o valor de score normalmente.
    printf("Digite o score: ");
    scanf("%d", &jogadores[i].score);
    cont++; //para cada score recebido, o programa incrementa "cont" em +1 pq aqui temos o real numero de jogadores e suas pontua��es
}
}
return cont; //a fun��o retorna a quantidade de jogadores que tiveram seus scores e nomes submetidos ao programa
}

void ordena_scores(TIPO_JOGADOR *jogadores, int num_elementos){ //a fun��o recebe o ponteiro do vetor de estruturas que indica cada jogador e o numero de jogadores
int maiorscore; //variavel em q � indexado a maior pontua��o/score.
char stringaux[40]; //string auxiliar para ajudar na troca de lugar na hora do ordenamento
int scoreaux;//variavel para armazenar o score auxiliar para ajudar na troca de lugar na hora do ordenamento

for(int i=0; i<num_elementos;i++){ //la�o para percorrer o vetor no campo de scores
    maiorscore=(*(jogadores+i)).score; //come�o assimilando meu primeiro valor como o maior score
    for(int i2=i+1; i2<num_elementos; i2++){ //para cada "i" indice do vetor, eu percorro o resto dele inteiro com a variavel "i2" comparando para ver se n�o tem algum valor maior q ele
        if((*(jogadores+i2)).score > maiorscore){ //se eu encontrar um outro score maior que o que foi assumido como maior
            maiorscore= (*(jogadores+i2)).score; // eu transfiro esse valor para ele passar a ser o maior
        }
        if(maiorscore != (*(jogadores+i)).score){ //e se eu identificar q o maior � diferente do que foi definido no "maiorscore" inicial, � sinal de que no "if" anterior foi encontrado um valor maior q o inicial
            strcpy(stringaux, (*(jogadores+i)).nome); //ent�o eu passo o nome e score do inicial pra uma variavel auxiliar
            scoreaux= (*(jogadores+i)).score;

            strcpy((*(jogadores+i)).nome, (*(jogadores+i2)).nome); //passo o nome e valor do maior score encontrado para o lugar onde era o inicial
            (*(jogadores+i)).score=maiorscore;

            strcpy((*(jogadores+i2)).nome, stringaux); //e passo o nome e score do inicial para onde estava o que � maior q ele. Dessa forma, resumidamente troco de lugar o jogador com o score menor pelo jogador com score maior
            (*(jogadores+i2)).score= scoreaux;
        }
    }
}
}

void imprime_scores(TIPO_JOGADOR *jogadores, int num_elementos){ //a fun��o recebe o ponteiro do vetor de estruturas que indica cada jogador e o numero de jogadores
printf("Nome:                    Score:\n");
for(int i=0; i<num_elementos; i++){ //la�o para imprimir os dados de nome e score de cada jogador
    for(int i2=0; ((*(jogadores+i)).nome[i2])!='\0'; i2++){ //mas antes de imprimir, eu uso esse la�o para retirar o "\n" que o fgets l� no final da string para poder imprimir todos os nomes na mesma linha dos scores
        if((*(jogadores+i)).nome[i2] == '\n' ){ //se for encontrado algum "\n" nas strings de nome, o programa substitui por "\0" antes de imprimir a string
            (*(jogadores+i)).nome[i2] = '\0';
        }
    }
    printf("%-25s%-10d\n", (*(jogadores+i)).nome, (*(jogadores+i)).score); //impress�o do nome e score
}
}


int main(){
int nest; //variavel em que � armazenado o numero de jogadores q tiveram seus dados submetidos ao programa
TIPO_JOGADOR jogadores[MAXSCORE]; //difini��o do vetor em que teremos os jogadores e seus dados

nest=preenche_scores(jogadores); //como a fun��o "preenche_scores" retorna o valor de jogadores efetivos que digitaram seus dados, eu armazeno esse dado na variavel criada p isso
printf("\nScores lidos:\n");
imprime_scores(jogadores, nest); //impress�o dos scores antes do ordenamento
printf("\nScores ordenados:\n");
ordena_scores(jogadores, nest); //ordenamento dos scores
imprime_scores(jogadores, nest); //impress�o dos scores ordenados
return 0;
}
