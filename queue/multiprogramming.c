#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int executionTime;
    struct node *next;
} node_type;

void insert(node_type **, node_type ** , int *n,int *timePeriod);
void delete(node_type **, node_type ** ,  int *n, int *timePeriod);
void display(node_type *, node_type *, int *timePeriod);
void execution(node_type **front , node_type **rear , int *timePeriod);

int main(){
    node_type *front ;
    node_type *rear;
    front = rear = NULL;
    int n;
    int timePeriod = 2;

    int option;

    printf("enter the number of process you want to execute\n");
    scanf("%d",&n);
    do
    {
        printf("1 to insert\n");
        printf("2 to delete\n");
        printf("3 to display\n");   
        printf("4 to exit\n");
        scanf("%d", &option);
    switch(option){
        case 1:
             insert(&front, &rear,&n,&timePeriod);
             break;
        case 2:
                delete(&front , &rear ,&n,&timePeriod);
                break; 
        case 3:
            execution(&front, &rear,&timePeriod);
                
                display(rear , front,&timePeriod);
                break;
        case 4:
                printf("exiting\n");
                break;
        default:
                printf("invalid option\n");
                break;
    }
    } while (option!=4);
    
    return 0;
}
void insert(node_type **front , node_type **rear , int *n ,int *timePeriod ){
  int i=0;
    while(i<(*n)){
    node_type * node;
    node = (node_type *)malloc(sizeof(node_type));
    node_type * last ;
        

    if(node !=NULL){
        printf("enter the execution time for process %d\n",i+1);
        scanf("%d", &node->executionTime);
        if(*front==NULL){
            *front = (*rear )= node;
            last = node;
            last->next = node;
            i++;
        }
        else{
            (*rear)->next = node;
            *rear = node;
            last = (*rear);
            last->next = (*front);
            i++;
        }
    }
    else {
        printf("memory not available\n");
      }
        }
     
}


void delete(node_type **front, node_type **rear , int *n ,int *timePeriod ){
    node_type *temp = *front;
    if((*front) == NULL){
        printf("queue is empty\n");
    }
    else if((*front) == (*rear)){
        printf("dequeued element is %d\n",temp->executionTime);
        *front = *rear = NULL;
        
        free(temp);

    }
    else {
        printf("dequeued element is %d\n",temp->executionTime);
        printf("number of process are %d",*n);
        *front = temp->next;
        (*rear)->next = *front;
        // (*n) --;
        free(temp);
    }


}
void display(node_type *rear,node_type * front ,int *timePeriod){
node_type *temp ;
temp = front;
 node_type * executor  = front;

if(temp==NULL){
    printf("Queue is empty\n");
}
    while(executor->next!=(front->next)){
    if(executor->executionTime >0){
        executor->executionTime = executor->executionTime - (*timePeriod );
        executor = executor->next;
        
    }
    }
do{
 printf(" execution time :%d ",temp->executionTime);
        temp = temp->next;
}
    while(temp!=front);
    // printf("execution time :%d ",rear->executionTime);
    printf("\n");

}

void execution(node_type **front , node_type **rear , int *timePeriod){
   
}