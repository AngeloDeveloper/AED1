
typedef struct fil
{
	struct fil* proximo;
	int elemento;
}filaNo;


typedef struct Tfila
{
	filaNo* inicio;
	filaNo* final;
}fila;





void enqueue(fila** simplefila, int elemento){
		filaNo* novo= (filaNo*)malloc(sizeof(filaNo));

		novo->elemento=elemento;
		
		if((*simplefila)->inicio==NULL || (*simplefila)->final==NULL){
			(*simplefila)->inicio=novo;
			(*simplefila)->final=novo;
		}
		else{
			(*simplefila)->final=((*simplefila)->final)->proximo=novo;
		}
}

int dequeue(fila** simplefila){

	if((*simplefila)->inicio==NULL ||(*simplefila)->final==NULL){
		return 0;
	}
	int retorno= (*simplefila)->inicio->elemento;
	filaNo* aux=(*simplefila)->inicio;
	(*simplefila)->inicio=(*simplefila)->inicio->proximo;
	free(aux);
	return retorno;
}

void printa(fila** aFila)
{
	filaNo* aux=(*aFila)->inicio;

		printf("elemento %i: \n",aux->elemento);
	while(aux->proximo!=NULL){
		aux=aux->proximo;
		printf("elemento %i: \n",aux->elemento);
	}
	
}