#include <stdio.h>
#include <stdbool.h>

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[2 * i + 1] < arr[i]) return false;
        if (2 * i + 2 < n && arr[2 * i + 2] < arr[i]) return false;
    }
    return true;
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%s\n", isMinHeap(arr, n) ? "YES" : "NO");
    return 0;
}
