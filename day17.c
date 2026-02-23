#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
