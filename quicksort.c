#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include <windows.h>

void quicksort(int *vet, int p, int r)
{
	int q;
	if (p<r)
	{
		q=particionar(vet, p, r);
		quicksort(vet, p, q-1);
		quicksort(vet, q+1, r);
	}	
}
void quicksort_aleatorio(int *vet, int p, int r)
{
	int q;
	if (p<r)
	{
		q=particionar_aleatorio(vet, p, r);
		quicksort_aleatorio(vet, p, q-1);
		quicksort_aleatorio(vet, q+1, r);
	}	
}

int particionar (int *vet, int p, int r)
{
	int x= vet[r];
	int j, i=p-1;
	for(j=p;j<r;j++)
		{
			if(vet[j]<=x)
				{
					i++;
					trocaQ(vet,i,j);
				}
		}
trocaQ(vet, i+1, r);
return (i+1);
}

int particionar_aleatorio (int *vet, int p, int r)
{
	int randI;
	srand(time(NULL));
	randI=p + (rand() %(r-p));
	trocaQ(vet, r, randI);	
return particionar(vet, p, r);
}

void trocaQ(int *vet, int i, int j)
{
	int temp = vet[i];
	vet[i]=vet[j];
	vet[j]=temp;
}

