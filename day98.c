#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void* a, const void* b) {
    return (((struct Interval*)a)->start - ((struct Interval*)b)->start);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Interval intervals[1000];
    for (int i = 0; i < n; i++) scanf("%d %d", &intervals[i].start, &intervals[i].end);
    qsort(intervals, n, sizeof(struct Interval), compare);
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (intervals[index].end >= intervals[i].start) {
            if (intervals[index].end < intervals[i].end)
                intervals[index].end = intervals[i].end;
        } else {
            index++;
            intervals[index] = intervals[i];
        }
    }
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", intervals[i].start, intervals[i].end);
    }
    return 0;
}
