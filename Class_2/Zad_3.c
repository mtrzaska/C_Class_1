#include <stdio.h>

struct Point {
    int x;
    int y;
};

void zmienWspolrzedne(struct Point *point, int newX, int newY) {
    point->x = newX;
    point->y = newY;
}

struct Rectangle {
    struct Point topleft;     
    struct Point bottomright; 
};

int poleProstokata(struct Rectangle *rect) {
    int szerokosc = rect->bottomright.x - rect->topleft.x;
    int wysokosc = rect->topleft.y - rect->bottomright.y;
    return szerokosc * wysokosc;
}

int obwodProstokata(struct Rectangle *rect) {
    int szerokosc = rect->bottomright.x - rect->topleft.x;
    int wysokosc = rect->topleft.y - rect->bottomright.y;
    return 2 * (szerokosc + wysokosc);
}

int main() {
    struct Point punkt = {3, 5};

    zmienWspolrzedne(&punkt, 7, 9);

    printf("Nowe wspolrzedne punktu: (%d, %d)\n", punkt.x, punkt.y);

    struct Rectangle prostokat = {{2, 4}, {8, 1}};

    printf("Pole prostokata: %d\n", poleProstokata(&prostokat));

    printf("Obwod prostokata: %d\n", obwodProstokata(&prostokat));

    return 0;
}
