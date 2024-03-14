#include<stdio.h>
#define size 5

void insert(int arr[] , int *front , int *rear, int value ){

if(((*rear) + 1)%size ==(*front)){
    printf("queue is full \n");
}
else {
    if((*front )== -1){
    (*front) = 0;
    (*rear) = 0;
   arr[(*rear)] = value;
}
   else {
    (*rear) = (*rear + 1)%size;
    arr[(*rear)] = value;
    
   }
   
}
}

void delete(int arr[], int *front , int *rear){

    if((*front)==-1){
        printf("Queue is empty\n");

    }
    else {
        printf("poped element is %d\n", arr[*(front)]);

        (*front)  = (*front + 1)%size;
    }
}

void display(int arr[], int *front , int *rear){
    int temp = (*front);
   
    while(temp!=(*rear)){
      printf("%d  ", arr[temp]);
      temp = (temp+1)%size;

    }
    printf("%d",arr[(*rear)]);
    printf("\n");

}
int main(){

    int arr[size];
    int front =-1;
    int rear = -1;
    int option;
    do
    {
        printf("1 to enter the value\n");
        printf("2 to delete the value\n");
        printf("3 to display the queue\n");

        printf("4 to exit\n");
        scanf("%d",&option);
switch (option)
{
case 1:
        int value;
        printf("enter a number\n");
        scanf("%d",&value);
        insert(arr,&front , &rear, value);
    
    break;
case 2:
        // insert(arr,&front , &rear);
        delete(arr, &front , &rear);
    
    break;
case 3:
            display(arr, &front , &rear);
     
    
    break;
case 4:
        printf("exit succesfully\n");
    
    break;
default:
    printf("Invalid statement\n");
    break;
}

    } while (option!=4);
    


    
    return 0;
}