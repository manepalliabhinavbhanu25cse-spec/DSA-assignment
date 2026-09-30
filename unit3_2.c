#include <stdio.h>
#include <stdlib.h>

struct Node {
    int passenger;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void addPassenger(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->passenger = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deletePassenger(int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->passenger != value)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
}

void forward() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->passenger);
        temp = temp->next;
    }

    printf("\n");
}

void backward() {
    struct Node *temp = tail;

    while (temp != NULL) {
        printf("%d ", temp->passenger);
        temp = temp->prev;
    }

    printf("\n");
}

int main() {
    addPassenger(101);
    addPassenger(102);
    addPassenger(103);
    addPassenger(104);

    printf("Forward: ");
    forward();

    printf("Backward: ");
    backward();

    deletePassenger(102);

    printf("After deletion: ");
    forward();

    return 0;
}
