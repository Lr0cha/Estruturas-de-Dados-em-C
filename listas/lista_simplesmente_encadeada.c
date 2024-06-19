#include <stdio.h>
#include<stdlib.h>

struct No{
    int info;
    struct No *prox;
};

//var global
struct No *inicio = NULL;
struct No *final = NULL;

//prototipos
void menu();
void incluir_lista(int num);
void excluir_da_lista();
void exibir_lista();

int main()
{
    menu();
    return 0;
}

void menu(){
    int op = 0;
    do{
        printf("---------------------------\n");
        printf("\tMenu da lista:\n");
        printf("1- Incluir da lista\n");
        printf("2- Excluir da lista\n");
        printf("3- Exibir a lista\n");
        printf("4- Sair do programa\n");
        printf("---------------------------\n->>");
        scanf("%d", &op);
        switch(op){
            case 1:
                int num = 0;
                printf("Digite o numero:");
                scanf("%d",&num);
                incluir_lista(num);
                break;
            case 2:
                excluir_da_lista();
                break;
            case 3:
                exibir_lista();
                break;
            case 4:
                printf("Saindo...\n");
            default:
                printf("Digite um numero valido!\n");
        }
    }while(op != 4);
    
}

void incluir_lista(int nr){
    struct No *novo = NULL;
    novo = (struct No*)malloc(sizeof(struct No)); //end do que foi reservado na MP
    if (novo == NULL) {
        printf("Memória insuficiente.\n");
        exit(1);
        return;
    }
    novo -> info = nr;
    novo -> prox = NULL;
    if(inicio == NULL){
        inicio = novo;
    }
    else{
        final -> prox = novo;
    }
    final = novo;
    printf("numero %d incluido com sucesso!\n", nr);
}

void excluir_da_lista(){
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    struct No *aux = inicio;
    struct No *ult = NULL; //recebe o anterior
    int numero = 0;
    exibir_lista();
    printf("Digite o numero que deseja retirar da lista:\n");
    scanf("%d",&numero);
    while(aux != NULL){
        if(numero == aux -> info){
            //se for o unico da lista
            if (aux == inicio && aux == final) {
                inicio = NULL;
                final = NULL;
            //primeiro da lista, mas nao unico
            } else if (aux == inicio) {
                inicio = aux->prox;
            //ultimo da lista
            } else if (aux == final) {
                final = ult;
                final->prox = NULL;
            //elemento intermediario na lista
            } 
            else {
                ult -> prox = aux -> prox;
            }
            free(aux);
            printf("%d numero excluido com sucesso da lista!\n", numero);
            return;
        }
        ult = aux;
        aux = aux -> prox;
    }
    printf("Numero %d nao encontrado na lista!\n", numero);
}

void exibir_lista(){
    struct No *aux = inicio;
    if (aux == NULL){
        printf("Lista vazia!\n");
        return;
    }
    printf("Elementos da lista:\n");
    
    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux -> prox;
    }
}



