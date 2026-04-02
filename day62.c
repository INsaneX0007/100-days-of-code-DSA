#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    
    struct Node* adj[1000] = {NULL};
    
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        
        struct Node* newNode = createNode(w);
        newNode->next = adj[u];
        adj[u] = newNode;
        
        newNode = createNode(u);
        newNode->next = adj[w];
        adj[w] = newNode;
    }
    
    for (int i = 0; i < v; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
    
    return 0;
}
