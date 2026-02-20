#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    if (scanf("%s", str) != 1) return 1;

    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    int is_palindrome = 1;

    while (left < right) {
        if (str[left] != str[right]) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (is_palindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
