#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int arr[], int n);
void merge(int*,int,int*,int, int*, int);
void selection(int *arr, int n);

int main()
{

}

void mergeSort(int arr[],int n){
    if(n<2)
        return;
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for(int i =0;i<mid;i++)
        left[i] = arr[i];
    for(int i = mid; i<n;i++)
        right[mid-i] = arr[i];
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    merge(left,mid,right,n-mid,arr,n);
}

void merge(int left[],int nL,int right, int nR, int arr[], int n){
    int i =0,j=0,k=0;
    while(i<nL && j<nR){
        if(left[i]>right[j])
            arr[k++] = right[j++];
        else 
            arr[k++] = left[j++];
    }
    while(i<nL)
        arr[k++] = left[i++];
    while(j<nR)
        arr[k++] = right[j++];
}

void selection(int arr[], int n){
    for(int i =0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[i])
            //swap arr[i] and arr[j]
        }
    }
}
void insertion(int arr[],int n){
    for(int i =1;i<n;i++);
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
}

void bubble(int arr[],int n){
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j+1]>arr[j])
                swap(arr[j+1],arr[j]);
        }
    }
}