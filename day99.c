#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    float time;
};

int compare(const void* a, const void* b) {
    return (((struct Car*)b)->pos - ((struct Car*)a)->pos);
}

int main() {
    int target, n;
    if (scanf("%d %d", &target, &n) != 2) return 0;
    struct Car cars[1000];
    for (int i = 0; i < n; i++) {
        int speed;
        scanf("%d %d", &cars[i].pos, &speed);
        cars[i].time = (float)(target - cars[i].pos) / speed;
    }
    qsort(cars, n, sizeof(struct Car), compare);
    int fleets = 0;
    float curr_time = 0;
    for (int i = 0; i < n; i++) {
        if (cars[i].time > curr_time) {
            fleets++;
            curr_time = cars[i].time;
        }
    }
    printf("%d\n", fleets);
    return 0;
}
