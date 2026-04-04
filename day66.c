#include <stdio.h>

int adj[1000][1000];
int visited[1000];
int recStack[1000];
int v;

int isCyclicUtil(int node) {
    if (!visited[node]) {
        visited[node] = 1;
        recStack[node] = 1;
        
        for (int i = 0; i < v; i++) {
            if (adj[node][i]) {
                if (!visited[i] && isCyclicUtil(i)) return 1;
                else if (recStack[i]) return 1;
            }
        }
    }
    recStack[node] = 0;
    return 0;
}

int isCyclic() {
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }
    
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i)) return 1;
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
    }
    
    printf("%s\n", isCyclic() ? "YES" : "NO");
    return 0;
}
