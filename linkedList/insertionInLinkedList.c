#include<stdio.h>
#include<stdlib.h>

struct Node {

    int data;
    struct Node * next;
};

int main(){

    struct node * head;
    struct node * second;
    struct node * third;

head  = (struct Node*) malloc(sizeof(struct Node *));
second  = (struct Node*) malloc(sizeof(struct Node *));
third  = (struct Node*) malloc(sizeof(struct Node *));

head->data = 45;
head->next = second;

head->data = 45;
head->next = second;

head->data = 45;
head->next = second;


    
    return 0;
}