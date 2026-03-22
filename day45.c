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

struct Node* insertLevel(int arr[], int i, int n) {
    if (i < n && arr[i] != -1) {
        struct Node* root = createNode(arr[i]);
        root->left = insertLevel(arr, 2 * i + 1, n);
        root->right = insertLevel(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = insertLevel(arr, 0, n);
    printf("%d\n", height(root));
    return 0;
}
