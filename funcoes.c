#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <winsock2.h>
#include "bucketSort.h"
#include "gerarCEP.h"

////////////////////////////
void preencherVetor(int vetor[], int n)
	{
	int MAX=100;
		int i;
		srand(time(NULL));
		for (i=0;i<n;i++)
			{
			vetor[i]=rand()%MAX;
			}
	}
	
	
///////////////////////////
void imprimirVetor(int vetor[], int n)
	{
		int i;
		for (i=0;i<n;i++)
			{
			printf("%d, ",vetor[i]);
			}
	}


////////////////////////////////
void bubbleSort(int vetor[],int n)
{
	int i, j,aux;

		for ( i=0; i<n-1; i++ )
		{
			for ( j=0; j<n-i-1; j++ )
			{

				if ( vetor[j] > vetor[j+1] )

					{
					aux = vetor[j];
					vetor[j] = vetor[j+1];
					vetor[j+1] = aux; 
					}

			}
		

		}
printf("\nVETOR ORDENADO!!!!!!!!!!");
}

/////////////////////////
void insertionSort(int vetor[],int n)
{
     int i,j,eleito;
     for (i=1;i<n;i++)
     {
         eleito=vetor[i];
         j=i-1;
         while ((j>=0) && (eleito<vetor[j]))
         {
         vetor[j+1]=vetor[j];
         j--;
         }
         vetor[j+1]=eleito;
     }
printf("\nVETOR ORDENADO!!!!!!!!!!");
}
/////////////////////////
void selectionSort(int vetor[], int n)
{
int i,j,min,aux;

     for (i=0;i<(n-1);i++)
     {
         min=i;
         for(j=(i+1);j<n;j++)
         {
             if(vetor[j]<vetor[min])
             {
               min=j;
             }
         }
         if(i!=min)
         {
            aux=vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=aux;
         }
     }
printf("\nVETOR ORDENADO!!!!!!!!!!");
}

/////////////////////////

void shellSort(int vetor[],int n) 
{
    int i,j,valor;
    int gap=1;
    while(gap<n) 
	{
        gap=3*gap+1;
    }
    while (gap>1) 
	{
        gap /=3;
        for(i=gap;i<n;i++) 
		{
            valor=vetor[i];
            j=i-gap;
            while(j>=0 && valor<vetor[j]) 
			{
                vetor[j+gap]=vetor[j];
                j-=gap;
            }
            vetor[j+gap]=valor;
        }
    }
printf("\nVETOR ORDENADO!!!!!!!!!!");
}

/////////////////////////
int buscaSequencial(int vetor[], int valorbuscado , int n)
{
     int i;
     for (i=0;i<n;i++)
     {
         if (valorbuscado==vetor[i])
             return i;
     }
     return -1;
}


//////////////////////////
int buscaBinaria(int vetor[],int inicio,int fim,int valorbuscado)
{
	 	if (inicio>fim)
	 		{
	 			return -1;
	 		}
	 	
  		int meio;
 		meio=(inicio+fim)/2;
  		if(vetor[meio]==valorbuscado)
 	 		{
   			return meio;
 	 		}
  		else if (vetor[meio]<valorbuscado)
  			{
   			return buscaBinaria(vetor,meio+1,fim,valorbuscado);
  			}
  		else if  (vetor[meio]>valorbuscado)
  			{
   			return buscaBinaria(vetor,inicio,meio-1,valorbuscado);
  			}
}

///////////////////////////
void menuOrdenacao(int vetor[], int n, int *jaEstaOrdenado)
{
	
int qualOrdenacao;
LARGE_INTEGER tempoInicial, tempoFinal, freq;
float tempoTotal;

printf("\n\nQual tipo ordenacao deseja?: ");
printf("\n\n1-BUBBLE SORT");
printf("\n2-INSERTION SORT");
printf("\n3-SELECTION SORT");
printf("\n4-SHELL SORT");
printf("\n5-QUICK SORT");
printf("\n6-QUICK SORT ALEATORIO");
printf("\n7-COUNTING SORT");
printf("\n8-HEAP SORT");
printf("\n9-BUCKET SORT");
printf("\n10-RADIX SORT");
printf("\nOUTRO-CANCELAR\nRESPOSTA:  ");
scanf("%d",&qualOrdenacao);

if (qualOrdenacao==1)
	{
	QueryPerformanceCounter(&tempoInicial);
	bubbleSort(vetor, n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;
	}
else if (qualOrdenacao==2)
	{
	QueryPerformanceCounter(&tempoInicial);
	insertionSort(vetor, n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;
	}
else if (qualOrdenacao==3)
	{
	QueryPerformanceCounter(&tempoInicial);
	selectionSort(vetor, n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}
else if (qualOrdenacao==4)
	{
	QueryPerformanceCounter(&tempoInicial);
	shellSort(vetor, n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}
else if (qualOrdenacao==5)
	{
	QueryPerformanceCounter(&tempoInicial);
	quicksort(vetor, 0, n-1);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}
else if (qualOrdenacao==6)
	{
	QueryPerformanceCounter(&tempoInicial);
	quicksort_aleatorio(vetor,0, n-1);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}
else if (qualOrdenacao==7)
	{
	int *v,i,k=0;
	for(i = 0; i < n; i++) // preenche o vetor com valores aleatórioos
	{
	 	if(vetor[i] > k)
	 	{	 
	  		k = vetor[i];
     	}
    }
	printf("Maior: %d", k);
	QueryPerformanceCounter(&tempoInicial);
	v=countingSort(vetor,k,n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}
else if (qualOrdenacao==8)
	{
	QueryPerformanceCounter(&tempoInicial);
	heapsort(vetor, n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}
else if (qualOrdenacao==9)
	{
	QueryPerformanceCounter(&tempoInicial);
	Bucket_Sort(vetor, n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}
	else if (qualOrdenacao==10)
	{
	QueryPerformanceCounter(&tempoInicial);
	radix_sort(vetor, n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
	*jaEstaOrdenado=1;	
	}

printf("\nTEMPO EM MILISEGUNDOS: %.20f ms", tempoTotal*1000);
}


///////////////////////////
void menuBusca(int vetor[], int n, int *jaEstaOrdenado)
{
	
int valorbuscado,resultadoBusca,qualBusca;
LARGE_INTEGER tempoInicial, tempoFinal, freq;
float tempoTotal;

printf("\n\nQual tipo busca deseja?: ");
printf("\n\n1-LINEAR");
printf("\n2-BINARIA");
printf("\nOUTRO-CANCELAR\nRESPOSTA:  ");
scanf("%d",&qualBusca);


printf("\n\nDigite o valor pra a busca: ");
scanf("%d",&valorbuscado);


if (qualBusca==1)
	{
	QueryPerformanceCounter(&tempoInicial);	
	resultadoBusca=buscaSequencial(vetor, valorbuscado,n);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
		if (resultadoBusca!=-1)
			{
			printf("\n#### POSICAO #####: %d\n\n",resultadoBusca+1);
			}
			else
				{
					printf("\nValor nao encontrado!");
				}

	}
else if (qualBusca==2)
	{
	if (*jaEstaOrdenado!=1)
	{
	printf("\nO VETOR ESTA DESORDENADO!!!!!! \nVOCE DEVE ORDENALO ANTES DE PROSSEGUIR!!!!!!!!! ");
	printf("\nESCOLHA OMETODO DE ORDENACAO:\n");
	menuOrdenacao(vetor,n,jaEstaOrdenado);	
	}	
	

	QueryPerformanceCounter(&tempoInicial);
	resultadoBusca=buscaBinaria(vetor,0, n-1, valorbuscado);
	QueryPerformanceCounter(&tempoFinal);
	QueryPerformanceFrequency(&freq);
	tempoTotal = (float)(tempoFinal.QuadPart - tempoInicial.QuadPart)/freq.QuadPart;
		if (resultadoBusca!=-1)
			{
			printf("\n#### POSICAO #####: %d\n\n",resultadoBusca+1);
			}
			else
				{
					printf("\nValor nao encontrado!");
				}
	
	}
printf("\nTEMPO EM MILISEGUNDOS: %.20f ms", tempoTotal*1000);
}

/////////////////////////
void prosseguir (void)
{
	printf("\nPressione qualquer tecla para continuar!");
	system("pause>>null");
}

