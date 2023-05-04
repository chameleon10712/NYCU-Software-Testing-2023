#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define EQUATION_CNT 14
#define VARIABLE_CNT 15

int equations[EQUATION_CNT][VARIABLE_CNT + 1] = {
    #include "equations"
};

int main()
{
    int xs[VARIABLE_CNT];

    for (int i = 0; i < EQUATION_CNT; ++i) {
        for (int j = 0; j < VARIABLE_CNT - 1; ++j) {
            printf("%d * x%d + ", equations[i][j], j);
        }
        printf("%d * x%d = %d\n", equations[i][VARIABLE_CNT - 1], VARIABLE_CNT - 1, equations[i][VARIABLE_CNT]);
    }

    printf("Solve all x\n");

    for (int i = 0; i < VARIABLE_CNT; ++i) {
        printf("Input x%d: ", i);
        scanf("%d", &xs[i]);
    }

    for (int i = 0; i < EQUATION_CNT; ++i) {
        int sum = 0;

        for (int j = 0; j < VARIABLE_CNT; ++j) {
            sum += xs[j] * equations[i][j];
        }

        if (sum != equations[i][VARIABLE_CNT]) {
            printf("WA!\n");
            return 1;
        }
    }

    printf("AC!\n");
    return 0;
}