#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);
    k = k % n;
    if (k < 0) k += n;

    int temp[1000];
    for (int i = 0; i < n; i++)
        temp[(i + k) % n] = arr[i];

    for (int i = 0; i < n; i++) {
        printf("%d", temp[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
