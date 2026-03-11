#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) { printf("Stack Overflow\n"); return; }
    stack[++top] = x;
}

int pop() {
    if (top == -1) { printf("Stack Underflow\n"); return -1; }
    return stack[top--];
}

int peek() {
    if (top == -1) { printf("Stack is Empty\n"); return -1; }
    return stack[top];
}

int isEmpty() { return top == -1; }

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'P' && op[1] == 'U') {
            int x; scanf("%d", &x);
            push(x);
        } else if (op[0] == 'P' && op[1] == 'O') {
            printf("%d\n", pop());
        } else if (op[0] == 'P' && op[1] == 'E') {
            printf("%d\n", peek());
        } else if (op[0] == 'I') {
            printf("%s\n", isEmpty() ? "YES" : "NO");
        }
    }
    return 0;
}
