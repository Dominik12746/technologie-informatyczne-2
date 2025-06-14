#include <stdio.h>
#define SIZE 10

int main() {
    char marki[SIZE][30];
    int roczniki[SIZE];
    int przebiegi[SIZE];
    int liczba = 0;
    int opcja = 0;

    do {
        printf("1. Dodaj samochod\n");
        printf("2. Wyswietl samochody\n");
        printf("3. Zapisz dane do pliku\n");
        printf("4. Wczytaj dane z pliku\n");
        printf("0. Zakoncz\n");
        printf("Wybierz opcje: ");
        scanf("%d", &opcja);

        switch(opcja) {
            case 1:
                if (liczba >= SIZE) {
                    printf("Osiagnieto limit samochodow\n\n");
                    break;
                }
                printf("Podaj marke: ");
                scanf("%s", marki[liczba]);
                printf("Podaj rocznik: ");
                scanf("%d", &roczniki[liczba]);
                printf("Podaj przebieg: ");
                scanf("%d", &przebiegi[liczba]);
                liczba++;
                break;

            case 2:
                for (int i = 0; i < liczba; i++) {
                    printf("Samochod %d:\n", i+1);
                    printf("Marka: %s\n", marki[i]);
                    printf("Rocznik: %d\n", roczniki[i]);
                    printf("Przebieg: %d\n\n", przebiegi[i]);
                }
                break;

            case 3: {
                FILE *plik = fopen("D:\\255941\\samochody.txt", "w");
                if (plik == NULL) {
                    printf("Blad otwarcia pliku\n\n");
                    break;
                }
                fprintf(plik, "%d\n", liczba);
                for (int i = 0; i < liczba; i++) {
                    fprintf(plik, "%s %d %d\n", marki[i], roczniki[i], przebiegi[i]);
                }
                fclose(plik);
                printf("Dane zapisane do pliku\n\n");
                break;
            }

            case 4: {
                FILE *plik = fopen("D:\\255941\\samochody.txt", "r");
                if (plik == NULL) {
                    printf("Brak pliku lub blad otwarcia\n\n");
                    break;
                }
                fscanf(plik, "%d", &liczba);
                for (int i = 0; i < liczba; i++) {
                    fscanf(plik, "%s %d %d", marki[i], &roczniki[i], &przebiegi[i]);
                }
                fclose(plik);
                printf("Dane wczytane z pliku\n\n");
                break;
            }

            case 0:
                printf("Koniec programu\n");
                break;

            default:
                printf("Nieznana opcja\n\n");
        }

    } while (opcja != 0);

    return 0;
}