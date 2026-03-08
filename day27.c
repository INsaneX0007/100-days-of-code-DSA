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
    if (!head) return newNode;
    struct Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    return head;
}

int main() {
    int m, n, val;
    struct Node *head1 = NULL, *head2 = NULL;

    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &val);
            head1 = insert(head1, val);
        }
    }

    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            head2 = insert(head2, val);
        }
    }

    int skipA, skipB;
    if (scanf("%d %d", &skipA, &skipB) == 2) {
        struct Node *temp1 = head1, *temp2 = head2;
        for (int i = 0; i < skipA && temp1; i++) temp1 = temp1->next;
        for (int i = 0; i < skipB && temp2; i++) temp2 = temp2->next;

        if (temp1 && temp2) {
            temp2->next = temp1;
        }
    }

    struct Node *curr1 = head1, *curr2 = head2;
    int len1 = 0, len2 = 0;

    while (curr1) { len1++; curr1 = curr1->next; }
    while (curr2) { len2++; curr2 = curr2->next; }

    curr1 = head1;
    curr2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) curr1 = curr1->next;
    } else {
        for (int i = 0; i < diff; i++) curr2 = curr2->next;
    }

    while (curr1 && curr2) {
        if (curr1 == curr2) {
            printf("%d\n", curr1->data);
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    printf("-1\n");
    return 0;
}
