#include <stdio.h>

void selectionSort(int *arr,int n)
{
    for(int i =0;i<=n-2;i++){// for picking the element from the starting point of the array
        for(int j = i+1;j<=n-1;j++){//this loop is for comparing the picked element with the remaining elements
            if(arr[j]<arr[i]){//comparison as the smallest element will always be in the beginning
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
}

int main()
{
    int arr[5] = {2,6,7,14,1};
    selectionSort(arr,5);
    for(int i=0;i<5;i++)
        printf("%d ",arr[i]);
        return 0;
}