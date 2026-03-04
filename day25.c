#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

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

    int key, count = 0;
    if (scanf("%d", &key) == 1) {
        struct Node *curr = head;
        while (curr != NULL) {
            if (curr->data == key) count++;
            curr = curr->next;
        }
    }

    printf("%d\n", count);

    return 0;
}
