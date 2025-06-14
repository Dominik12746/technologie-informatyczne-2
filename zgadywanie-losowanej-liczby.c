#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand(time(&t));
    int losowa = rand() % 20 + 1;
    int ilosc = 1;
    printf("Wylosowano liczbe \n");
    printf("Podaj liczbe od 1 do 20 \n");

    int liczba;
    if (scanf("%d", &liczba) != 1) {
        printf("To nie jest liczba program zostanie zakonczony\n");
        return 1;
    }

    while (losowa != liczba) {
        if (losowa > liczba) {
            printf("Podana liczba jest mniejsza od szukanej \n");
        } else if (losowa < liczba) {
            printf("Podana liczba jest wieksza od szukanej \n");
        }
        ilosc++;

        printf("Wprowadz ponownie liczbe \n");

        if (scanf("%d", &liczba) != 1) {
            printf("To nie jest liczba program zostanie zakonczony\n");
            return 1;
        }
    }

    if (losowa == liczba) {
        printf("Zgadles w %d probach", ilosc);
    }

    return 0;
}
