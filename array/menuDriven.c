#include<stdio.h>

void inputArray(int arr[] , int size){
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}



void printArray(int arr[], int *size){
    for(int i=0;i<(*size);i++){
        printf("%d ",arr[i]);
    }
}

int insert(int arr [], int * size, int index, int element){
    int i= (*size);
    if(index >= *size){
        return -1;
    }
    else {
        (*size )++;
         while(i>index){
            arr[i] = arr[i-1];
            i--;
         }
    arr[index] = element;
    return *size;
    }
}

int delete(int arr[] , int * size, int index){
    int i = index;
    if(index>(*size)){
        printf("Elment cannot be accessed");
    }
    else {

        while(i<(*size-1)){

            arr[i] = arr[i+1];
            i++;
        }


    }
    return (*size)--;

}
int main(){

    int arr[15] = {};
    int length ;
  

    printf("enter the size of array\n");
    scanf("%d",&length);
    printf("\n");
    // printf("%d\n",length);
    inputArray(arr, length);
printArray(arr,&length);

// printf("before insertion \n");
// insert(arr, &length,1,1);
// printf("after insertion \n");
// printArray(arr,&length);
printf("after deletion \n");
delete(arr,&length, 3);
printArray(arr,&length);

//    implementing menu driven logic here
    // printf("Press 1 for insertion , 2 for deletion ");
    //  while(inp>1){
    //     switch (inp)
    //     {
    //     case 1:
    //         insert(arr, *length , index, element);
    //         break;
    //     case 2:
    //         delete(arr, *length, index);
    //         break;
    //     default:
    //         printf("Input valid input\n");
    //         break;
    //     }
    //  }

    return 0;
}