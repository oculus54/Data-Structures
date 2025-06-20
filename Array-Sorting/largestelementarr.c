#include <stdio.h>
int main(){
    int n,b;
    printf("Enter the range of the array");scanf("%d",&n);
    int arr[n];
    printf("Enter the values:\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int a = arr[0] ;//initiallising a variable with any postion of the array
    for(int i = 0;i<n;i++){
        if(arr[i]>arr[0])
            a = arr[i];//loop continues untill all i values or the positions are checked and it will store the highest value among the array
        
    }
    printf("max value is %d",a);
    return 0;
}
