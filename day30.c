#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->coeff != 0) {
            if (curr != head && curr->coeff > 0) {
                printf(" + ");
            } else if (curr->coeff < 0) {
                if (curr == head) printf("-");
                else printf(" - ");
            }
            int abs_c = abs(curr->coeff);
            if (abs_c != 1 || curr->exp == 0) {
                printf("%d", abs_c);
            }
            if (curr->exp > 0) {
                printf("x");
                if (curr->exp > 1) {
                    printf("^%d", curr->exp);
                }
            }
        }
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
