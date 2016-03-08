#include "radixSort.h"
 
void radixSort(int *vetor, int size) {
     int i, b[size], m = 0, exp = 1;
     /** Encontra o maior valor do vetor para saber quantos digitos ele tem **/
     for (i = 0; i < size; i++) {
         if (vetor[i] > m)
         m = vetor[i];
     }
     /** Repete-se o processo até o maior digito significativo **/
     while (m / exp > 0) {
           int box[10] = { 0 }; /** Inicaliza o vetor box com 0's. **/
           for(i = 0; i < size; i++)
               /** Para os algarismos(0-9) conta quantos elementos existem de cada valor.
               Com o while repete-se o mesmo processo para cada dígito **/
              box[vetor[i] / exp % 10]++;
           for(i = 1; i < 10; i++)
               // calcula as posições dos digitos no vetor
               box[i] += box[i - 1];
           /** coloca os elementos no vetor b em suas posições,
           onde os números com dígitos analisados de menor valor
           ficam nas primeiras posições **/
           for(i = size - 1; i >= 0; i--)
               b[--box[vetor[i] / exp % 10]] = vetor[i];

           /** Atualiza o vetor. Copiando o vetor b para o vetor. No final do while o vetor estará ordenado **/
           for(i = 0; i < size; i++)
               vetor[i] = b[i];
           exp *= 10; /** Aumenta expoente que pegará o próximo digito do numero **/
     }
}
