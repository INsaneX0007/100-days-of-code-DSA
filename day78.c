#include <stdio.h>
#include <limits.h>

int minKey(int key[], int mstSet[], int v) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
        if (mstSet[i] == 0 && key[i] < min)
            min = key[i], min_index = i;
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

    int parent[1000], key[1000], mstSet[1000];
    for (int i = 0; i < v; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < v - 1; count++) {
        int u = minKey(key, mstSet, v);
        mstSet[u] = 1;
        for (int i = 0; i < v; i++)
            if (graph[u][i] && mstSet[i] == 0 && graph[u][i] < key[i])
                parent[i] = u, key[i] = graph[u][i];
    }

    int totalWeight = 0;
    for (int i = 1; i < v; i++) totalWeight += graph[i][parent[i]];

    printf("%d\n", totalWeight);
    return 0;
}
