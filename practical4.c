#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;

    // Create first node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = 10;
    newNode->next = newNode;   // points to itself
    head = newNode;

    // Create second node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = 20;
    newNode->next = head;

    head->next = newNode;

    // Create third node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = 30;
    newNode->next = head;

    head->next->next = newNode;

    // Display
    temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD\n");

    return 0;
}