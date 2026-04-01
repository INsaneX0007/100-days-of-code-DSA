#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* nNode = (struct Node*)malloc(sizeof(struct Node));
    nNode->data = data;
    nNode->left = nNode->right = NULL;
    return nNode;
}

int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int postIndex;
struct Node* buildTree(int in[], int post[], int inStrt, int inEnd) {
    if (inStrt > inEnd) return NULL;
    struct Node* tNode = createNode(post[postIndex--]);
    if (inStrt == inEnd) return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->right = buildTree(in, post, inIndex + 1, inEnd);
    tNode->left = buildTree(in, post, inStrt, inIndex - 1);
    return tNode;
}

void preorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

int main() {
    int n, in[100], post[100];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    postIndex = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1);
    preorder(root);
    printf("\n");
    return 0;
}
