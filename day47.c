#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int data) {
    if (data == -1) return NULL;
    struct Node* nNode = (struct Node*)malloc(sizeof(struct Node));
    nNode->data = data;
    nNode->left = nNode->right = NULL;
    return nNode;
}

struct Node* build(int arr[], int i, int n) {
    if (i < n && arr[i] != -1) {
        struct Node* root = create(arr[i]);
        root->left = build(arr, 2 * i + 1, n);
        root->right = build(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}

int maxDepth(struct Node* root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n);
    printf("%d\n", maxDepth(root));
    return 0;
}
