#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* nNode = (struct Node*)malloc(sizeof(struct Node));
    nNode->data = data;
    nNode->left = nNode->right = NULL;
    return nNode;
}

struct Node* build(int arr[], int i, int n) {
    if (i < n && arr[i] != -1) {
        struct Node* root = createNode(arr[i]);
        root->left = build(arr, 2 * i + 1, n);
        root->right = build(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}

void printVertical(struct Node* root) {
    if (!root) return;
    int min = 0, max = 0;
    struct QueueNode q[1000];
    int front = 0, rear = 0;
    q[rear].node = root;
    q[rear++].hd = 0;

    int vals[200][100] = {0};
    int counts[200] = {0};

    while (front < rear) {
        struct Node* curr = q[front].node;
        int hd = q[front++].hd;

        vals[hd + 100][counts[hd + 100]++] = curr->data;
        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (curr->left) {
            q[rear].node = curr->left;
            q[rear++].hd = hd - 1;
        }
        if (curr->right) {
            q[rear].node = curr->right;
            q[rear++].hd = hd + 1;
        }
    }

    for (int i = min + 100; i <= max + 100; i++) {
        for (int j = 0; j < counts[i]; j++) {
            printf("%d ", vals[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n);
    printVertical(root);
    return 0;
}
