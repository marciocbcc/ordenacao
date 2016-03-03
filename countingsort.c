#include <stdio.h>
#include <stdlib.h>
#include "countingsort.h"
int *countingSort(int vetor[], int tam, int numMax)
{
	int c[numMax];
	int aux[tam];
	int i,j;
	for(i = 0; i <= numMax; i++)
	{
		c[i] = 0;
	}
	
	for(i = 1; i <= tam; i++)
	{
		c[vetor[i]] = c[vetor[i]] + 1;
	}
	for(i = 1; i <= numMax; i++)
	{
		c[i] = c[i] + c[i-1]; 
	}
	for(i = tam; i >= 1; i--)
	{
	 aux[c[vetor[i]]] = vetor[i];
	 c[vetor[i]] = c[vetor[i]] - 1;
		  
	}
	
	for(i = 0; i < tam; i++)
	{		
		vetor[i]= aux[i];
	}

	return vetor;
}


