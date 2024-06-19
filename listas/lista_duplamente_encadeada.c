#include <stdio.h> //entrada e saida
#include <stdlib.h> //alocacao dinamica e etc

//estrutura da lista
struct No {
    struct No *ant;
    int info;
    struct No *prox;
};

//var globais
struct No *inicio = NULL;
struct No *final = NULL;

//prototipos funcoes
void menu();
void incluir_lista(int num);
void excluir_da_lista();
void exibir_lista();

int main() {
    menu();
    return 0;
}

void menu() {
    int op = 0;
    do {
        printf("---------------------------\n");
        printf("\tMenu da lista:\n");
        printf("1- Incluir na lista\n");
        printf("2- Excluir da lista\n");
        printf("3- Exibir a lista\n");
        printf("4- Sair\n");
        printf("---------------------------\n->>");
        scanf("%d", &op);
        switch (op) {
            case 1:
                int num;
                printf("Digite o numero: ");
                scanf("%d", &num);
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
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (op != 4);
}

void incluir_lista(int nr) {
    struct No *novo = (struct No *)malloc(sizeof(struct No)); //reservar byte para armazenar no na MP
    if (novo == NULL) {
        printf("Memória insuficiente.\n");
        exit(1);
    }
    novo->info = nr;
    novo->prox = NULL;
    if (inicio == NULL) {
        novo->ant = NULL;
        inicio = novo;
    } else {
        novo->ant = final;
        final->prox = novo;
    }
    final = novo;
    printf("Numero %d incluído com sucesso!\n", nr);
}

void excluir_da_lista() {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    int numero;
    exibir_lista();
    printf("Digite o numero que deseja retirar da lista: ");
    scanf("%d", &numero);
    struct No *aux = inicio;
    while (aux != NULL) {
        if (numero == aux->info) {
            //primeiro e unico no da lista
            if (aux == inicio && aux == final) {
                inicio = NULL;
                final = NULL;
            //primeiro, mas nao unico da lista
            } else if (aux == inicio) {
                inicio = aux->prox;
                inicio->ant = NULL;
            //ultimo, mas nao unico da lista
            } else if (aux == final) {
                final = aux->ant;
                final->prox = NULL;
            //no intermediario da lista
            } else {
                aux->ant->prox = aux->prox;//atualiza o ponteiro prox do no anterior
                aux->prox->ant = aux->ant;//atualiza o ponteiro ant do no seguinte
            }
            free(aux);
            printf("%d removido com sucesso da lista!\n", numero);
            return;
        }
        aux = aux->prox;
    }
    printf("Elemento não encontrado na lista!\n");
}

void exibir_lista() {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    struct No *aux = inicio;
    printf("Elementos da lista:\n");
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox; //passar para proximo no da lista
    }
}

