#include <stdio.h>
#define INF 99999

int main() {
    int v;
    if (scanf("%d", &v) != 1) return 1;

    int dist[1000][1000];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF) printf("-1 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
