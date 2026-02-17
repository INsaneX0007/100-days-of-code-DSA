#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    if (n == 0) {
        printf("\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int unique_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[unique_count - 1]) {
            arr[unique_count] = arr[i];
            unique_count++;
        }
    }

    for (int i = 0; i < unique_count; i++) {
        printf("%d", arr[i]);
        if (i < unique_count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(arr);
    return 0;
}
