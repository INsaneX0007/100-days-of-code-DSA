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

    int key;
    if (scanf("%d", &key) == 1) {
        struct Node *temp = head, *prev = NULL;

        if (temp != NULL && temp->data == key) {
            head = temp->next;
            free(temp);
        } else {
            while (temp != NULL && temp->data != key) {
                prev = temp;
                temp = temp->next;
            }
            if (temp != NULL) {
                prev->next = temp->next;
                free(temp);
            }
        }
    }

    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) printf(" ");
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
