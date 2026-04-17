#include <stdio.h>

long long floorSqrt(long long x) {
    if (x == 0 || x == 1) return x;
    long long start = 1, end = x, ans;
    while (start <= end) {
        long long mid = (start + end) / 2;
        if (mid * mid == x) return mid;
        if (mid * mid < x) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long x;
    if (scanf("%lld", &x) != 1) return 0;
    printf("%lld\n", floorSqrt(x));
    return 0;
}
