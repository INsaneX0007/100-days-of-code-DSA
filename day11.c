#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[100][100], b[100][100], sum[100][100];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d", sum[i][j]);
            if (j < c - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
