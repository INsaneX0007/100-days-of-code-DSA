#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
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

void pre(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data); pre(root->left); pre(root->right);
}

void in(struct Node* root) {
    if (!root) return;
    in(root->left); printf("%d ", root->data); in(root->right);
}

void post(struct Node* root) {
    if (!root) return;
    post(root->left); post(root->right); printf("%d ", root->data);
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n);
    
    pre(root); printf("\n");
    in(root); printf("\n");
    post(root); printf("\n");
    return 0;
}
