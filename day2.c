#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int pos;
    if (scanf("%d", &pos) != 1) {
        free(arr);
        return 1;
    }
    int index = pos - 1;
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) {
            printf(" ");
        }
    }
    printf("\n");

    free(arr);
    return 0;
}
