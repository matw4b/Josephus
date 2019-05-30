#include <stdio.h>
#include <string.h>

#define MAX 7 /*maximo de elementos na lista*/

typedef struct{
	char nome[20];
}nomes;

typedef struct{
	int nr_Elementos;
	nomes array[MAX];
}lista;

void inicializa_Lista(lista* p){
	p->nr_Elementos = 6; /*indica que a lista estah vazia*/
	/*preenchimento da lista com os nomes abaixo*/
	strcpy(p->array[0].nome, "Alberto");
	strcpy(p->array[1].nome, "Bernardo");
	strcpy(p->array[2].nome, "Caio");
	strcpy(p->array[3].nome, "Daniel");
	strcpy(p->array[4].nome, "Eduardo");
	strcpy(p->array[5].nome, "Flavio");
	strcpy(p->array[6].nome, "Gabriel");
}

void imprime_Lista(lista* p){
	int i;
	for(i = 0; i < MAX; i++){
		printf("(%d)%s\n", i+1, p->array[i].nome);
	}
}

void remover_Soldado(lista*p, int posicao){
	int i;
	
	if(posicao == p->nr_Elementos){/*se for o ultimo elemento da lista*/
		p->nr_Elementos--;/*atualiza o valor do numero de elementos*/
		printf("Soldado removido: %s\n", p->array[posicao].nome);/*mostra quem saiu da lista*/
		strcpy(p->array[posicao].nome, "\0");/*esvazia a string*/
	}
	else{
		printf("Soldado removido: %s\n", p->array[posicao].nome);/*mostra quem saiu da lista*/
		for(i = posicao; i < p->nr_Elementos; i++){/*desloca a lista para ocupar a posicao do elemento retirado*/
			strcpy(p->array[i].nome, p->array[i+1].nome);
		}
		p->nr_Elementos--;/*atualiza o valor do numero de elementos*/
	}
}

int main(){
	lista Lista;/*aloca uma lista estatica*/
	lista* p = &Lista;/*aloca um ponteiro para guardar a lista*/
	int n;/*numero que representa a meta da contagem*/
	int escolha; /*escolha do soldado da lista para iniciar a contagem*/
	int i; /*contador do loop*/
	int posicao; /*posicao atual na lista*/
	
	inicializa_Lista(p);
	
	printf("Digite um numero N > 1: ");
	scanf("%d", &n);
	printf("\n\n\n");
	imprime_Lista(p);
	printf("Escolha um soldado: ");
	scanf("%d", &escolha);
	printf("\n\n\n");
	
	posicao = escolha-1;/*Configura o ponto de partida para percorrer a lista (obs: por causa disso nao da para usar pos = i%nr_Elementos para percorrer)*/
	i = 0;
	while(p->nr_Elementos > 0){/*Enquanto a lista nao tiver apenas 1 soldado, o loop remove soldados.*/
		i++;
		if(i%n == 0 && i != 0){
			remover_Soldado(p, posicao);
		}
		if(posicao < p->nr_Elementos && i%n != 0)/*Avanca a posicao da lista*/
			posicao++;
		else if(posicao >= p->nr_Elementos)/*retorna para o inicio do vetor*/
			posicao = 0;
	}
	
	printf("Soldado que chamara reforcos: %s\n", p->array[0].nome);
	
	return 0;
}