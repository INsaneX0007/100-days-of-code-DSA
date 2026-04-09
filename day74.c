#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Vote {
    char name[100];
    int count;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    struct Vote votes[1000];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[j].name, temp) == 0) {
                votes[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(votes[uniqueCount].name, temp);
            votes[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    char winner[100];
    int maxVotes = 0;

    for (int i = 0; i < uniqueCount; i++) {
        if (votes[i].count > maxVotes) {
            maxVotes = votes[i].count;
            strcpy(winner, votes[i].name);
        } else if (votes[i].count == maxVotes) {
            if (strcmp(votes[i].name, winner) < 0) {
                strcpy(winner, votes[i].name);
            }
        }
    }

    printf("%s\n", winner);
    return 0;
}
