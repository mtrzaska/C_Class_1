#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    // Przechowywanie wartości typu int
    data.i = 10;
    printf("Wartość całkowita: %d\n", data.i);

    // Przechowywanie wartości typu float
    data.f = 3.14;
    printf("Wartość zmiennoprzecinkowa: %f\n", data.f);

    // Przechowywanie wartości typu char
    data.c = 'A';
    printf("Wartość znaku: %c\n", data.c);

    return 0;
}
