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

void printRightView(struct Node* root) {
    if (!root) return;
    struct Node* q[100];
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear) {
        int n = rear - front;
        for (int i = 1; i <= n; i++) {
            struct Node* temp = q[front++];
            if (i == n) printf("%d ", temp->data);
            if (temp->left) q[rear++] = temp->left;
            if (temp->right) q[rear++] = temp->right;
        }
    }
    printf("\n");
}

int main() {
    int n, arr[1000];
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = build(arr, 0, n);
    printRightView(root);
    return 0;
}
