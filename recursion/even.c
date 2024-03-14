#include<stdio.h>

int even(int n){
// tail recursion call  then statement 
    if(n<0){
        return 0;
    }
    else if(n%2!=0){
        return even(n-1);
    }
    printf("%d\n",n);
    return even(n-2);
}
int main(){
    int a ;
    printf("Enter the number\n");
    scanf("%d",&a);
    even(a);
    return 0;
}