#include <stdio.h>
void findAvgTime(int n, int bt[], int at[], int quantum) {
    int wt[n], tat[n], rem_bt[n];
    int total_wt = 0, total_tat = 0;
    int t = 0, completed = 0;
    for (int i = 0; i < n; i++) rem_bt[i] = bt[i];
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rem_bt[i] > 0) {
                if (rem_bt[i] > quantum) {
                    rem_bt[i] -= quantum;
                    t += quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i] - at[i];
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }
        t++;
    }
    for (int i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
    printf("Processes | Turnaround Time | Waiting Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" P[%d]     | %d               | %d\n", i + 1, tat[i], wt[i]);
    }
    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], at[n];
    printf("Enter arrival and burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process[%d]:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }
    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    printf("Round Robin Scheduling\n");
    findAvgTime(n, bt, at, quantum);
    return 0;
}
