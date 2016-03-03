#include <stdlib.h>
#include <stdio.h>

typedef struct heap Heap;

struct heap {
  int n;
  int max_n;
  int *vet; 
};


void cria_heap (Heap *heap, int max_n) {
  heap->n = 0;
  heap->n = max_n;
  heap->vet = (int *) calloc (sizeof(int), max_n);
}

void destroi_heap(Heap *heap) {
  heap->n = 0;
  free (heap->vet);
}

int pai(int i) { return (i - 1) / 2; }
int filho_esq (int i) { return 2 * i + 1; }
int filho_dir (int i) { return 2 * i + 2; }

int existe_pai(int i) { return i > 0; }
int existe_filho_esq (int i, int n) { return (2 * i + 1) < n; }
int existe_filho_dir (int i, int n) { return (2 * i + 2) < n; }

void insere(Heap *heap, int elem) {

  if (heap->n + 1 == heap->max_n) {
     printf("Heap lotado! \n");
    exit(-1);
  }
  else {
    int i = heap->n;

    while (existe_pai(i) && heap->vet[pai(i)] < elem) {
      heap->vet[i] = heap->vet[pai(i)];
      i = pai(i);
    }
    heap->vet[i] = elem;
    heap->n++;
  }
}

void desce_raiz(Heap* heap, int pos_raiz) {
  int raiz = heap->vet[pos_raiz];
  int i = pos_raiz;
  
  while ((existe_filho_esq(i, heap->n) && raiz < heap->vet[filho_esq(i)]) ||
	 (existe_filho_dir(i, heap->n) &&
	  raiz <  heap->vet[filho_dir(i)])) {
    int j = filho_esq(i);
    if (existe_filho_dir(i, heap->n) &&
	heap->vet[filho_dir(i)] >  heap->vet[filho_esq(i)])
      j = filho_dir(i);
    heap->vet[i] = heap->vet[j];
    i = j;
  }
  
  heap->vet[i] = raiz;
}

int remove_max(Heap* heap) {
  if (heap->n == 0) {
    printf("Heap lotado! \n");
    exit(-1);
  }
  else {
    int elem = heap->vet[0];
    heap->n--;
    heap->vet[0] = heap->vet[heap->n];
    desce_raiz(heap, 0);	
    return elem;
  }
}

void monta_heap(Heap* heap, int* vet, int n) {
  int i;
  
  heap->n = n;
  heap->max_n = n;
  heap->vet = vet;
  
  for (i = n / 2; i >= 0; i--)
    desce_raiz(heap, i);
}

int vazio(Heap* heap) {
  return heap->n == 0;
}

void exibe_vetor(int vet[], int n_elem) {
  int i;
  for (i =0; i < n_elem; i++)
    printf("%d ", vet[i]);
  printf("\n");
}

void heapsort(int *vet, int n) {
  Heap heap;
  int i;
  
  monta_heap(&heap, vet, n);

  for (i = 0; i < n; i++) {
    int aux = remove_max(&heap);
    vet[heap.n] = aux;
  }
}

