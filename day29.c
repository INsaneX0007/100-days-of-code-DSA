#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
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

    if (scanf("%d", &k) != 1) return 1;

    k = k % n;
    if (k > 0) {
        tail->next = head;
        struct Node* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }
        head = newTail->next;
        newTail->next = NULL;
    }

    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) printf(" ");
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
