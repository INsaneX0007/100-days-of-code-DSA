#include <stdio.h>

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    
    int adj[1000][1000] = {0};
    int visited[1000] = {0};
    
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
        adj[w][u] = 1;
    }
    
    int start;
    scanf("%d", &start);
    
    int queue[1000], front = 0, rear = 0;
    
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        
        for (int i = 0; i < v; i++) {
            if (adj[curr][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    
    return 0;
}
