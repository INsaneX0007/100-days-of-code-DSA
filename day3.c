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

    int k;
    if (scanf("%d", &k) != 1) {
        free(arr);
        return 1;
    }

    int comps = 0;
    int found_index = -1;

    for (int i = 0; i < n; i++) {
        comps++;
        if (arr[i] == k) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comps);

    free(arr);
    return 0;
}
