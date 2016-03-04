#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void preencherVetor(int vetor[], int n);
void imprimirVetor(int vetor[], int n);
void bubbleSort(int vetor[], int n);
void insertionSort(int vetor[],int n);
void selectionSort(int vetor[], int n);
void shellSort(int vetor[],int n);
int buscaSequencial(int vetor[], int valorbuscado , int n);
int buscaBinaria(int vetor[],int inicio,int fim,int valorbuscado);
void menuOrdenacao(int vetor[], int n, int *jaEstaOrdenado);
void menuBusca(int vetor[], int n, int *jaEstaOrdenado);
void prosseguir (void);
void inverterVetor(int vetor[],int n);

