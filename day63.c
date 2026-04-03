#include <stdio.h>

int adj[1000][1000];
int visited[1000];
int v;

void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < v; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int e;
    scanf("%d %d", &v, &e);
    
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
        adj[w][u] = 1;
    }
    
    int start;
    scanf("%d", &start);
    
    dfs(start);
    printf("\n");
    
    return 0;
}
