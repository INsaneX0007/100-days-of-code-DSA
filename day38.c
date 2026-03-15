#include <stdio.h>
#define MAX 1000

int deque[MAX];
int front = MAX/2, rear = MAX/2 - 1;

void insertFront(int x) { deque[--front] = x; printf("InsertedFront %d\n", x); }
void insertRear(int x) { deque[++rear] = x; printf("InsertedRear %d\n", x); }

int deleteFront() {
    if (front > rear) { printf("Empty\n"); return -1; }
    return deque[front++];
}

int deleteRear() {
    if (front > rear) { printf("Empty\n"); return -1; }
    return deque[rear--];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char op[15];
        scanf("%s", op);
        if (op[0] == 'I' && op[6] == 'F') {
            int x; scanf("%d", &x); insertFront(x);
        } else if (op[0] == 'I' && op[6] == 'R') {
            int x; scanf("%d", &x); insertRear(x);
        } else if (op[0] == 'D' && op[6] == 'F') {
            int val = deleteFront();
            if (val != -1) printf("DeletedFront %d\n", val);
        } else if (op[0] == 'D' && op[6] == 'R') {
            int val = deleteRear();
            if (val != -1) printf("DeletedRear %d\n", val);
        }
    }
    return 0;
}
