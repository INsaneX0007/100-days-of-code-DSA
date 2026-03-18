#include <stdio.h>
#define MAX 1000

int queue[MAX];
int q_front = 0, q_rear = -1, q_size = 0;

void enqueue(int x) { queue[++q_rear] = x; q_size++; }
int dequeue() { q_size--; return queue[q_front++]; }
int isQueueEmpty() { return q_size == 0; }

int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }
int isStackEmpty() { return top == -1; }

void reverseQueue() {
    while (!isQueueEmpty()) {
        push(dequeue());
    }
    while (!isStackEmpty()) {
        enqueue(pop());
    }
}

int main() {
    int n, x;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    reverseQueue();
    while (!isQueueEmpty()) {
        printf("%d", dequeue());
        if (!isQueueEmpty()) printf(" ");
    }
    printf("\n");
    return 0;
}
