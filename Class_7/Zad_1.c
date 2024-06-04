#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int word_to_digit(char *word) {
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // error case
}

int get_digit(char *line, int start, int direction) {
    char word[6];
    int len = strlen(line);
    while (start >= 0 && start < len) {
        if (isdigit(line[start])) {
            return line[start] - '0';
        }
        int i = 0;
        while (isalpha(line[start])) {
            word[i++] = line[start];
            start += direction;
            if (i == 5) break; // max length of digit word is 5
        }
        word[i] = '\0';
        int digit = word_to_digit(word);
        if (digit != -1) return digit;
    }
    return -1; // error case
}

int calculate_energy_sum(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }
    
    char line[256];
    int sum = 0;
    
    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0'; // Remove newline
        
        int first_digit = get_digit(line, 0, 1);
        int last_digit = get_digit(line, len - 1, -1);
        
        if (first_digit != -1 && last_digit != -1) {
            sum += first_digit * 10 + last_digit;
        }
    }
    
    fclose(file);
    return sum;
}

int main() {
    const char *filename = "dane.txt"; // Plik z danymi
    int energy_sum = calculate_energy_sum(filename);
    if (energy_sum != -1) {
        printf("Suma wszystkich wartości energetycznych: %d\n", energy_sum);
    }
    return 0;
}