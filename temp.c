#include <stdio.h>
#include <stdlib.h>
int main(){
    int *arr = malloc(5*sizeof(int));
    arr[0] =5;
    arr[1] = 6;
    printf("%d",*(arr+1));
    return 0;
}