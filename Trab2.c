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
                                                                                    ⠀  ⠀⢀⣿⣿⣿⣇⠀⠀⠀⣿⣿⣿⠀⠀⠀⣿⡿⣿⠀⠀⠀⠀⠀⠀
                                                                                    ⠀  ⠈⠉⠉⠉⠉⠉⠁⢀⡼⠿⠿⢿⣦⡀⠀⢹⡇⠈⠀⠀⠀⠀⠀⠀
                                                                                   ⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀
                                                                                   ⠀⠀⠀⠀
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct no ArvNo;
typedef struct arv Arv;
typedef struct bruxo Bruxo;

struct bruxo{
    char nome[50];
    char casa[50];
};

struct no{
    Bruxo bruxo;
    ArvNo *esq;
    ArvNo *dir;
};

struct arv{
    ArvNo* raiz;
};


//cria nó na árvore 
ArvNo* criaNo(char Nome[50],char Casa[50], ArvNo* esquerda, ArvNo* direita){
    ArvNo* no = (ArvNo*)malloc(sizeof(ArvNo));
    strcpy(no->bruxo.nome, Nome);// O strcpy copia o texto de uma string pra outra
    strcpy(no->bruxo.casa, Casa);
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

//Libera os nós da árvore
void liberaNo(ArvNo* r){
    if(r != NULL){
        liberaNo(r->esq);
        liberaNo(r->dir);
        free(r);
    };
};

// Libera a memória da árvore completa (nós e a estrutura Arv)
void liberaArv(Arv* a) {
    if (a != NULL) {
        liberaNo(a->raiz); // Libera todos os nós
        free(a);           // Libera o contêiner da árvore
    }
}

//imprimindo em PÓS ORDEM
void imprimirResultadosPosOrdem(ArvNo* partida, int nivel) {
    if (partida == NULL) {
        return;
    }

    imprimirResultadosPosOrdem(partida->esq, nivel + 1);

    imprimirResultadosPosOrdem(partida->dir, nivel + 1);

    if (partida->esq != NULL && partida->dir != NULL) {
        // indentação
        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }

        //duelos
        printf("Rodada: %s vs %s  =>  Vencedor: %s\n",
               partida->esq->bruxo.nome,
               partida->dir->bruxo.nome,
               partida->bruxo.nome);
    }
}

void imprimirTorneioCronologico(ArvNo* campeao) {
    if (campeao == NULL) {
        printf("Torneio vazio!\n");
        return;
    }
    printf("\n--- Resultados do Torneio (Ordem Cronológica) ---\n\n");

    // recursao 
    imprimirResultadosPosOrdem(campeao, 0);


    printf("\nO grande campeão do Torneio Tribruxo é: %s (%s)!\n", campeao->bruxo.nome, campeao->bruxo.casa);
}


// Função para sortear o vencedor e mostrar a historia do torneio
void torneio(char* nome1, char* casa1, char* nome2, char* casa2){
};

void sorteandoVencedor(char* nome1, char* casa1, char* nome2, char* casa2, char* vencedorNome, char* vencedorCasa){
   torneio(nome1, casa1, nome2, casa2);
        if (rand() % 2 == 0) {
        strcpy(vencedorNome, nome1);
        strcpy(vencedorCasa, casa1);
    } else {
        strcpy(vencedorNome, nome2);
        strcpy(vencedorCasa, casa2);
    };
};

Bruxo bruxosDeHogwarts[10] = {
    {"Harry Potter", "Grifinoria"},
    {"Hermione Granger", "Grifinoria"},
    {"Rony Weasley", "Grifinoria"},
    {"Draco Malfoy", "Sonserina"},
    {"Luna Lovegood", "Corvinal"},
    {"Cedrico Diggory", "Lufa-Lufa"},
    {"Severo Snape", "Sonserina"},
    {"Alvo Dumbledore", "Grifinoria"},
    {"Ninfadora Tonks", "Lufa-Lufa"},
    {"Minerva McGonagall", "Grifinoria"}
};



int main(){

    
srand(time(NULL));// Iniciando pra funcionar o rand
Bruxo bruxoUsuario[2];

    printf("BEM VINDO AO TORNEIO TRIBRUXO\n");

    printf("____***____ Cadastro dos participantes do Torneio Tribruxo ____***____ \n");
    for (int i = 0; i < 2; i++) {
        printf("\nNome do bruxo %d: ", i + 1);
        fgets(bruxoUsuario[i].nome, 50, stdin);
        bruxoUsuario[i].nome[strcspn(bruxoUsuario[i].nome, "\n")] = '\0';

        printf("Casa do bruxo %d: ", i + 1);
        fgets(bruxoUsuario[i].casa, 50, stdin);
        bruxoUsuario[i].casa[strcspn(bruxoUsuario[i].casa, "\n")] = '\0';
    };

    Bruxo participantesTorneio[6];

int indicesUtilizados[4] = {-1, -1, -1, -1};

participantesTorneio[0] = bruxoUsuario[0];
participantesTorneio[2] = bruxoUsuario[1]; 

int vagasPreenchidas = 0;
while(vagasPreenchidas < 4) {
    int indiceAleatorio;
    int repetido;


    do {
        indiceAleatorio = rand() % 10; 
        repetido = 0;

        for (int j = 0; j < vagasPreenchidas; j++) {
            if (indiceAleatorio == indicesUtilizados[j]) {
                repetido = 1; 
                break;
            }
        }
    } while (repetido);
    indicesUtilizados[vagasPreenchidas] = indiceAleatorio;

    if (vagasPreenchidas == 0) {

        participantesTorneio[1] = bruxosDeHogwarts[indiceAleatorio];
    } else if (vagasPreenchidas == 1) {

        participantesTorneio[3] = bruxosDeHogwarts[indiceAleatorio];
    } else if (vagasPreenchidas == 2) {

        participantesTorneio[4] = bruxosDeHogwarts[indiceAleatorio];
    } else if (vagasPreenchidas == 3) {

        participantesTorneio[5] = bruxosDeHogwarts[indiceAleatorio];
    }

    vagasPreenchidas++; 
}

    printf("\n\n____***____ Participantes do Torneio ____***____\n");
    for (int i = 0; i < 6; i++) {
        printf("Participante %d: %s (Casa: %s)\n", i + 1, participantesTorneio[i].nome, participantesTorneio[i].casa);
    }
// Fase 1 com 3 desafios
 char v1[50], c1[50], v2[50], c2[50], v3[50], c3[50];
    ArvNo* no_p0 = criaNo(participantesTorneio[0].nome, participantesTorneio[0].casa, NULL, NULL);
    ArvNo* no_p1 = criaNo(participantesTorneio[1].nome, participantesTorneio[1].casa, NULL, NULL);
    sorteandoVencedor(participantesTorneio[0].nome, participantesTorneio[0].casa, participantesTorneio[1].nome, participantesTorneio[1].casa, v1, c1);
    ArvNo* p1 = criaNo(v1, c1, no_p0, no_p1);

    ArvNo* no_p2 = criaNo(participantesTorneio[2].nome, participantesTorneio[2].casa, NULL, NULL);
    ArvNo* no_p3 = criaNo(participantesTorneio[3].nome, participantesTorneio[3].casa, NULL, NULL);
    sorteandoVencedor(participantesTorneio[2].nome, participantesTorneio[2].casa, participantesTorneio[3].nome, participantesTorneio[3].casa, v2, c2);
    ArvNo* p2 = criaNo(v2, c2, no_p2, no_p3);

    ArvNo* no_p4 = criaNo(participantesTorneio[4].nome, participantesTorneio[4].casa, NULL, NULL);
    ArvNo* no_p5 = criaNo(participantesTorneio[5].nome, participantesTorneio[5].casa, NULL, NULL);
    sorteandoVencedor(participantesTorneio[4].nome, participantesTorneio[4].casa, participantesTorneio[5].nome, participantesTorneio[5].casa, v3, c3);
    ArvNo* p3 = criaNo(v3, c3, no_p4, no_p5);

    // Sorteando quem vai pra final
    int direto = rand() % 3;
    int semi1_idx = (direto + 1) % 3;
    int semi2_idx = (direto + 2) % 3;

    ArvNo* vencedoresFase1[] = {p1, p2, p3};
    
    char vSemi[50], cSemi[50];
    ArvNo* semiEsq = vencedoresFase1[semi1_idx];
    ArvNo* semiDir = vencedoresFase1[semi2_idx];
    sorteandoVencedor(semiEsq->bruxo.nome, semiEsq->bruxo.casa, semiDir->bruxo.nome, semiDir->bruxo.casa, vSemi, cSemi);
    ArvNo* semi = criaNo(vSemi, cSemi, semiEsq, semiDir);

    // A Grande Final
    char vFinal[50], cFinal[50];
    ArvNo* diretoNo = vencedoresFase1[direto];
    sorteandoVencedor(semi->bruxo.nome, semi->bruxo.casa, diretoNo->bruxo.nome, diretoNo->bruxo.casa, vFinal, cFinal);
    ArvNo* final = criaNo(vFinal, cFinal, semi, diretoNo);

    // arvore + impressao
    Arv* arvoreTorneio = criaArv(final);
    imprimirTorneioCronologico(arvoreTorneio->raiz);
    liberaArv(arvoreTorneio);

 return 0;

};