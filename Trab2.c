/*******************************************************************************
 Estrutura de dados - 2025/01 -  Professora: Eliza Helena
Alunos: Guilherme Ferreira Brandão   231030691
        Guilherme Nascimento Tegnoue 231011909

    Nós Declaramos que somos os autores deste trabalho e que o código não foi copiado
    de outra pessoa nem repassado para alguém. Estamos cientes de que poderemos sofrer
    penalizações na avaliação em caso de detecção de plágio.    


    A nossa ideia é representar o torneio tribruxo em código, inspirado obviamente no Harry Potter e Cálice de Fogo.         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    Em nosso torneio é necessário fazer o cadastro de 6 integrantes, sendo 3 duplas            ⠀⠀⣤⣤⣤⡤⠀⠈⣿⣿⣿⡿⠛⠛⣷⣄⠀⠀
    e suas respectivas casas, tais como Grifinória, Sonserina, Corvinal              ⠀⠀⠀⠙⣿⣿⣿⡏⠀⠀⢸⣿⣿⡇⠀⠀⢿⣿⣿⣷⠀⠀⣿⣿⣷⡄
    e Lufa-Lufa para participar do torneio.                                         ⠀⠀⠀⠀⣿⣿⣿⡇⠀⠀⢸⣿⣿⡇⠀⠀⢸⣿⣿⣿⠀⠀⢹⣿⣿⡇
    Logo em seguida eles terão os seus desafios...                                  ⠀⠀⠀⠀⣿⣿⣿⡇⠀⠀⠘⣿⣿⡇⠀⠀⠈⣿⣿⣿⠀⠀⢸⣿⣿⡇
    Nesses desafios, será sorteado o vencedor,                                      ⠀⢀⡀⠀⣿⣿⣿⡇⠀⠀⢀⣿⣿⣿⠖⠓⣶⣿⣿⣿⠐⣄⣸⣿⣿⠇
    utilizando a função rand da biblioteca <time.h>.                                ⠈⢧⣀⠀⣿⣿⣿⣇⣠⣴⣿⣿⣿⣿⠀⠀⢻⣿⣿⣿⡇⠈⠛⠉⠀⠀
    E no final iremos imprimir a dupla vencedora e                                  ⠀⠀⠉⠛⣿⣿⣿⡟⠉⠁⠀⣿⣿⣿⠀⠀⢸⣿⣿⡿⡇⠀⠀⠀⠀⠀
    a árvore que seria, nesse contexto de torneio o chaveamento.                     ⠀⠀⠀⠀⣿⣿⣿⡇⠀⠀⠀⣿⣿⣿⠀⠀⢄⣿⣿⡇⠘⠀⠀⠀⠀⠀
                                                                                   ⠀⠀⠀⠀  ⣿⣿⣿⡇⠀⠀⠀⣿⣿⣿⠀⠀⢸⣿⣿⣷⠀⠀⠀⠀⠀⠀
                                                                                   ⠀⠀  ⠀⢀⣿⣿⣿⣇⠀⠀⠀⣿⣿⣿⠀⠀⠀⣿⡿⣿⠀⠀⠀⠀⠀⠀
                                                                                   ⠀⠀  ⠈⠉⠉⠉⠉⠉⠁⢀⡼⠿⠿⢿⣦⡀⠀⢹⡇⠈⠀⠀⠀⠀⠀⠀
                                                                                   ⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀
                                                                                   ⠀⠀⠀⠀
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct no ArvNo;
typedef struct arv Arv;

struct no{
    char nome[50];
    char casa[50];
    ArvNo *esq;
    ArvNo *dir;
};
struct arv{
    ArvNo* raiz;
};


//Cria nó na árvore 

ArvNo* criaNo(char Nome[50],char Casa[50], ArvNo* esquerda, ArvNo* direita){
    ArvNo* no = (ArvNo*)malloc(sizeof(ArvNo));
    strcpy(no->nome, Nome);//O strcpy copia o texto de uma string pra outra
    strcpy(no->casa, Casa);
    no->esq = esquerda;
    no->dir = direita;
    return no;

};


//Cria a árvore 

Arv* criaArv(ArvNo* r){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = r;
    return a;

};

//imprimir 
void imprime(ArvNo* r, int nivel){
    if(r != NULL){
        for(int i=0; i<nivel; i++) printf("  ");
        printf("Vencedor: %s (%s)\n", r->nome, r->casa);
        imprime(r->esq, nivel+1);
        imprime(r->dir, nivel+1);
    };

};


//Libera os nós da árvore

void liberaNo(ArvNo* r){
    if(r != NULL){
        liberaNo(r->esq);
        liberaNo(r->dir);
        free(r);
    };

};

// Função para sortear o vencedor  e mostrar a historia do torneio
void torneio(char* nome1, char* casa1, char* nome3, char* casa3){
    printf("\n O Torneio TriBruxo sera entre %s da casa %s contra  %s da casa %s \n", nome1, casa1, nome3, casa3);

     printf(" O bruxo  %s da casa %s  esta em um Duelo contra  %s da casa %s \n", nome1, casa1, nome3, casa3);
     
  

};

void sorteandoVencedor(char* nome1, char* casa1, char* nome2, char* casa2, char* vencedorNome, char* vencedorCasa){
   torneio(nome1, casa1, nome2, casa2);
        if (rand() % 2 == 0) {
        printf("=> %s venceu o Duelo e Avanca!\n", nome1);
        strcpy(vencedorNome, nome1);
        strcpy(vencedorCasa, casa1);
    } else {
        printf("=> %s venceu o Duelo e Avanca!\n", nome2);
        strcpy(vencedorNome, nome2);
        strcpy(vencedorCasa, casa2);
    };


};


int main(){

srand(time(NULL));// Iniciando pra funcionar o rand
char nomes[6][50], casas[6][50];

    printf("BEM VINDO AO TORNEIO TRIBRUXO\n");

    printf("____***____ Cadastro dos participantes do Torneio Tribruxo ____***____ \n");
    for (int i = 0; i < 6; i++) {
        printf("\nNome do bruxo %d: ", i + 1);
        fgets(nomes[i], 50, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        printf("Casa do bruxo %d: ", i + 1);
        fgets(casas[i], 50, stdin);
        casas[i][strcspn(casas[i], "\n")] = '\0';
    };

// Fase 1  com 3 desafios
 char v1[50], c1[50], v2[50], c2[50], v3[50], c3[50];
    sorteandoVencedor(nomes[0], casas[0], nomes[1], casas[1], v1, c1);
    ArvNo* p1 = criaNo(v1, c1, NULL, NULL);

    sorteandoVencedor(nomes[2], casas[2], nomes[3], casas[3], v2, c2);
    ArvNo* p2 = criaNo(v2, c2, NULL, NULL);

    sorteandoVencedor(nomes[4], casas[4], nomes[5], casas[5], v3, c3);
    ArvNo* p3 = criaNo(v3, c3, NULL, NULL);

    // Sorteando quem vai pra final
    int direto = rand() % 3;
    int semi1 = (direto + 1) % 3;
    int semi2 = (direto + 2) % 3;

    char vSemi[50], cSemi[50];
    ArvNo* semiEsq = (semi1 == 0) ? p1 : (semi1 == 1) ? p2 : p3;
    ArvNo* semiDir = (semi2 == 0) ? p1 : (semi2 == 1) ? p2 : p3;
    sorteandoVencedor(semiEsq->nome, semiEsq->casa, semiDir->nome, semiDir->casa, vSemi, cSemi);
    ArvNo* semi = criaNo(vSemi, cSemi, semiEsq, semiDir);

    printf("\n%s avanca direto para a final!\n", (direto == 0) ? p1->nome : (direto == 1) ? p2->nome : p3->nome);

    // A Grande Final
    char vFinal[50], cFinal[50];
    ArvNo* diretoNo = (direto == 0) ? p1 : (direto == 1) ? p2 : p3;
    sorteandoVencedor(semi->nome, semi->casa, diretoNo->nome, diretoNo->casa, vFinal, cFinal);
    ArvNo* final = criaNo(vFinal, cFinal, semi, diretoNo);

    printf("\n____***____  Resultado Final do Torneio Tribruxo ____***____ \n");
    printf("Campeao do Torneio: %s da casa %s!\n\n", final->nome, final->casa);

    imprime(final, 0);

    liberaNo(final);


 return 0;

};
