#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[1000];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int main() {
    char infix[1000], postfix[1000];
    scanf("%s", infix);
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            if (!isEmpty()) pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (!isEmpty()) postfix[j++] = pop();
    postfix[j] = '\0';
    printf("%s\n", postfix);
    return 0;
}
