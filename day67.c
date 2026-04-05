#include <stdio.h>

int adj[1000][1000];
int visited[1000];
int stack[1000], top = -1;
int v;

void topologicalSortUtil(int node) {
    visited[node] = 1;
    for (int i = 0; i < v; i++) {
        if (adj[node][i] && !visited[i])
            topologicalSortUtil(i);
    }
    stack[++top] = node;
}

void topologicalSort() {
    for (int i = 0; i < v; i++) visited[i] = 0;
    
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            topologicalSortUtil(i);
    }
    
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int e;
    scanf("%d %d", &v, &e);
    
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
    }
    
    topologicalSort();
    return 0;
}
