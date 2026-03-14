#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int x) {
    if (size == MAX) { printf("Queue Full\n"); return; }
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    size++;
}

int dequeue() {
    if (size == 0) { printf("Queue Empty\n"); return -1; }
    int val = queue[front];
    front = (front + 1) % MAX;
    size--;
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
            if (val != -1) printf("%d\n", val);
        }
    }
    return 0;
}
