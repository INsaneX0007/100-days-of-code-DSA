#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int mat[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int identity = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && mat[i][j] != 1) {
                identity = 0;
                break;
            }
            if (i != j && mat[i][j] != 0) {
                identity = 0;
                break;
            }
        }
        if (!identity) break;
    }

    if (identity)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
