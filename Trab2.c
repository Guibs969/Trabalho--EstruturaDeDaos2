#include <stdio.h>
#include <stdlib.h>


typedef struct no ArvNo;
typedef struct arv Arv;

struct no{
    int info;
    ArvNo *esq;
    ArvNo *dir;
};

struct arv{
    ArvNo* raiz;

};

//Cria nó na árvore 

ArvNo* criaNo(int elem, ArvNo* esquerda, ArvNo* direita){
    ArvNo* no = (ArvNo*)malloc(sizeof(ArvNo));
    no->info = elem;
    no->esq = esquerda;
    no->dir = direita;
    return no;

};


//Cria a árvore 

Arv* criaArv(ArvNo* r){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = r;
    retunt a;

};


//imprimir os nós da árvore Pré-ordem
void imprime (ArvNo* r){
    if(r != NULL){
        printf("%d", r->info);
        imprime(r->esq);
        imprime(r->dir);

    };


};

//Imprimir a árvore começando pela raiz

void imprimeRaiz(Arv* a){
    imprime(a->raiz);

};



//Libera os nós da árvore

void liberaNo(ArvNo* r){
    if(r != NULL){
        liberaNo(r->esq);
        liberaNo(r->dir);
        free(r);


    };


};

//Libera árvore

void liberaArv(Arv* a){
    liberaNo(a->raiz);
    free(a);


};


//Busca nó da árvore
ArvNo* buscaNo(ArvNo* r, int elem){
    if(r ==NULL){

        return NULL;

    }else if(elem ==r->info){
        return r;

    }else{
        ArvNo* no = buscaNo(r->esq, elem);
        if(no != NULL){
            return no;
            

            }else{
                return buscaNo(r->dir, elem);

            };

        };

    };


//Busca nó a partir da raiz 
ArvNo* buscaArv(Arv* a, int elem){
 return buscaNo(a->raiz, elem);

 };


 


//Altura da árvore

int max (int a, int b){
    return(a>b)? a:b;

};

int altura(ArvNo* r){
 if(r == NULL){
   return -1;
    }else{
     return 1 + max (altura(r->esq), altura(r->dir));
    };
   };


int alturaArv(Arv* a){
    return altura(a->raiz);

};





int main(){
 Arv*a= criaArv(criaNo(50,
            criaNo(10,criaNo(5, NULL, NULL),
            criaNo(30,
                criaNo(25, NULL, NULL),
                criaNo(45,
                    criaNo(40, NULL, NULL),
                    NULL))),
                    criaNo(99, NULL, NULL)));
 
 
      imprimeRaiz(a);
 
 return 0;

}