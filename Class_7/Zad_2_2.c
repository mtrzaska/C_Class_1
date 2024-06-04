#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} Dice;

int parse_draw(char *str, Dice *draw) {
    draw->red = draw->green = draw->blue = 0;
    int number;
    char color[10];

    while (sscanf(str, "%d %s", &number, color) == 2) {
        // Usuń przecinki i inne niepotrzebne znaki
        color[strcspn(color, ",.;")] = '\0';
        
        if (strcmp(color, "red") == 0) {
            draw->red += number;
        } else if (strcmp(color, "green") == 0) {
            draw->green += number;
        } else if (strcmp(color, "blue") == 0) {
            draw->blue += number;
        }
        
        // Przesuń wskaźnik str do następnego zestawu
        char *next = strstr(str, color) + strlen(color);
        while (*next == ',' || *next == ' ') next++;
        str = next;
    }
    return 1;
}

void find_minimum_set(Dice *draws, int draw_count, Dice *min_set) {
    min_set->red = min_set->green = min_set->blue = 0;
    for (int i = 0; i < draw_count; i++) {
        if (draws[i].red > min_set->red) {
            min_set->red = draws[i].red;
        }
        if (draws[i].green > min_set->green) {
            min_set->green = draws[i].green;
        }
        if (draws[i].blue > min_set->blue) {
            min_set->blue = draws[i].blue;
        }
    }
}

int main() {
    FILE *file = fopen("dane2.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    char line[1024];
    int total_power = 0;

    while (fgets(line, sizeof(line), file)) {
        // Usuń znaki nowej linii z końca linii
        line[strcspn(line, "\n")] = 0;

        char *game_str = strdup(line);
        char *game_id_str = strtok(game_str, ":");
        if (game_id_str == NULL) {
            printf("Error parsing game ID: %s\n", line);
            free(game_str);
            continue;
        }
        int game_id = atoi(&game_id_str[5]);

        char *draw_str = strtok(NULL, ":");
        if (draw_str == NULL) {
            printf("Error parsing draws for game %d: %s\n", game_id, line);
            free(game_str);
            continue;
        }

        char *draw_token;
        Dice draws[100];
        int draw_count = 0;

        draw_token = strtok(draw_str, ";");
        while (draw_token != NULL) {
            parse_draw(draw_token, &draws[draw_count++]);
            draw_token = strtok(NULL, ";");
        }

        Dice min_set;
        find_minimum_set(draws, draw_count, &min_set);

        if (min_set.red > 0 && min_set.green > 0 && min_set.blue > 0) {
            int power = min_set.red * min_set.green * min_set.blue;
            total_power += power;
        } else {
            printf("Game %d has zero values: R=%d, G=%d, B=%d\n", game_id, min_set.red, min_set.green, min_set.blue);
        }

        free(game_str);
    }

    fclose(file);
    printf("Suma mocy minimalnych zestawów kostek: %d\n", total_power);
    return 0;
}