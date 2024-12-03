#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate Fibonacci numbers as strings
int main() {
    FILE *file = fopen("a.conf", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int HOW;
    fscanf(file, "%d", &HOW);
    fclose(file);

    // Allocate memory for the array of pointers to char
    char **fibArray = malloc(HOW * sizeof(char*));
    if (fibArray == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    // Load Fibonacci numbers into the array
    for (int i = 0; i < HOW; i++) {
        fibArray[i] = fibonacci(i);
    }

    // Print the Fibonacci numbers
    for (int i = 0; i < HOW; i++) {
        printf("%s\n", fibArray[i]);
        free(fibArray[i]); // Free each string after printing
    }

    free(fibArray); // Free the array of pointers

    return 0;
}

