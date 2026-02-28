#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int min_sum = INT_MAX;
    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}
