#include <iostream>
using namespace std;

void bubbleSort(int arr[],int a){
    for(int i=0;i<a-1;i++){
        for(int j=0;j<a-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int a;
    cout<<"Enter The array size:";
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++)
        cin>>arr[i];
    bubbleSort(arr,a);
    cout<<"Sorted array is";
    for(int i=0;i<a;i++)
        cout<< arr[i]<<" ";
        return 0;
} 