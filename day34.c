#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

long long stack[1000];
int top = -1;

void push(long long x) { stack[++top] = x; }
long long pop() { return stack[top--]; }

int main() {
    char expr[1000];
    scanf("%s", expr);
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(c - '0');
        } else {
            long long b = pop();
            long long a = pop();
            if (c == '+') push(a + b);
            else if (c == '-') push(a - b);
            else if (c == '*') push(a * b);
            else if (c == '/') push(a / b);
            else if (c == '^') push((long long)pow(a, b));
        }
    }
    printf("%lld\n", pop());
    return 0;
}
