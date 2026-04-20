#include <stdio.h>
#include <stdlib.h>

int isPossible(int arr[], int n, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > curr_min) return 0;
        if (curr_sum + arr[i] > curr_min) {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m) return 0;
        } else {
            curr_sum += arr[i];
        }
    }
    return 1;
}

int findPages(int arr[], int n, int m) {
    long long sum = 0;
    if (n < m) return -1;
    for (int i = 0; i < n; i++) sum += arr[i];
    int start = 0, end = sum, res = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid)) {
            res = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return res;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", findPages(arr, n, m));
    free(arr);
    return 0;
}
