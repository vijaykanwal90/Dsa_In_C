#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool checkingAp(int *arr,int size){
    int d = arr[1]-arr[0];
    printf("%d  " ,d);
     for(int i=2;i<size;i++){
        
        if(arr[i]-arr[i-1]!=d){
            return false;
        }
        
    }
        return true;

}
int main(){

    int * dynamicArray ;
    int size ;
    scanf("%d",&size);
    dynamicArray = (int *) malloc(size * sizeof(int));
    for(int i=0;i<size;i++){
        scanf("%d",&dynamicArray[i]);
    }
    
     for(int i=0;i<size;i++){
        printf("%d ",dynamicArray[i]);
    }
  if(checkingAp(dynamicArray, size)){
    printf("array is in AP");
  }
  else {
    printf("array is not in  AP");


  }
    return 0;
}
