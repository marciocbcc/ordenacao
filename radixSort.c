#include "radixSort.h"
 
void radixSort(int *vetor, int size) {
     int i, b[size], m = 0, exp = 1;
     /** Encontra o maior valor do vetor para saber quantos digitos ele tem **/
     for (i = 0; i < size; i++) {
         if (vetor[i] > m)
         m = vetor[i];
     }
     /** Repete-se o processo at� o maior digito significativo **/
     while (m / exp > 0) {
           int box[10] = { 0 }; /** Inicaliza o vetor box com 0's. **/
           for(i = 0; i < size; i++)
               /** Para os algarismos(0-9) conta quantos elementos existem de cada valor.
               Com o while repete-se o mesmo processo para cada d�gito **/
              box[vetor[i] / exp % 10]++;
           for(i = 1; i < 10; i++)
               // calcula as posi��es dos digitos no vetor
               box[i] += box[i - 1];
           /** coloca os elementos no vetor b em suas posi��es,
           onde os n�meros com d�gitos analisados de menor valor
           ficam nas primeiras posi��es **/
           for(i = size - 1; i >= 0; i--)
               b[--box[vetor[i] / exp % 10]] = vetor[i];

           /** Atualiza o vetor. Copiando o vetor b para o vetor. No final do while o vetor estar� ordenado **/
           for(i = 0; i < size; i++)
               vetor[i] = b[i];
           exp *= 10; /** Aumenta expoente que pegar� o pr�ximo digito do numero **/
     }
}
