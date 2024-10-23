#include <stdio.h>
#include <stdlib.h>

void selectionsort_parcial(int v[], int k, int n){
    int i, j, min, temp;
    for(i = 0; i < k; i++){  // Apenas itere até k, ao invés de n
        min = i;
        for(j = i + 1; j < n; j++){  // Procura o menor elemento no restante do vetor
            if(v[j] < v[min]){
                min = j;
            }
        }   
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

void ordenacao_parcial(int v[], int k, int n ){
    if(k <= n){
        selectionsort_parcial(v, k, n);  // Chama a função de ordenação parcial
    }
}


void merge(int vet[], int e1, int d1, int e2, int d2) {
    int *aux = (int*) malloc (sizeof(int)* (d1-e1 + d2-e2 + 2));
    int j = e1;
    int p = 0;
    int k = e2;

    while((j<=d1 )&&(k<=d2)){
        if(vet[j] < vet[k])
            aux[p++]= vet[j++];
        else
            aux[p++] = vet[k++];
    }
    for(;j<=d1;j++)
        aux[p++]= vet[j];

    for(;j<=d1;j++)
        aux[p++]= vet[k];

    p=0;
    
    for(j = e1; j <= d1; j++)
        vet[j] = aux[p++];

    for(k = e2; k <= d2; k++)
        vet[k] = aux[p++];   
}


int main(){
    /*int v[10] = {11,13,5,17,3,9,8,6,14,20};

    printf("Vetor original:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    ordenacao_parcial(v,10,10);  // Ordena parcialmente os 4 primeiros elementos

    printf("Vetor após ordenação parcial dos k primeiros elementos:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");*/

    int vet[] = {7, 2, 9, 15, 8, 6, 3, 4, 10, 12, 5, 3};
    int e1 = 1, d1 = 3, e2 = 6, d2 = 9;

    for (int i = 0; i < 12; i++) 
        printf("%d ", vet[i]);

    printf("\n");

    merge(vet, e1, d1, e2, d2);

    // Print the merged array
    for (int i = 0; i < 12; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}