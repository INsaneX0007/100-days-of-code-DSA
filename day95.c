#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

void bucketSort(float arr[], int n) {
    struct Node* buckets[n];
    for (int i = 0; i < n; i++) buckets[i] = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        int bucketIndex = n * arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }
    for (int i = 0; i < n; i++) {
        if (buckets[i] == NULL) continue;
        struct Node* sorted = NULL;
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            struct Node* next = curr->next;
            if (sorted == NULL || sorted->data >= curr->data) {
                curr->next = sorted;
                sorted = curr;
            } else {
                struct Node* temp = sorted;
                while (temp->next != NULL && temp->next->data < curr->data) temp = temp->next;
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }
        buckets[i] = sorted;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    float arr[1000];
    for (int i = 0; i < n; i++) scanf("%f", &arr[i]);
    bucketSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%.2f", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
