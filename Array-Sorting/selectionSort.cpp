#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size:";
    cin>>n;
    int arr[n];
    cout<<"Enter array";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //selectionsort
    for(int i =0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[i]){
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
    for(int i =0;i<n;i++)
        cout<<arr[i]<<" ";
        return 0;
}