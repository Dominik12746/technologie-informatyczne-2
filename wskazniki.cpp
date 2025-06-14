
#include <iostream>

    void sum(const int *ptrA, const int *ptrB, int *ptrResult) {
        *ptrResult = *ptrA + *ptrB;
    }

    void minus(const int *ptrA, const int *ptrB, int *ptrResult) {
    *ptrResult = *ptrA - *ptrB;
}
    void multi(const int *ptrA, const int *ptrB, int *ptrResult) {
    *ptrResult = *ptrA * *ptrB;
}
void division(const int *ptrA, const int *ptrB, float *ptrResult) {
    *ptrResult = (float) *ptrA / *ptrB;
}

    int main() {
        int a = 2;
        int b = 5;
        int result = 0;
        float dresult = 0;
        sum(&a, &b, &result);
        printf("%d + %d = %d\n", a, b, result);
        minus(&a, &b, &result);
        printf("%d - %d = %d\n", a, b, result);
        multi(&a, &b, &result);
        printf("%d * %d = %d\n", a, b, result);
        division(&a, &b, &dresult);
        printf("%d / %d = %f\n", a, b, dresult);
        return 0;
    }