#include <stdio.h>

void select_sort(int v[], int n){
    int i, j, min, x;

    for(i = 0; i < n-1; i++){
        min = i;

        for(j = i+1; j < n; j++)
            if(v[j] < v[min]) min = j;

            x = v[i];
            v[i] = v[min];
            v[min] = x;
    }
}

void insertion_sort(int vet[], int n){
    int i, j, x;
    for(j = 1; j < n; j++){
        x = vet[j];

        for(i = j-1; i >= 0 && vet[i] > x; i--)
            vet[i+1] = vet[i];

        vet[i+1] = x;
    }
}



int main (){
    int vet[5] = {4, 8, 1, 0, 6};

    //select_sort(vet, 5);
    insertion_sort(vet, 5);

    for(int i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}