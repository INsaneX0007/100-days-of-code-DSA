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

struct Node* lcaBT(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    struct Node* l = lcaBT(root->left, n1, n2);
    struct Node* r = lcaBT(root->right, n1, n2);
    if (l && r) return root;
    return (l != NULL) ? l : r;
}

int main() {
    int n, n1, n2, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    if (scanf("%d %d", &n1, &n2) != 2) return 1;
    struct Node* root = build(arr, 0, n);
    struct Node* lca = lcaBT(root, n1, n2);
    if (lca) printf("%d\n", lca->data);
    return 0;
}
