#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char imie[50];
    float ocena;
};

void sortujStudentow(struct Student *tablica, int rozmiar) {
    int i, j;
    struct Student temp;

    for (i = 0; i < rozmiar - 1; i++) {
        for (j = 0; j < rozmiar - 1 - i; j++) {
            if (tablica[j].ocena < tablica[j + 1].ocena) {
                temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int liczba_studentow = 100;
    struct Student studenci[liczba_studentow];

    srand(time(NULL));
    for (int i = 0; i < liczba_studentow; i++) {
        sprintf(studenci[i].imie, "Student%d", i + 1);
        studenci[i].ocena = (float)(rand() % 101) / 10.0; 
    }

    sortujStudentow(studenci, liczba_studentow);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < liczba_studentow; i++) {
        printf("Student: %s, Ocena: %.1f\n", studenci[i].imie, studenci[i].ocena);
    }

    return 0;
}
