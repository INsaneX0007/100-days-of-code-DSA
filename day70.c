#include <stdio.h>
#include <limits.h>

struct Edge { int src, dest, weight; };

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    
    struct Edge edges[10000];
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    
    int src;
    scanf("%d", &src);
    
    long long dist[1000];
    for (int i = 0; i < v; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    
    for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].src;
            int w = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[w])
                dist[w] = dist[u] + weight;
        }
    }
    
    int has_neg_cycle = 0;
    for (int j = 0; j < e; j++) {
        int u = edges[j].src;
        int w = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[w]) {
            has_neg_cycle = 1;
            break;
        }
    }
    
    if (has_neg_cycle) {
        printf("Negative Cycle Detected\n");
    } else {
        for (int i = 0; i < v; i++) {
            if (dist[i] == INT_MAX) printf("-1 ");
            else printf("%lld ", dist[i]);
        }
        printf("\n");
    }
    
    return 0;
}
