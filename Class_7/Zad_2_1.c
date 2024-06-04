#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} Dice;

int check_possibility(Dice bag, Dice *draws, int draw_count) {
    for (int i = 0; i < draw_count; i++) {
        if (draws[i].red > bag.red || draws[i].green > bag.green || draws[i].blue > bag.blue) {
            return 0;
        }
    }
    return 1;
}

int parse_draw(char *str, Dice *draw) {
    char *token;
    draw->red = draw->green = draw->blue = 0;

    token = strtok(str, ", ");
    while (token != NULL) {
        if (strstr(token, "red")) {
            draw->red = atoi(token);
        } else if (strstr(token, "green")) {
            draw->green = atoi(token);
        } else if (strstr(token, "blue")) {
            draw->blue = atoi(token);
        }
        token = strtok(NULL, ", ");
    }
    return 1;
}

int main() {
    FILE *file = fopen("dane2.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    char line[1024];
    Dice bag = {12, 13, 14};
    int possible_games_sum = 0;

    while (fgets(line, sizeof(line), file)) {
        char *game_str = strdup(line);
        char *game_id_str = strtok(game_str, ":");
        int game_id = atoi(&game_id_str[5]);

        char *draw_str = strtok(NULL, ":");
        char *draw_token;
        Dice draws[100];
        int draw_count = 0;

        draw_token = strtok(draw_str, ";");
        while (draw_token != NULL) {
            parse_draw(draw_token, &draws[draw_count++]);
            draw_token = strtok(NULL, ";");
        }

        if (check_possibility(bag, draws, draw_count)) {
            possible_games_sum += game_id;
        }

        free(game_str);
    }

    fclose(file);
    printf("Suma identyfikatorów możliwych gier: %d\n", possible_games_sum);
    return 0;
}
