#include <stdio.h>
#include <stdlib.h>

typedef struct disco
{
	int elemento;
	struct disco* anterior;
	
}pilha;

//inicia a quantidade de discos de acordo com dificuldade
void primeirosDiscos(pilha** PontPilha,int quantdis)
{
		printf("a quantidade de discos que chegou aqui foi %i \n",quantdis );
		
		int i=quantdis;;
		for ( i = i; i >0; i--)
		{
			printf("chamando a função push pra colocar o numero %i la dentro\n",i );
			push(PontPilha,i);
		}
}


void push(pilha** PontPilha1, int elemento)
{
		
		pilha* newDisco= (pilha*)malloc(sizeof(pilha));
		newDisco->anterior= *PontPilha1;

		newDisco->elemento=elemento;

		(*PontPilha1)=newDisco;

	
}

void printaDisco(pilha** ponteiro)
{
	pilha** temp=ponteiro;


		do
		{
			printf("elemento é: %i\n",(*ponteiro)->elemento );
			*temp=(*temp)->anterior;
		}
		while((*temp)->anterior!=NULL);


}



int main()
{
	pilha* P1 =NULL;
	pilha* P2 =NULL;
	pilha* P3 =NULL;

	//Dificuldade
	char DFC;

	printf("Bem vindo a torre de hannoi\n");
	printf("Escolha a dificuldade A=Fácil B=Médio C=Difícil\n");
	
	scanf("%c",&DFC);

	switch (DFC)
	{
		case 'A':
			primeirosDiscos(&P1,3);
			printaDisco(&P1);
		break;
		case 'B':
			primeirosDiscos(&P1,5);
			printaDisco(&P1);
		break;
		case 'C':
			primeirosDiscos(&P1,7);
		break;
	}



	
	return 0;
}
