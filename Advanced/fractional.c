#include <stdio.h>
#include <stdlib.h>

int compare(void conts){


}

int knapsack(int val[],int wt[], int maxw,int n){
    int item[n][2];
    for(int i =0;i<n;i++){
        item[i][0] = val[i];
        item[i][1] = wt[i];
    }
    qsort(item,n,sizeof(float[2]),compare);
    int res = 0.0;
    int curcapa = maxw;
    for(int i =0;i<n;i++){
        if(item[i][1]<curcapa){
            res += item[i][0];
            curcapa -= item[i][1];
        }
        else{
            res += item[i][0]*((float)curcapa/item[i][1]);
            break;
        }
        return res;
    }
}