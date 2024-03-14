#include<stdio.h>
#include<stdlib.h>
void sum(int , int b);
int main(){
    int a = 10;
    int *p = &a;
    int **q = &p;
    printf("value of a is %d\n", a);
    printf("value of a is %d\n", *p);
    printf("value of a is %d\n", **q);
    printf("the address of a is %u\n", &a);
    printf("the address of a is %u\n", p);
    printf("the address of a is %u\n", *q);
    printf("the address of a is %p\n", *q);


    sum(1,3);
    return 0;
}
void sum(int a , int b){
    printf("the sum is %d\n", a+b);
}