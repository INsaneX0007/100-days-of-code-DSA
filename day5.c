#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;
    if (scanf("%d", &p) != 1) return 1;

    int *log1 = (int *)malloc(p * sizeof(int));
    if (log1 == NULL) return 1;
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    if (scanf("%d", &q) != 1) {
        free(log1);
        return 1;
    }

    int *log2 = (int *)malloc(q * sizeof(int));
    if (log2 == NULL) {
        free(log1);
        return 1;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int *merged = (int *)malloc((p + q) * sizeof(int));
    if (merged == NULL) {
        free(log1);
        free(log2);
        return 1;
    }

    int i = 0, j = 0, k = 0;

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    while (i < p) {
        merged[k++] = log1[i++];
    }

    while (j < q) {
        merged[k++] = log2[j++];
    }

    for (int m = 0; m < p + q; m++) {
        printf("%d", merged[m]);
        if (m < p + q - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(log1);
    free(log2);
    free(merged);
    return 0;
}
