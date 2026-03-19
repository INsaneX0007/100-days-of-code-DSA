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

struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n && arr[i] != -1) {
        root = createNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = insertLevelOrder(arr, 0, n);
    inorder(root);
    printf("\n");
    return 0;
}
