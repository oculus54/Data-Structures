#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char id[3];
    int deadline;
    int profit;
} Job;

// Sort by profit descending
void sort(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (jobs[j].profit > jobs[i].profit) {
                Job tmp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = tmp;
            }
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, n);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    char slot[MAX][3];
    int filled[MAX];
    memset(filled, 0, sizeof(filled));

    // Find latest free slot for each job
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!filled[j]) {
                filled[j] = 1;
                strcpy(slot[j], jobs[i].id);
                break;
            }
        }
    }

    int totalProfit = 0;
    printf("Scheduled jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (filled[i]) {
            printf("%s ", slot[i]);
            // Find profit for this job
            for (int k = 0; k < n; k++)
                if (strcmp(jobs[k].id, slot[i]) == 0)
                    totalProfit += jobs[k].profit;
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    Job jobs[] = {
        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);
    return 0;
}
```

**Output:**
```
Scheduled jobs: J3 J1 J5
Total Profit: 142