#include <stdio.h>
#include <stdlib.h>

int* BIT;
int bit_size;

void update(int i, int val) {
    while (i <= bit_size) {
        BIT[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

struct Node {
    int val;
    int id;
};

int compare(const void* a, const void* b) {
    return (((struct Node*)a)->val - ((struct Node*)b)->val);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node nums[1000];
    int raw_nums[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &raw_nums[i]);
        nums[i].val = raw_nums[i];
        nums[i].id = i + 1;
    }
    qsort(nums, n, sizeof(struct Node), compare);
    int ranks[1001];
    for (int i = 0; i < n; i++) {
        ranks[nums[i].id] = i + 1;
    }
    BIT = (int*)calloc(n + 1, sizeof(int));
    bit_size = n;
    int result[1000];
    for (int i = n - 1; i >= 0; i--) {
        int rank = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j].val == raw_nums[i]) {
                rank = j + 1;
                break;
            }
        }
        result[i] = query(rank - 1);
        update(rank, 1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    free(BIT);
    return 0;
}
