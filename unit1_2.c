#include <stdio.h>

#define SIZE 10

void openHashing(int keys[], int n) {
    int table[SIZE][SIZE] = {0};
    int count[SIZE] = {0};

    for (int i = 0; i < n; i++) {
        int index = keys[i] % SIZE;
        table[index][count[index]++] = keys[i];
    }

    printf("Open Hashing:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        for (int j = 0; j < count[i]; j++)
            printf("%d -> ", table[i][j]);
        printf("NULL\n");
    }
}

void closedHashing(int keys[], int n) {
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    for (int i = 0; i < n; i++) {
        int index = keys[i] % SIZE;

        while (table[index] != -1)
            index = (index + 1) % SIZE;

        table[index] = keys[i];
    }

    printf("\nClosed Hashing:\n");

    for (int i = 0; i < SIZE; i++)
        printf("%d: %d\n", i, table[i]);
}

int main() {
    int keys[] = {23, 43, 13, 27, 37, 53};
    int n = 6;

    openHashing(keys, n);
    closedHashing(keys, n);

    return 0;
}
