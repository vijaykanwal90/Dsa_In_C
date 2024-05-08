#define MAX 10
#include<stdio.h>
#include<stdlib.h>
typedef struct graphImplementation{
    int data;
    struct graphImplementation *next;

} graph;

void insert(graph *adjList [],int s , int d){
    graph * node;
    node = (graph *)malloc(sizeof(graph));
    if(node==NULL){
        printf("memory not available\n");
    }
    else {
        node->data = d;
        node->next = NULL;
        if(adjList[s]==NULL){

            adjList[s]=node;
        }
        else {
            node->next = adjList[s];
            adjList[s]->next = node;

        }
    }
}
void display(graph * adjList[],int nodes){
    for(int  i=0;i<nodes;i++){
        
    }
}
int main(){
graph * adjList[MAX];

int nodes;
    printf("Enter the number of nodes you want to insert\n ");
scanf("%d", &nodes);
    for(int i=0;i<nodes;i++){
        adjList[i]=NULL;
    }
    int s,d;
    printf("enter the number where you want to insert the data\n");
    scanf("%d", &s);
    printf("enter the number which you want to insert the data\n");
    scanf("%d", &d);

    insert(adjList, s,d);

    return 0;
}