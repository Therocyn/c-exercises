
//exercicio 1, o programa pede 4 variáveis(a,b,c,d) e imprime na tela a matriz inversa(e,f,g,h)

#include <stdio.h>

int main(){
    float a, b, c, d; //variaveis de entrada da matriz
    float e, f, g, h; //variaveis de saida na matriz inversa

    //leitura dos valores
    printf("Digite as variaveis da matriz:");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);

    //calculo da matriz inversa
    e = d/ (a*d-b*c);
    f = -b/ (a*d-b*c);
    g = -c/ (a*d-b*c);
    h = a/ (a*d-b*c);

    //impressão dos valores na tela
    printf("Matriz inversa a seguir:\n");
    printf("%8.5f    %8.5f\n", e, f);
    printf("%8.5f    %8.5f", g, h);

return 0;
}
