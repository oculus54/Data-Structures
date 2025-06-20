#include <stdio.h>

void merge(int *left, int nL, int *right, int nR, int *arr, int n){
    int i = 0, j = 0, k = 0;
    while(i < nL && j < nR){
        if(left[i] >= right[j])
            arr[k++] = right[j++];
        else
            arr[k++] = left[i++];
    }
    while(i < nL)
        arr[k++] = left[i++];
    while(j < nR)
        arr[k++] = right[j++];
}


void mergeSort(int *arr, int n){
    if(n<2)
        return;

    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for(int i = 0; i < mid; i++)
        left[i] = arr[i];
    for(int j = mid; j < n; j++)
        right[j - mid] = arr[j];
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, mid, right, n - mid, arr, n);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
