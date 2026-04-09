#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    scanf("%s", str);

    int count[256] = {0};
    for (int i = 0; i < strlen(str); i++) {
        count[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < strlen(str); i++) {
        if (count[(unsigned char)str[i]] == 1) {
            printf("%c\n", str[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
