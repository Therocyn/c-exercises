#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

typedef struct tipo_jogador //definição da estrutura de highscores dada no exercicio
{
    char nome[40];
    int score;
} TIPO_JOGADOR;

void movimenta_flecha(int*, char*, int*, char*);
void imprime_cenario(char*);

void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void preenche_cenario(char *matrizcen)
{
    char cenario[35][80];
    int i, i2;
    for(i=0; i<35; i++)
    {
        for(i2=0; i2<80; i2++)
        {
            cenario[i][i2]=' ';
            if(i==0 || i==34 || i==3)
                cenario[i][i2]='-';
            if(i2==78 || i2==0)
                cenario[i][i2]=':';
            if(i2==79)
                cenario[i][i2]='\0';

            cenario[0][28] = '>';
            cenario[0][29] = ' ';
            cenario[0][30] = 'B';
            cenario[0][31] = 'O';
            cenario[0][32] = 'W';
            cenario[0][33] = ' ';
            cenario[0][34] = 'A';
            cenario[0][35] = 'N';
            cenario[0][36] = 'D';
            cenario[0][37] = ' ';
            cenario[0][38] = 'A';
            cenario[0][39] = 'R';
            cenario[0][40] = 'R';
            cenario[0][41] = 'O';
            cenario[0][42] = 'W';
            cenario[0][43] = ' ';
            cenario[0][44] = '<';
        }
    }
    for(i=0; i<35; i++)
    {
        for(i2=0; i2<80; i2++)
        {
            *(matrizcen+i*80+i2) = cenario[i][i2];
        }
    }
}

void preenche_menu(char *matrizcen)
{
    char cenario[35][80];
    int i, i2;
    for(i=0; i<35; i++)
    {
        for(i2=0; i2<80; i2++)
        {
            cenario[i][i2]=' ';
            if(i==0 || i==34 || i==5)
                cenario[i][i2]='-';
            if(i2==78 || i2==0)
                cenario[i][i2]=':';
            if(i2==79)
                cenario[i][i2]='\0';

            cenario[3][30] = 'B';
            cenario[3][31] = 'O';
            cenario[3][32] = 'W';
            cenario[3][33] = ' ';
            cenario[3][34] = 'A';
            cenario[3][35] = 'N';
            cenario[3][36] = 'D';
            cenario[3][37] = ' ';
            cenario[3][38] = 'A';
            cenario[3][39] = 'R';
            cenario[3][40] = 'R';
            cenario[3][41] = 'O';
            cenario[3][42] = 'W';
            cenario[3][43] = ' ';

            cenario[15][30] = '-';
            cenario[15][31] = '-';
            cenario[15][32] = '>';

            cenario[15][33] = ' ';
            cenario[15][34] = 'N';
            cenario[15][35] = 'O';
            cenario[15][36] = 'V';
            cenario[15][37] = 'O';
            cenario[15][38] = ' ';
            cenario[15][39] = 'J';
            cenario[15][40] = 'O';
            cenario[15][41] = 'G';
            cenario[15][42] = 'O';

            cenario[16][34] = 'H';
            cenario[16][35] = 'I';
            cenario[16][36] = 'G';
            cenario[16][37] = 'H';
            cenario[16][38] = 'S';
            cenario[16][39] = 'C';
            cenario[16][40] = 'O';
            cenario[16][41] = 'R';
            cenario[16][42] = 'E';
            cenario[16][43] = 'S';

            cenario[17][34] = 'S';
            cenario[17][35] = 'A';
            cenario[17][36] = 'I';
            cenario[17][37] = 'R';

        }
    }
    for(i=0; i<35; i++)
    {
        for(i2=0; i2<80; i2++)
        {
            *(matrizcen+i*80+i2) = cenario[i][i2];
        }
    }
}

void preenche_menu_score(char *matrizcen)
{
    char cenario[35][80];
    int i, i2;
    for(i=0; i<35; i++)
    {
        for(i2=0; i2<80; i2++)
        {
            cenario[i][i2]=' ';
        }
    }
    for(i=0; i<35; i++)
    {
        for(i2=0; i2<80; i2++)
        {
            *(matrizcen+i*80+i2) = cenario[i][i2];
        }
    }
}


void movimenta_menu(int *jogar, char *cenario, int *posicao, char *c)
{
    if((*c)=='w' && (*posicao) != 15)
    {
        (*posicao)--;
        for(int i2=0; i2<3; i2++)
        {
            *(cenario+((*posicao))*80+(i2+30))=*(cenario+((*posicao)+1)*80+(i2+30));
            *(cenario+((*posicao)+1)*80+(i2+30))= ' ';
        }

        imprime_cenario(cenario);
    }
    if((*c)=='s' && (*posicao) != 17)
    {
        (*posicao)++;
        for(int i2=0; i2<3; i2++)
        {
            *(cenario+((*posicao))*80+(i2+30))=*(cenario+((*posicao)-1)*80+(i2+30));
            *(cenario+((*posicao)-1)*80+(i2+30))=' ';
        }
        imprime_cenario(cenario);
    }

}


void imprime_cenario(char *cenario)
{
    gotoxy(0, 0);
    for(int i=0; i<35; i++)
    {
        printf("%s\n", (cenario+i*80));
    }
}

void le_arqueiro(FILE *arq, char *arqueiro) //essa função recebe o ponteiro para o arquivo do arqueiro base e a matriz em que deverá preencher e devolve a matriz preenchida
{
    int i=0; //i é uma variavel que serve para mudar o indice de linhas na leitura do arquivo
    char aux[4][10]; //matriz auxiliar para armazenar os dados do arquivo

    while(fgets(&aux[i][0], 10, arq )!=0 ) //enquanto ainda tiverem linhas a serem lidas a iteração irá se repetir
    {
        i++; // incremento em +1 para realizar a mudança de linhas na leitura
    }
    for(int i2=0; i2<4; i2++) //esses 2 for servem para percorrer a matriz auxiliar enquanto devolve os dados para a matriz principal na função main
    {
        for(int i3=0; i3<8; i3++)
        {
            *(arqueiro+i2*8+i3) = aux[i2][i3]; //passagem dos dados da matriz auxiliar para a principal
        }
    }
}

void entra_arqueiro(char *arqueiro, char *cenario)
{
    for(int i=0; i<4; i++)
    {
        for(int i2=0; i2<8; i2++)
        {
            *(cenario+(i+16)*80+(i2+2))=(*(arqueiro+i*8+i2));
        }

    }
}


void movimenta_arqueiro(int *jogar, char *cenario, int *posicao, char *c)
{
    if((*c)=='w' && (*posicao) != 4)
    {
        (*posicao)--;
        for(int i=0; i<4; i++)
        {
            for(int i2=0; i2<8; i2++)
            {
                *(cenario+((*posicao)+i)*80+(i2+2))=*(cenario+((*posicao)+i+1)*80+(i2+2));
                *(cenario+((*posicao)+i+1)*80+(i2+2))= ' ';
            }
        }
        imprime_cenario(cenario);
    }
    if((*c)=='s' && (*posicao) != 30)
    {
        (*posicao)++;
        for(int i=0; i<4; i++)
        {
            for(int i2=0; i2<8; i2++)
            {
                *(cenario+((*posicao)-i+3)*80+(i2+2))=*(cenario+((*posicao)-i+2)*80+(i2+2));
                *(cenario+((*posicao)-i+2)*80+(i2+2))=' ';
            }
        }
        imprime_cenario(cenario);
    }
}

void movimenta_flecha(int *jogar,char *cenario, int *posicao, char *c)
{

    if((*c)==' ') //flecha ta em cenario[17][7,8,9]
    {


        int linhaflecha =(*posicao);
        for(int i=10; i<79; i++)
        {
            if(i<76)
            {
                *(cenario+((linhaflecha)+1)*80+(i)) = '-';
                *(cenario+((linhaflecha)+1)*80+(i+1)) = '-';
                *(cenario+((linhaflecha)+1)*80+(i+2)) = '>';
            }
            if(i>75)
                *(cenario+((linhaflecha)+1)*80+77) = '-';
            if(i>10)
                *(cenario+((linhaflecha)+1)*80+(i-1)) = ' ';
            if(i>11)
                *(cenario+((linhaflecha)+1)*80+(i-2)) = ' ';
            if(i>12)
                *(cenario+((linhaflecha)+1)*80+(i-3)) = ' ';
            *c = '\0';
            if(kbhit()) *c = getch();
            movimenta_arqueiro(jogar, cenario, posicao, c);
            imprime_cenario(cenario);
            Sleep(3);
        }
    }
}

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



int main()
{
    int jogar=0, posicao, i=10;
    char cenario[35][80], arqueiro[4][8], c='\0';
    FILE *arqarq;

    //
    char nome_arquivo[20]="highscores.bin";
    TIPO_JOGADOR dadosplayers[5];
    int lidos;
    lidos = le_arquivo(nome_arquivo, dadosplayers);

    preenche_menu(cenario[0]);
    imprime_cenario(cenario[0]);

    posicao=15;
    while(jogar ==0)
    {
        if(kbhit()) c = getch();
        movimenta_menu(&jogar, cenario[0], &posicao, &c);
        if(posicao==15 && c== ' ')
        {
            jogar=1;
        }
        if(posicao==16 && c== ' ')
        {
            preenche_menu_score(cenario[0]);
            imprime_cenario(cenario[0]);
            gotoxy(0,0);
            imprime_scores(dadosplayers, lidos);
            printf("\nPressione qualquer tecla para voltar para o menu principal...");
            getch();
            preenche_menu(cenario[0]);
            posicao=15;
            imprime_cenario(cenario[0]);
        }
        if(posicao==17 && c== ' ')
        {
            printf("Obrigado por jogar!! :D \nFeito por: Vitor Simon de Souza e Tiago Jardim\n");
            return 0;
        }
        c= '\0';
    }

    posicao=16;
    preenche_cenario(cenario[0]);

    arqarq = fopen("arqueiro.txt", "r"); //abertura do arquivo
    if(arqarq == NULL) //se a abertura do arquivo der errado
    {
        printf("Erro ao abrir o arquivo de entrada!"); //imprimo uma mensagem de erro
        return 1; //e encerro o programa
    }
    le_arqueiro(arqarq, arqueiro[0]);
    fclose(arqarq);
    entra_arqueiro(arqueiro[0], cenario[0]);
    imprime_cenario(cenario[0]);


    while(jogar==1)
    {
        if(kbhit()) c = getch();
        movimenta_arqueiro(&jogar, cenario[0], &posicao, &c);
        movimenta_flecha( &jogar, cenario[0], &posicao, &c);
        c= '\0';

    }

    return 0;
}






/*int main()
{
    int jogar=1, posicao=16, i=10;
    char cenario[35][80], arqueiro[4][8], c='\0';
    FILE *arqarq;

    preenche_cenario(cenario[0]);

    arqarq = fopen("arqueiro.txt", "r"); //abertura do arquivo
    if(arqarq == NULL) //se a abertura do arquivo der errado
    {
        printf("Erro ao abrir o arquivo de entrada!"); //imprimo uma mensagem de erro
        return 1; //e encerro o programa
    }
    le_arqueiro(arqarq, arqueiro[0]);
    fclose(arqarq);
    entra_arqueiro(arqueiro[0], cenario[0]);
    imprime_cenario(cenario[0]);





    while(jogar==1)
    {
        if(kbhit()) c = getch();
        movimenta_arqueiro(&jogar, cenario[0], &posicao, &c);
        movimenta_flecha( &jogar, cenario[0], &posicao, &c);
        c= '\0';

    }

    return 0;
}*/
