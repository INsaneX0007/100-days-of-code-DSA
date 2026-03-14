#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() { return (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void enqueue(int x) {
    if (isFull()) { printf("Full\n"); return; }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("Enqueued %d\n", x);
}

int dequeue() {
    if (isEmpty()) { printf("Empty\n"); return -1; }
    int val = queue[front];
    if (front == rear) { front = rear = -1; }
    else front = (front + 1) % MAX;
    return val;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'E') {
            int x; scanf("%d", &x);
            enqueue(x);
        } else if (op[0] == 'D') {
            int val = dequeue();
            if (val != -1) printf("Dequeued %d\n", val);
        }
    }
    return 0;
}
