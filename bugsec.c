#include <stdio.h>
#include <stdlib.h>

typedef struct disco
{
	int elemento;
	struct disco* anterior;
	
}pilha;

void push(pilha** PontPilha1, int elemento)
{
		//aloca uma area de memoria		
		pilha* newDisco= (pilha*)malloc(sizeof(pilha));
		//ela recebe o conteudo pra qual pilha original aponta
		newDisco->anterior= *PontPilha1;
		//o elemento dela recebe o parametro da funcao
		newDisco->elemento=elemento;
		//o conteudo da pilha que aponta sempre pra o topo recebe esse elemento alocado
		(*PontPilha1)=newDisco;
}

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

//remove e retorna o elemento do topo
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

//uma funcao que verifica se um ponteiro pra pilha é nula se ela for retona 0 se tiver alguma coisa la retorna 1
int verifica(pilha* pilhaOriginal)
{
	if (pilhaOriginal==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}



void move(int op1,int op2,pilha** pilhaOriginal,pilha** pilhaOriginal1,pilha** pilhaOriginal2)
{
	if (op1==op2 || op2<0 || op2>3 || op1<0 || op1>3 )
	{
		printf("movimento invalido\n");
		return;
	}

	//escolhe a primeira torre 

	switch(op1)
		{

		case 1:
			//caso a primeira torre seja a primeira verifica se ela tem disco se sim prosegue com a troca
			if(verifica(*pilhaOriginal))
			{
				//agora que sabemos que ela tem um disco vamo ver se as proximas está vazia se tiver faz pop direto
				switch(op2)
				{
					//caso a torre selecionada pra receber seja a torre 2 e ela estiver vazia push direto
					case 2:
					if (verifica(*pilhaOriginal1)==0)
					{
						push(pilhaOriginal1,pop(pilhaOriginal));
					}
					else
					{
						//CASO ELA NAO ESTEJA VAZIA VAMOS VER SE O ELEMENTO DELA É MAIOR QUE O QUE NOS QUER COLOCAR

						if ((*pilhaOriginal1)->elemento>(*pilhaOriginal)->elemento)
						{
							push(pilhaOriginal1,pop(pilhaOriginal));
						} 
					}
					break;
					//caso a torre selecionada pra receber seja a torre 3 e ela estiver vazia push direto
					case 3:
					if (verifica(*pilhaOriginal2)==0)
					{
						push(pilhaOriginal2,pop(pilhaOriginal));
					}
					else
					{
						//CASO ELA NAO ESTEJA VAZIA VAMOS VER SE O ELEMENTO DELA É MAIOR QUE O QUE NOS QUER COLOCAR

						if ((*pilhaOriginal2)->elemento>(*pilhaOriginal)->elemento)
						{
							push(pilhaOriginal2,pop(pilhaOriginal));
						} 
					}
					break;
				}
			}
			else
			{
				printf("movimento invalido\n");
				return;
			}
		break;

		case 2:
			//caso a primeira torre seja a segunda verifica se ela tem disco se sim prosegue com a troca
			if(verifica(*pilhaOriginal1))
			{
				//agora que sabemos que ela tem um disco vamo ver se as proximas está vazia se tiver faz pop direto
				switch(op2)
				{
					//caso a torre selecionada pra receber seja a torre 1 e ela estiver vazia push direto
					case 1:
					if (verifica(*pilhaOriginal)==0)
					{
						push(pilhaOriginal,pop(pilhaOriginal1));
					}
					else
					{
						//CASO ELA NAO ESTEJA VAZIA VAMOS VER SE O ELEMENTO DELA É MAIOR QUE O QUE NOS QUER COLOCAR

						if ((*pilhaOriginal)->elemento>(*pilhaOriginal1)->elemento)
						{
							push(pilhaOriginal,pop(pilhaOriginal1));
						} 
					}
					break;
					//caso a torre selecionada pra receber seja a torre 3 e ela estiver vazia push direto
					case 3:
					if (verifica(*pilhaOriginal2)==0)
					{
						push(pilhaOriginal2,pop(pilhaOriginal1));
					}
					else
					{
						//CASO ELA NAO ESTEJA VAZIA VAMOS VER SE O ELEMENTO DELA É MAIOR QUE O QUE NOS QUER COLOCAR

						if ((*pilhaOriginal2)->elemento>(*pilhaOriginal1)->elemento)
						{
							push(pilhaOriginal2,pop(pilhaOriginal1));
						} 
					}
					break;
				}
			}
			else
			{
				printf("movimento invalido\n");
				return;
			}
		break;

		case 3:
			//casso a primeira torre seja a terceira verifica se ela tem disco se sim prosegue com a troca
			if(verifica(*pilhaOriginal2))
			{
				//agora que sabemos que ela tem um disco vamo ver se as proximas está vazia se tiver faz pop direto
				switch(op2)
				{
					//caso a torre selecionada pra receber seja a torre 1 e ela estiver vazia push direto
					case 1:
					if (verifica(*pilhaOriginal)==0)
					{
						push(pilhaOriginal,pop(pilhaOriginal2));
					}
					else
					{
						//CASO ELA NAO ESTEJA VAZIA VAMOS VER SE O ELEMENTO DELA É MAIOR QUE O QUE NOS QUER COLOCAR

						if ((*pilhaOriginal)->elemento>(*pilhaOriginal2)->elemento)
						{
							push(pilhaOriginal,pop(pilhaOriginal2));
						} 
					}
					break;
					//caso a torre selecionada pra receber seja a torre 3 e ela estiver vazia push direto
					case 2:
					if (verifica(*pilhaOriginal1)==0)
					{
						push(pilhaOriginal1,pop(pilhaOriginal2));
					}
					else
					{
						//CASO ELA NAO ESTEJA VAZIA VAMOS VER SE O ELEMENTO DELA É MAIOR QUE O QUE NOS QUER COLOCAR

						if ((*pilhaOriginal1)->elemento>(*pilhaOriginal2)->elemento)
						{
							push(pilhaOriginal1,pop(pilhaOriginal2));
						} 
					}
					break;
				}
			}
			else
			{
				printf("movimento invalido\n");
				return;
			}
		break;

		default:

			printf("movimento invalido\n");
			return;	
	}
}


int printaDisco(pilha** pilhaOriginal,pilha** pilhaOriginal1,pilha** pilhaOriginal2,int quantdis)
{
	pilha* temp= *pilhaOriginal;
	pilha* temp1= *pilhaOriginal1;
	pilha* temp2=	*pilhaOriginal2;

	short int p1=0,p2=0,p3=0;
	short int qdiscos=quantdis;

		//AGORA É A HORA DA GAMBIARRA MASTER ULTRA
		//CRIA UM WHILE PRA NAVEGAR NA PILHA E VER QUANTOS ELEMENTOS NOS TEMOS PRA POR OS ZEROS PRIMEIRO
		
		do
		{
			if (temp!=NULL)
			{
				p1++;
				temp=temp->anterior;
			}
			

			if (temp1!=NULL)
			{
				p2++;
				temp1=temp1->anterior;
			}
			

			if (temp2!=NULL)
			{
				p3++;
				temp2=temp2->anterior;
			}
			
			qdiscos--;

		}
		while(qdiscos>0);


		//printf("eu sei que tem %i na primeira %i na segunda e %i na terceira \n", p1,p2,p3);

		// esse é o mesmo while de cima so que esse printa sei la

		  temp= *pilhaOriginal;
		  temp1= *pilhaOriginal1;
		  temp2=	*pilhaOriginal2;

		  if (p2==quantdis || p3==quantdis)
		  {
		  	
		  	return 0;
		  }


		  p1=quantdis-p1;
		  p2=quantdis-p2;
		  p3=quantdis-p3;

		do
		{

			/*---	backup--------\\
			printf("%i ",temp->elemento );
			temp=temp->anterior;
			printf("%i\n",temp->elemento );
			*/

			if (p1>0)
			{
				printf("   0        ");
				p1--;
			}
			else
			{
				printf("   %i        ",temp->elemento );
				temp=temp->anterior;
			}	


			if (p2>0)
			{
				printf("   0         ");
				p2--;
			}
			else
			{
				printf("   %i         ",temp1->elemento );
				temp1=temp1->anterior;
			}

			if (p3>0)
			{
				printf("0         ");
				p3--;
			}
			else
			{
				printf("%i        ",temp2->elemento );
				temp2=temp2->anterior;
			}

			printf("\n");
			quantdis--;

		}
		while(quantdis>0);
		printf("torre 1   torre 2   torre 3\n");
		//printf("primeiro digite o numero da torre que tem o disco\n");
		//printf("depois digite o numero da torre que vai receber o disco\n");
		printf("EX: 1 2\n");

		return 1;
}



int main()
{
	pilha* P1 =NULL;
	pilha* P2 =NULL;
	pilha* P3 =NULL;
	int quantdis;
	//Dificuldade
	char DFC;

	printf("Bem vindo a torre de hannoi\n");
	printf("Escolha a dificuldade A=Fácil B=Médio C=Difícil\n");
	
	scanf("%c",&DFC);

	switch (DFC)
	{
		case 'A':
			quantdis=3;
			primeirosDiscos(&P1,3);
			//printf("o topo de P2 é %i \n",P2->elemento);
		
			
		break;
		case 'B':
			quantdis=5;
			primeirosDiscos(&P1,5);
			
		break;
		case 'C':
			quantdis=7;
			primeirosDiscos(&P1,7);
			
		break;
		default:
		printf("estou vendo que tem dificuldade por padrão (Fácil) foi selecionado\n");
		quantdis=3;
		primeirosDiscos(&P1,3);
	}
		printaDisco(&P1,&P2,&P3,quantdis);
		int op1,op2;
		do
		{
			
			scanf("%i %i",&op1,&op2);
			
			system("clear");
			move(op1,op2,&P1,&P2,&P3);
			 
		}while(printaDisco(&P1,&P2,&P3,quantdis));
		
		printf("PARABENS VOCE GANHOU!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		

	
	return 0;
}
