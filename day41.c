#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL) return -1;
    struct Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'E' || op[0] == 'e') {
            scanf("%d", &val);
            enqueue(val);
        } else if (op[0] == 'D' || op[0] == 'd') {
            int res = dequeue();
            if (res != -1) printf("%d\n", res);
            else printf("Empty\n");
        }
    }
    return 0;
}
