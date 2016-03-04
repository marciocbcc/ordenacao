#include "bucketSort.h"
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <winsock2.h>
#include <windows.h>

int main() 
{
int n,respostaMenuIncial;
int jaEstaOrdenado=0;
printf("***************CRIAR VETOR************\n");
printf("Digite o tamanho do Vetor: \n");
scanf("%d",&n);
int vetor[n];
preencherVetor(vetor,n);

//gerarCepBelem(vetor,n);
printf("O VETOR CRIADO FOI PREENCHIDO COM VALORES ALEATORIOS !!!!!!!!!\n");

do
{
printf("\n\n*****************MENU****************");
printf("\n\n1-IMPRIMIR VETOR ");
printf("\n2-ORDENAR VETOR ");
printf("\n3-BUSCA NO VETOR ");
printf("\n4-LIMPAR TELA ");
printf("\n5-INVERTER VETOR ");
printf("\n0-ENCERRAR\n\nRESPOSTA:  ");

scanf("%d",&respostaMenuIncial);
if (respostaMenuIncial==1)
	{
	imprimirVetor(vetor,n);
	}
	else if (respostaMenuIncial==2)
		{
			menuOrdenacao(vetor, n, &jaEstaOrdenado);
			prosseguir ();
		}
	else if (respostaMenuIncial==3)
		{
			menuBusca(vetor, n, &jaEstaOrdenado);
			prosseguir ();			
		}
	else if (respostaMenuIncial==4)
		{
			system("cls");
		}
	else if (respostaMenuIncial==5)
		{
			inverterVetor(vetor,n);
			prosseguir ();			
		}
	else if(respostaMenuIncial!=0)
		{
			printf("VALOR INCORRETO\n\n");
			prosseguir ();
		}
	
}while(respostaMenuIncial!=0);

}//////////////fim main


