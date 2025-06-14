
#include <stdio.h>
#define SIZE 10

int main() {

    int tablica[10] = {1,2,3,-6,8,4,1,8,5,9,};

    for (int i = 0; i < SIZE; i++){
        printf("tablica[%d]: %d\n",i, tablica[i]);
    }
    int min = tablica[0];
    for (int i = 1; i < SIZE; i++) {
        if (min > tablica[i]){
            min = tablica[i];
        }
    }
        printf("wartosc min %d\n", min);

    int max = tablica[0];
    for(int i = 1; i < SIZE; i++) {
        if(max < tablica[i]){
            max = tablica[i];
        }
    }
    printf("wartosc max %d\n", max);

    int suma = 0;
    for (int i = 0; i < SIZE; i++) {
        suma += tablica[i];
    }
    printf("suma wynosi: %d\n", suma);
    float average = 0;
    average = (float)suma / SIZE;
    printf("srednia wynosi: %.2f\n", average);

    return 0;
}