#include <stdio.h>
#define SIZE 10

void printarray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

void menu(void) {
    printf("1. Wygeneruj liczby w tablicy\n");
    printf("2. Wyswietl liczby z tablicy\n");
    printf("3. Wyswietl najnizsza wartosc\n");
    printf("4. Wyswietl najwyzsza wartosc\n");
    printf("5. Wyswietl srednia wartosc\n");
    printf("6. Zapisz wartosci tablicy do pliku\n");
    printf("7. Wczytaj wartosci tablicy z pliku\n");
    printf("0. Zakoncz\n");
    printf("Wybierz opcje: ");
}

int findminimum(int array[], int size) {
    int minimum = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
    }
    return minimum;
}

int findmaximum(int array[], int size) {
    int maximum = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

float calculateAverage(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return (float) sum / size;
}

int savearraytofile(int array[]) {
    FILE *fptr = fopen("D:\\255947\\plik.txt", "w");
    if (fptr == NULL) {
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        fprintf(fptr, "%d\n", array[i]);
    }
    fclose(fptr);
    return 0;
}

int restorearraytofile(int array[]) {
    FILE *fptr = fopen("D:\\255947\\plik.txt", "r");
    if (fptr == NULL) {
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        fscanf(fptr, "%d", &array[i]);
    }
    fclose(fptr);
    return 0;
}

int main() {
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int option = 0;
    int errorcode = 0;

    printf("Tablica\n\n");

    do {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                printf("Funkcja generowania nie jest zaimplementowana.\n\n");
                break;
            case 2:
                printarray(array, SIZE);
                break;
            case 3:
                printf("Najnizsza wartosc: %d\n\n", findminimum(array, SIZE));
                break;
            case 4:
                printf("Najwieksza wartosc: %d\n\n", findmaximum(array, SIZE));
                break;
            case 5:
                printf("Srednia wartosc: %.2f\n\n", calculateAverage(array, SIZE));
                break;
            case 6:
                printf("Zapisuje dane do pliku...\n");
                errorcode = savearraytofile(array);
                if (!errorcode) {
                    printf("Tablica zapisana.\n\n");
                } else {
                    printf("Blad zapisu tablicy.\n\n");
                }
                break;
            case 7:
                printf("Wczytuje dane z pliku...\n");
                errorcode = restorearraytofile(array);
                if (!errorcode) {
                    printf("Tablica wczytana.\n\n");
                } else {
                    printf("Blad wczytania tablicy.\n\n");
                }
                break;
            default:
                printf("Wybierz poprawna opcje.\n\n");
        }

    } while (option != 0);

    printf("Koniec programu.\n");
    return 0;
}