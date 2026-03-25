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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

struct Node* lcaBST(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2)
        return lcaBST(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lcaBST(root->right, n1, n2);
    return root;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 1;
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        root = insert(root, val);
    }
    if (scanf("%d %d", &n1, &n2) != 2) return 1;
    struct Node* lca = lcaBST(root, n1, n2);
    if (lca) printf("%d\n", lca->data);
    return 0;
}
