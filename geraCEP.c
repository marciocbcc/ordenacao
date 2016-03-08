#include "gerarCEP.h"
#include <winsock2.h>

void gerarCepBelem(int vetor[], int n){
	
	int MAX=999;
		int i;
		srand(time(NULL));
		for (i=0;i<n;i++)
			{
			vetor[i]=66000000+(rand()%MAX)*1000+rand()%MAX;
			}
	
}
