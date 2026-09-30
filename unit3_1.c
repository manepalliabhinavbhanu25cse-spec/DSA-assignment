#include <stdio.h>
#include <stdlib.h>

struct Node {
    int song;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int song) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->song = song;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int song) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteSong(int song) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->song != song) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->song);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    insertEnd(101);
    insertEnd(102);
    insertEnd(103);
    insertBeginning(100);

    printf("Playlist: ");
    display();

    deleteSong(102);

    printf("After deletion: ");
    display();

    return 0;
}
