#include <stdio.h>
#include <stdlib.h>
void cria_heap (Heap *heap, int max_n);
void destroi_heap(Heap *heap);
int pai(int i);
int filho_esq (int i);
int filho_dir (int i);
int existe_pai(int i);
int existe_filho_esq (int i, int n);
int existe_filho_dir (int i, int n);
void insere(Heap *heap, int elem);
void desce_raiz(Heap* heap, int pos_raiz);
int remove_max(Heap* heap);
void monta_heap(Heap* heap, int* vet, int n);
int vazio(Heap* heap);
void exibe_vetor(int vet[], int n_elem);
void heapsort(int *vet, int n);


