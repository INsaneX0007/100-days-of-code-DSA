#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
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

void printLevelOrder(struct Node* root) {
    if (!root) return;
    struct Node* queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        struct Node* current = queue[head++];
        printf("%d ", current->data);
        if (current->left) queue[tail++] = current->left;
        if (current->right) queue[tail++] = current->right;
    }
    printf("\n");
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n);
    printLevelOrder(root);
    return 0;
}
