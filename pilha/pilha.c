#include <stdio.h> //entrada e saida
#include <stdlib.h> //alocacao e etc
#include <stdbool.h> //em c incluir para funcionar o booleano

struct No{
	int info;
	struct No *prox;
}; //estrutura para encadear

struct No *topo=NULL; //cria uma var global de "cabeça" da lista

//prototipos
void empilhar_pilha(int); 
void exibir_pilha();
void desempilhar_pilha();
void menu();
void exibir_topo_pilha();
void tamanho_pilha();

int main(){
	menu();
	return 0;
}

void empilhar_pilha(int nr){
	struct No *novo; //guardar o retorno(ENDEREÇO) do malloc
	novo=(struct No*)malloc(sizeof(struct No)); //reservou 1 dessa struct e mandou o endereço pra var
	novo->info=nr; //pra onde o novo aponta colocar o parametro no campo info da struct
	novo->prox=topo; //recebe o topo anterior para "ligar"
	topo=novo; //recebe o novo valor que foi inserido
	printf("%d inserido com sucesso!\n", nr);
}

void exibir_pilha(){
	struct No *aux = topo; //criar uma copia para não mexer no topo original e perder a referência
	if(topo!=NULL){
	    printf("Elementos da pilha:\n");
		while(aux!=NULL){
			printf("%d \n",aux->info);
			aux = aux->prox; //recebe o campo prox da struct que ele aponta para acessar o antecessor na pilha
		}	
	}
	else{
		printf("Pilha vazia!\n");
	}
	printf("\n");
}

void desempilhar_pilha(){
	struct No *aux = topo;
	if(topo != NULL){
		topo = topo->prox; //insere o valor anterior como novo topo
		printf("%d desempilhado com sucesso!\n", aux->info);
		free(aux);
		
	} 
	else{
		printf("Pilha vazia!\n");
	}	
}

void menu(){
	int op=0;
	do{
    	printf("--------------------------------\n");
    	printf("\t***Pilha Dinamica***\n");
    	printf("1-Empilhar\n");
    	printf("2-Desempilhar\n");
    	printf("3-Exibir Pilha\n");
    	printf("4-Exibir o topo da Pilha\n");
    	printf("5-Exibir tamanho da Pilha\n");
    	printf("6-Sair\n");
    	printf("--------------------------------\n->>");
    	scanf("%d",&op);
    	switch(op){
    		case 1:	
    			int num;
    			printf("Digite um numero inteiro:");
    			scanf("%d",&num); //numero que será armazenado no campo info da struct
    			empilhar_pilha(num);
    			break;
    		case 2: 
    			desempilhar_pilha();
    			break;
    		case 3:
    			exibir_pilha();
    			break;
    		case 4:
    			exibir_topo_pilha();
    			break;
    		case 5:
    			tamanho_pilha();
    			break;
    		case 6:
    			printf("Saindo...\n");
    			break;
    		default:
    		    printf("Digite um numero valido!");
    	}
    }while(op != 6);
}
	

void exibir_topo_pilha(){
	struct No *aux = topo; //ponteiro guardando 
	if(aux!=NULL){
		printf("Topo da pilha: %d\n",aux->info);
	}
	else{
		printf("A pilha esta vazia\n");
	}
}

void tamanho_pilha(){
    int cont=0;
    struct No *aux = topo;
    while(aux!=NULL){
        cont++;
        aux=aux->prox;
    }
    if(cont!=0){
        printf("Está pilha tem %d elementos\n" ,cont);
    }
    else{
        printf("Não há elementos nessa pilha\n");
    }
}




