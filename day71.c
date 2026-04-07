#include <stdio.h>
#include <string.h>

int main() {
    int size, n;
    scanf("%d", &size);
    scanf("%d", &n);

    int table[1000];
    for (int i = 0; i < size; i++) table[i] = -1;

    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        int j = 0;
        int index = (key % size + j * j) % size;
        while (table[index] != -1 && j < size) {
            j++;
            index = (key % size + j * j) % size;
        }
        if (table[index] == -1) {
            table[index] = key;
        }
    }

    for (int i = 0; i < size; i++) {
        if (table[i] != -1) printf("%d: %d\n", i, table[i]);
        else printf("%d: Empty\n", i);
    }
    return 0;
}
