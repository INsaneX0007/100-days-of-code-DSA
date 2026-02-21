#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int mat[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            printf("%d ", mat[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            printf("%d ", mat[i][right]);
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", mat[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", mat[i][left]);
            left++;
        }
    }
    printf("\n");

    return 0;
}
