#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate Fibonacci numbers as strings
char* fibonacci(int n) {
    if (n == 0) return strdup("0");
    if (n == 1) return strdup("1");

    char *a = strdup("0");
    char *b = strdup("1");
    char *temp;

    for (int i = 2; i <= n; i++) {
        temp = b;
        b = malloc(strlen(a) + strlen(b) + 1);
        sprintf(b, "%s%s", a, temp);
        free(a);
        a = temp;
    }

    free(a);
    return b;
}

