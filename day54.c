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

void printZigZag(struct Node* root) {
    if (!root) return;
    struct Node* s1[100];
    struct Node* s2[100];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 != -1 || top2 != -1) {
        while (top1 != -1) {
            struct Node* temp = s1[top1--];
            printf("%d ", temp->data);
            if (temp->left) s2[++top2] = temp->left;
            if (temp->right) s2[++top2] = temp->right;
        }
        while (top2 != -1) {
            struct Node* temp = s2[top2--];
            printf("%d ", temp->data);
            if (temp->right) s1[++top1] = temp->right;
            if (temp->left) s1[++top1] = temp->left;
        }
    }
    printf("\n");
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n);
    printZigZag(root);
    return 0;
}
