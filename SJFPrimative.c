#include <stdio.h>

int main(){

    int n,i;
    int pid[20],at[20],bt[20],rt[20];
    int ct[20],tat[20],wt[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        pid[i]=i+1;
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    int completed=0,current_time=0;

    while(completed<n){

        int idx=-1;
        int min=9999;

        for(i=0;i<n;i++){
            if(at[i]<=current_time && rt[i]>0){
                if(rt[i]<min){
                    min=rt[i];
                    idx=i;
                }
            }
        }

        if(idx==-1){
            current_time++;
        }
        else{
            rt[idx]--;
            current_time++;

            if(rt[idx]==0){
                ct[idx]=current_time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
