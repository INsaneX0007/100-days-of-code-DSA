#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n == 0) return 0;

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tail != NULL) tail->next = head;

    struct Node* curr = head;
    if (head != NULL) {
        do {
            printf("%d", curr->data);
            if (curr->next != head) printf(" ");
            curr = curr->next;
        } while (curr != head);
    }
    printf("\n");

    return 0;
}
