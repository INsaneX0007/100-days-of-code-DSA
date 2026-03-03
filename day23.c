#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;
    struct Node* curr = head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = newNode;
    return head;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *head2 = NULL;

    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            head1 = insert(head1, val);
        }
    }

    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &val);
            head2 = insert(head2, val);
        }
    }

    struct Node dummy;
    dummy.data = 0;
    dummy.next = NULL;
    struct Node* curr = &dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if (head1 != NULL) curr->next = head1;
    if (head2 != NULL) curr->next = head2;

    struct Node* printNode = dummy.next;
    while (printNode != NULL) {
        printf("%d", printNode->data);
        if (printNode->next != NULL) printf(" ");
        printNode = printNode->next;
    }
    printf("\n");

    return 0;
}
