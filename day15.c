#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int mat[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mat[i][i];
        if (i != n - 1 - i)
            sum += mat[i][n - 1 - i];
    }

    printf("%d\n", sum);
    return 0;
}
