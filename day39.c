#include <stdio.h>
#define MAX 1000

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapifyUp(int i) {
    while (i > 0) {
        int p = (i-1)/2;
        if (heap[p] > heap[i]) { swap(&heap[p], &heap[i]); i = p; }
        else break;
    }
}

void heapifyDown(int i) {
    while (1) {
        int l=2*i+1, r=2*i+2, smallest=i;
        if (l < heapSize && heap[l] < heap[smallest]) smallest=l;
        if (r < heapSize && heap[r] < heap[smallest]) smallest=r;
        if (smallest==i) break;
        swap(&heap[i], &heap[smallest]);
        i=smallest;
    }
}

void insert(int x) { heap[heapSize++]=x; heapifyUp(heapSize-1); }

int extractMin() {
    if (!heapSize) return -1;
    int min=heap[0];
    heap[0]=heap[--heapSize];
    heapifyDown(0);
    return min;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        if (op[0]=='I') { int x; scanf("%d",&x); insert(x); }
        else if (op[0]=='E') printf("%d\n", extractMin());
    }
    return 0;
}
