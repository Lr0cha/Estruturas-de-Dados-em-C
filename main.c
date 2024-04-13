#include<stdio.h>
#include<stdlib.h>

//struct criada e encadeado na fila
struct No{
	int info;
	struct No *prox;
};


//var global
struct No *inicio=NULL;
struct No *ultimo=NULL;

//prototipos
void enfileirar_fila(int nr);
void desenfileirar_fila();
void exibir_fila();
void menu();

main(){
	menu();
	return 0;
}

void enfileirar_fila(int nr){
	struct No *novo;
	novo=(struct No*)malloc(sizeof(struct No));//guardar primeiro end. celula alocada
	if (novo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return; // Encerrar a função em caso de erro no malloc
    }
    
	if(inicio==NULL){//quer dizer que não há elementos na fila
		novo->info=nr;
		novo->prox=NULL;
		inicio=novo;
	}else{
		novo->info=nr;
		novo->prox=NULL;
		ultimo->prox=novo;
	}
	ultimo=novo;
	printf("Numero %d enfileirado com sucesso!\n",nr);
	printf("Pressione Enter para continuar...");
	getchar();
	getchar();
}

void desenfileirar_fila(){
	struct No *aux = inicio;
	if(aux==NULL){
	    printf("--------------------------------------------------\n\n");
		printf("\t\tFILA VAZIA\n");
		printf("Acrescente um número para desenfileirar!!\n");
		printf("--------------------------------------------------\n");
	}
	else{
		inicio=aux->prox;
		printf("Numero %d desenfileirado com sucesso\n",aux->info);
		free(aux);
	}
	printf("Pressione Enter para continuar...");
	getchar();
	getchar();
	
}
void exibir_fila(){
	struct No *aux;
	aux = inicio;
	int cont = 0;
	printf("--------------------------------------------------\n\n");
	printf("\t\tELEMENTOS DA FILA\n");
	while(aux!=NULL){
	    cont++;
		printf("%d- %d \n",cont, aux->info);
		aux=aux->prox;
	}
	if (cont == 0){
	    printf("Não há elementos na fila\n");
	}
	printf("--------------------------------------------------\n");
	printf("Pressione Enter para continuar...\n");
	getchar();
	getchar();
}

void menu() {
    int op;//var que vai ser usa para converter a entrada pra int
    char entrada_[2];//receber o que o usuario digita
    do {
        system("cls||clear");//limpar tela
        printf("--------------------------------------------------\n\n");
    	printf("\t\tMENU FILA:\n\n");
        printf("1- Enfileirar\n");
        printf("2- Desenfilerar\n");
        printf("3- Exibir a fila\n");
        printf("4- Sair do programa\n");
        printf("Escolha uma das opcões: \n");
        printf("--------------------------------------------------\n");
        //loop infinito
        while(1){
            scanf("%s", &entrada_);
            if(sscanf(entrada_, "%d", &op) == 1){
                break;//sair do loop
            }
            else{
                printf("Digite um número inteiro de 1 a 4 para usar o sistema:\n");
            }
        }
        
        switch(op) {
        	
            case 1:
                int num;
                char entrada[10];
                while(1){
                    printf("Digite um número inteiro para ir para fila: ");
                    scanf("%s",&entrada);
                    if(sscanf(entrada, "%d", &num) == 1){
                        break;   
                    }//se conseguir converter em int
                    else{
                        printf("Entrada inválida, entre com um número inteiro\n");
                    }//senão volta no loop
                }
                enfileirar_fila(num);
                break;
                
            case 2:
                desenfileirar_fila();
                break;
                
            case 3:
                exibir_fila();
                break;
                
            case 4:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
                printf("Pressione Enter para continuar...\n");
	            getchar();
	            getchar();
        }
    } while (op != 4);
}
