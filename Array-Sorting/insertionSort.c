#include <stdio.h>

void insertion(int *arr, int n) {
    for(int i=1;i<n;i++){
        int current = arr[i]; 
        int j =i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main()
{
    int arr[5] = {7,3,1,4,2};
    insertion(arr,5);
    for(int i=0;i<5;i++)
        printf("%d ",arr[i]);

    return 0;
}