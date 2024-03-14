#include<stdio.h>

int reverse(int arr[] , int start , int end){
    if(start >=end){
        return 0;
    }
    else {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        return reverse( arr , ++start, --end);
    }


}
int main(){
    int arr[10] = {2,3,4,23,443,23,43,23,15,76};
     for (int i = 0; i <= 9; i++)

    {
        printf("%d ",arr[i]);
    }
    reverse(arr , 0,9);
        printf("after revrse \n");

    for (int i = 0; i <= 9; i++)

    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}