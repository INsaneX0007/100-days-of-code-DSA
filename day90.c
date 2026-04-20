#include <stdio.h>
#include <stdlib.h>

int isPossible(int arr[], int n, int k, long long mid) {
    int painters = 1;
    long long currentBoard = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return 0;
        if (currentBoard + arr[i] > mid) {
            painters++;
            currentBoard = arr[i];
            if (painters > k) return 0;
        } else {
            currentBoard += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        high += arr[i];
        if (arr[i] > low) low = arr[i];
    }
    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("%lld\n", ans);
    free(arr);
    return 0;
}
