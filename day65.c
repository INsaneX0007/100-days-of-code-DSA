#include <stdio.h>

int adj[1000][1000];
int visited[1000];
int v;

int isCyclicUtil(int node, int parent) {
    visited[node] = 1;
    for (int i = 0; i < v; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(i, node)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int isCyclic() {
    for (int i = 0; i < v; i++)
        visited[i] = 0;
    
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, -1)) return 1;
        }
    }
    return 0;
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
    
    printf("%s\n", isCyclic() ? "YES" : "NO");
    return 0;
}
