#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node_type;

void insert(node_type **head,node_type **tail){
node_type *node ;
    node = (node_type *) malloc(sizeof(node_type));
    if(node==NULL){
        printf("memory not available\n");
    }
    else {
        printf("enter the data for node\n");
        scanf("%d",&node->data);
        node->next= NULL;
        
        if((*head)==NULL){
            
            (*head) = node;
            (*tail)= node;
            (*tail)->next = (*head);
            


        }
        else {
           node->next = (*tail);
           (*tail)->next = node;
           (*tail) = node;

        }
    }

}
void display(node_type *h, node_type *t){
    node_type *temp = h;
   if(temp->next==NULL){
printf("%d ",temp->data);

   }
    while(temp!=t ){
printf("%d ",temp->data);

        temp = temp->next;
    }
        printf("%d",temp->data);
    
}
int main(){
    node_type* h = NULL;
    node_type *t = NULL;

   int num ;
    printf("enter how many numbers you want to insert in linkedlist\n");
    scanf("%d",&num);

    for(int i=0;i<num;i++){
      insert(&h  , &t);

    }
    display(h,t);

    return 0;
}