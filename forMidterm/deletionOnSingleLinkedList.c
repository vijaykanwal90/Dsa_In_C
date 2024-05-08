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


        }
        else {
             (*tail)->next = node;
             (*tail) = node;

        }
    }

}
void deletionAtHead(node_type**head){
    node_type *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
}
void deletionBeforeTail(node_type **head,node_type**tail){
    node_type *temp = (*head);
    node_type *prev = NULL;

    while(temp->next !=(*tail)){
        prev=temp;
        temp = temp->next;
    }
    prev->next = (*tail);
    free(temp);
        

}
void display(node_type *p){
    node_type *temp = p;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
    int main(){
        node_type * head = NULL;
        node_type * tail = NULL;

   int num ;
    printf("enter how many numbers you want to insert in linkedlist\n");
    scanf("%d",&num);

    for(int i=0;i<num;i++){
      insert(&head  , &tail);

    }
    // deletionAtHead(&head);
    deletionBeforeTail(&head,&tail);
    display(head);

    return 0;
}