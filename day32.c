#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) { printf("Overflow\n"); return; }
    stack[++top] = x;
    printf("Pushed %d\n", x);
}

int pop() {
    if (top == -1) { printf("Underflow\n"); return -1; }
    return stack[top--];
}

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
            int val = pop();
            if (val != -1) printf("Popped %d\n", val);
        }
    }
    return 0;
}
