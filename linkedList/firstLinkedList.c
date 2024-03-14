#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data ;
    struct Node * next;
};

void linkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){

    
    printf("%d  ", ptr->data);
    ptr= ptr->next;
    }
}
int main(){

struct Node * head;
struct Node * second;
struct Node * third;
// alllocate memory for nodes in the linked list
head = (struct Node * ) malloc(sizeof(struct Node));
second = (struct Node * ) malloc(sizeof(struct Node));
third = (struct Node * ) malloc(sizeof(struct Node));


// linking the nodes
head->data = 7;
head->next = second;

second->data = 23.55;
second->next = third;

third->data = 87;
third->next = NULL;

linkedListTraversal(head);

    return 0;
}