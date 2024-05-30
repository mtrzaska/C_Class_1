#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int choice, x, y;
    int (*operation)(int, int);

    printf("Wybierz operację:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    scanf("%d", &choice);

    printf("Podaj dwie liczby: ");
    scanf("%d %d", &x, &y);

    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = multiply;
            break;
        case 3:
            operation = subtract;
            break;
        default:
            printf("Nieprawidłowy wybór\n");
            return 1;
    }

    int result = operation(x, y);
    printf("Wynik: %d\n", result);

    return 0;
}
