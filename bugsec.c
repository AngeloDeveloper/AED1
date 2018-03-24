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
		//printf("a quantidade de discos que chegou aqui foi %i \n",quantdis );
		
		int i=quantdis;;
		for ( i = i; i >0; i--)
		{
			//printf("chamando a função push pra colocar o numero %i la dentro\n",i );
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


int pop(pilha** topo)
{
	//printf("%i",(*remover)->elemento);
	
	//auxiliar recebe topo atual
	pilha* auxiliar=*topo;
	//elemento recebe o elemento atual
	int elemento=(*topo)->elemento;
	//topo desce um nível
	*topo=(*topo)->anterior;
	//limpa auxiliar que é topo anteriro
	free(auxiliar);

	return elemento;



}




void printaDisco(pilha** pilhaOriginal,pilha** pilhaOriginal1,pilha** pilhaOriginal2)
{
	pilha* temp= *pilhaOriginal;
	pilha* temp1= *pilhaOriginal1;
	pilha* temp2=	*pilhaOriginal2;

		
		do
		{

			/*---	backup--------\\
			printf("%i ",temp->elemento );
			temp=temp->anterior;
			printf("%i\n",temp->elemento );
			*/

			if (temp==NULL)
			{
				printf("0 ");
			}
			else
			{
				printf("%i ",temp->elemento );
				temp=temp->anterior;
			}	


			if (temp1==NULL)
			{
				printf("0 ");
			}
			else
			{

			}

			if (temp2==NULL)
			{
				printf("0");
			}
			else
			{

			}

			printf("\n");

		}
		while(temp->anterior!=NULL);
		

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
			//printf("o topo de P2 é %i \n",P2->elemento);
		
			
		break;
		case 'B':
			primeirosDiscos(&P1,5);
			
		break;
		case 'C':
			primeirosDiscos(&P1,7);
			
		break;
	}


		

			printaDisco(&P1,&P2,&P3);

		


	
	return 0;
}
