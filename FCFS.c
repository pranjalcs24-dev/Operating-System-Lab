#include <stdio.h>

int main() {
    int n, i;
    int pid[20], at[20], bt[20];
    int ct[20], tat[20], wt[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter Arrival Time and Burst Time for P%d: ",i+1);
        pid[i]=i+1;
        scanf("%d %d",&at[i],&bt[i]);
    }

    int current_time = 0;

    for(i=0;i<n;i++){
        if(current_time < at[i])
            current_time = at[i];

        ct[i] = current_time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        current_time = ct[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
