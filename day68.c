#include <stdio.h>

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    
    int adj[1000][1000] = {0};
    int in_degree[1000] = {0};
    
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
        in_degree[w]++;
    }
    
    int queue[1000], front = 0, rear = 0;
    for (int i = 0; i < v; i++) {
        if (in_degree[i] == 0) queue[rear++] = i;
    }
    
    int count = 0;
    int top_order[1000];
    
    while (front < rear) {
        int u = queue[front++];
        top_order[count++] = u;
        
        for (int i = 0; i < v; i++) {
            if (adj[u][i]) {
                if (--in_degree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }
    
    if (count != v) {
        printf("Graph has a cycle\n");
    } else {
        for (int i = 0; i < count; i++) printf("%d ", top_order[i]);
        printf("\n");
    }
    
    return 0;
}
