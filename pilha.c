#include <stdio.h>
#include <stdlib.h>

typedef struct Tpilha
{
	int elemento;
	struct Tpilha* anterior;
}pilha;
//espera como 2 parametros um ponteiro de pilhas(pilha na verdade é como se fosse um elemento da pilha tipo um quadrado em cima do outro)
// a pilha seria esse quadrado, que na verdade é um elemento, mas eu n chamo de elemento por que na programação ela guarda tanto o elemento
// que representa ela quanto o proximo elemento 
void push(pilha** temp1,int elemento){
	//declara um novo ponteiro de pilha que um ponteiro que vai apontar pra uma area de memoria que guarda um elemento(numero)
	//e um ponteiro que é o proximo, um meme que tem sua graça mas tem uma referencia a outro meme que tem sua graça
	//q tem outro meme e etc etc;...
	//maloc guarda memoria
	pilha* novo= (pilha*)malloc(sizeof(pilha));
	//ultiliza a setinha por que ele não é um struckt em si(struct é uma estrutura que guarda varios tipos de dados)
	//ele nao é um struck é um ponteiro pra struck, ou seja aponta pra uma area de memoria do tamanho de um struck
	//recebe elemento passado pelo parametro da funcao eles tem o mesmo nome mas um é o que tá la nos parentese o outro é o que tá dentro
	//do struckt ver 4 linha
	novo->elemento=elemento;
	//novo anterior recebe o conteudo(*)de temp 1, o que é temp1? é um ponteiro de ponteiro de struck
	//é uma referencia a uma variavel que guarda refencia
	// é uma referencia do meme do vin disel fazendo referencia a isso aqui tá uma porra.
	//mas o que tem em temp1? geralmente essa funcao vai retornar o topo da pilha	
	novo->anterior=(*temp1);
	//agora que o nosso novo elemento aponta pro topo, o topo vai ser atualizado pq já temos um novo
	*temp1=novo;
}

void imprime(pilha** temp){
pilha* aux= *temp;
		printf("elemento %i\n",aux->elemento);
		while(aux->anterior!=NULL){	
		aux=aux->anterior;
		printf("elemento %i\n",aux->elemento);
		}
}
//pop remove um iten
int pop(pilha** original){
//ela retorna o valor removido tipo eu tinha 3 no topo tirei ele essa função retorna o valor removido 
// eu posso guardar ele ou não

	int retorno= (*original)->elemento;
	//aux recebe o topo
	pilha* aux= *original;
	//o topo recebe o proprio elemento do topo
	*original=(*original)->anterior;
	//o topo antigo é free livre liberado apagado
	free(aux);
	return retorno;
}


int main()
{
	pilha* torre=NULL;
	pilha* torre2=NULL;

	push(&torre,3);
	push(&torre,5);
	push(&torre,7);
	push(&torre,9);
	imprime(&torre);
	printf("\n\n\n\n\n\n\n\n\n");
	pop(&torre);
	imprime(&torre);
	printf("\n\n\n");
	push(&torre2,(pop(&torre)));

	imprime(&torre2);

	return 0;
}
