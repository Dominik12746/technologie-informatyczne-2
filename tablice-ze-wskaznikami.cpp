
#include <iostream>
#define SIZE 10

void printarray(int *array) {
    for (int i = 0; i < SIZE; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
        printf("*(%p) = %d\n\n", array + i, *(array + i));
    }
}

void menu(void) {
    printf("1. Wygeneruj liczby w tablicy\n");
    printf("2. Wyswietl liczby z tablicy\n");
    printf("3. Wyswietl najnizszom wartosc\n");
    printf("4. Wyswietl najwyszom wartosc\n");
    printf("5. Wyswietl sredniom wartosc\n");
    printf("6. Wyswietl mediane\n");
    printf("0. Zakoncz\n");
    printf("Wybierz opcje\n");
}

int findminimum (int *array, int size) {
    int minimum = *array;
    for (int i = 1; i < SIZE; ++i) {
        if (*(array + i) < minimum) {
            minimum = *(array + i);
        }
    }
    return minimum;
}
int findmaximum (int *array, int size) {
    int maximum = *array;
    for (int i = 1; i < SIZE; ++i) {
        if (*(array + i) > maximum) {
            maximum = *(array + i);
        }
    }
    return maximum;
}
float calculateAverage (int *array, int size) {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += *(array + i);
    }
    return (float) sum / SIZE;
}

int mediana (int *array, int n) {
    float mediana;
    if (n%2 ==0){
        mediana = array[(n-1)/2]+array[n/2];
        mediana = mediana/2;
    }
    else
    {
        mediana = array[n/2];
    }
    return mediana;
}

int main() {
    int array[SIZE] {-13, 2, -20, 4, 5, 6, 7, 8, 9, 10};
    int option = 0;

    printf("Tablica\n\n");

    do {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                printf("cos\n\n");
                break;
            case 2:
                printarray(array);
                break;
            case 3:
                printf("Najnizsza wartosc: %d\n\n", findminimum(array, sizeof (array)/sizeof(int)));
                break;
            case 4:
                printf("Najwieksza wartosc: %d\n\n", findmaximum(array, sizeof (array)/sizeof(int)));
                break;
            case 5:
                printf("Srednia wartosc: %f\n\n", calculateAverage(array, sizeof (array)/sizeof(int)));
                break;
            case 6:
                printf("Mediana: %d\n\n", mediana(array, sizeof (array)/sizeof(int)));
                break;
            default:
                printf("Wybierz poprawna opcje\n\n");
        }

    } while (option != 0);

    printf("koniec\n");

    return 0;
}