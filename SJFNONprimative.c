#include <stdio.h>

int main() {

    int n,i,j;
    int pid[20],at[20],bt[20],ct[20],tat[20],wt[20];
    int completed[20]={0};
    int current_time=0,done=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        pid[i]=i+1;
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    while(done<n){

        int idx=-1;
        int min=9999;

        for(i=0;i<n;i++){
            if(at[i]<=current_time && completed[i]==0){
                if(bt[i]<min){
                    min=bt[i];
                    idx=i;
                }
            }
        }

        if(idx==-1){
            current_time++;
        }
        else{
            ct[idx]=current_time+bt[idx];
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];

            current_time=ct[idx];
            completed[idx]=1;
            done++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
