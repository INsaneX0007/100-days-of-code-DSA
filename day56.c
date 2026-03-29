#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMirror(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    return false;
}

bool isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n);
    printf("%s\n", isSymmetric(root) ? "YES" : "NO");
    return 0;
}
