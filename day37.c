#include <stdio.h>
#define MAX 1000

int heap[MAX];
int heapSize = 0;

void insert(int x) {
    heap[heapSize] = x;
    int i = heapSize++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            int tmp = heap[parent]; heap[parent] = heap[i]; heap[i] = tmp;
            i = parent;
        } else break;
    }
}

int extractMax() {
    if (heapSize == 0) return -1;
    int max = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, largest = i;
        if (l < heapSize && heap[l] > heap[largest]) largest = l;
        if (r < heapSize && heap[r] > heap[largest]) largest = r;
        if (largest == i) break;
        int tmp = heap[i]; heap[i] = heap[largest]; heap[largest] = tmp;
        i = largest;
    }
    return max;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'I') {
            int x; scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'E') {
            printf("%d\n", extractMax());
        }
    }
    return 0;
}
