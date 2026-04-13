#include <stdio.h>
#include <limits.h>

int minDistance(int dist[], int sptSet[], int v) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
        if (sptSet[i] == 0 && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

int main() {
    int v, e;
    if (scanf("%d %d", &v, &e) != 2) return 1;

    int graph[1000][1000] = {0};
    for (int i = 0; i < e; i++) {
        int u, w, weight;
        scanf("%d %d %d", &u, &w, &weight);
        graph[u][w] = weight;
        graph[w][u] = weight;
    }

    int src;
    scanf("%d", &src);

    int dist[1000], sptSet[1000];
    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = minDistance(dist, sptSet, v);
        sptSet[u] = 1;

        for (int i = 0; i < v; i++)
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }

    for (int i = 0; i < v; i++) {
        if (dist[i] == INT_MAX) printf("-1 ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
