#include <stdio.h>
#include <stdlib.h>

int calculate_hash(char **input_str, int N_lines) {
    int total_hash = 0;
    int i, j;
    for (i = 0; i < N_lines; i++) {
        for (j = 0; input_str[i][j] != '\0'; j++) {
            int alphabet_position = input_str[i][j] - 'A';
            int character_value = alphabet_position + i + j;
            total_hash += character_value;
        }
    }
    return total_hash;
}

int main() {

    int N;
    scanf("%d", &N);

    int t;
    for (t = 0; t < N; t++) {
        int N_lines;
        scanf("%d", &N_lines);

        // Allocate memory for input lines
        char **input_str = (char **)malloc(N_lines * sizeof(char *));
        int i;
        for (i = 0; i < N_lines; i++) {
            input_str[i] = (char *)malloc(51 * sizeof(char)); // Assuming maximum length of input is 50
            scanf("%s", input_str[i]);
        }

        // Calculate and print the hash
        printf("%d\n", calculate_hash(input_str, N_lines));

        // Free memory for input lines
        for (i = 0; i < N_lines; i++) {
            free(input_str[i]);
        }
        free(input_str);
    }

    return 0;
}
