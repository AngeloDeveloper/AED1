#include <stdio.h>
#include <stdlib.h>
#include "funcaofila.h"


int main(int argc, char const *argv[])
{
	fila* fila_simples;
	fila_simples->inicio=NULL;
	fila_simples->final=NULL;

	enqueue(&fila_simples,3);
	enqueue(&fila_simples,4);
	enqueue(&fila_simples,5);
	enqueue(&fila_simples,6);

	printa(&fila_simples);

	dequeue(&fila_simples);

	printa(&fila_simples);

	return 0;
}
