#include <stdio.h>

int adj[1000][1000], visited[1000], v;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < v; i++) {
        if (adj[node][i] && !visited[i]) dfs(i);
    }
}

int main() {
    int e, components = 0;
    if (scanf("%d %d", &v, &e) != 2) return 1;
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1; adj[w][u] = 1;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}
