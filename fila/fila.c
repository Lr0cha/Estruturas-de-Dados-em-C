#include<stdio.h>
#include<stdlib.h>

struct No{
	int info;
	struct No *prox;
};

struct No *inicio=NULL;
struct No *ultimo=NULL;

void enfileirar_fila(int nr);
void desenfileirar_fila();
void exibir_fila();
void tamanho_fila();
void menu();

int main(){
	menu();
	return 0;
}

void enfileirar_fila(int nr){
	struct No *novo;
	novo=(struct No*)malloc(sizeof(struct No));//guardar primeiro end. celula alocada
	if(inicio==NULL){
		novo->info=nr;
		novo->prox=NULL;
		inicio=novo;
	}else{
		novo->info=nr;
		novo->prox=NULL;
		ultimo->prox=novo;
	}
	ultimo=novo;
	printf("Numero %d enfileirado com sucesso!\n\n",nr);
}

void desenfileirar_fila(){
	struct No *aux = inicio;
	if(aux==NULL){
		printf("Fila esta vazia\n");
	}
	else{
		inicio=aux->prox;
		printf("Numero %d desenfileirado com sucesso\n",aux->info);
		free(aux);	
	}
	
}
void exibir_fila(){
	struct No *aux;
	aux = inicio;
	if (aux == NULL){
	    printf("Fila vazia!");
	    return;
	}
	printf("Elementos da fila:\n");
	while(aux!=NULL){
		printf("%d \n",aux->info);
		aux=aux->prox;
	}
}
void tamanho_fila(){
    int cont = 0;
    struct No *aux = inicio;
    while(aux != NULL){
        cont++;
        aux = aux -> prox;
    }
    if (cont == 0 || cont == 1){
        if (cont == 0){
            printf("Sem elementos na fila!\n");
        }
        else{
            printf("%d elemento na fila\n",cont);
        }
    }   
    else{
        printf("%d elementos na fila\n",cont);
    }
    
}
void menu() {
    int op;
    do {
        printf("---------------------------------------\n");
    	printf("\t\tMENU DA FILA:\n\n");
        printf("\n1- Adicionar na fila\n");
        printf("2- Remover da fila\n");
        printf("3- Exibir fila\n");
        printf("4- Tamanho da fila\n");
        printf("5- Sair do programa\n");
        printf("---------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op) {
        	
            case 1:
                int num;
                printf("Digite um numero para enfileirar: ");
                scanf("%d", &num);
                enfileirar_fila(num);
				
                break;
                
            case 2:
                desenfileirar_fila();
                break;
                
            case 3:
                exibir_fila();
                break;
                
            case 4:
                tamanho_fila();
                break;
                
            case 5:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 5);
}





