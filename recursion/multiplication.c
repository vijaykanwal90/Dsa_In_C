#include<stdio.h>

int multiplication(int n , int i){

    if(i==11){
        return 0;
    }
    else {
    printf("%d\n",n*i);

    return multiplication(n,++i);

    }
}
int main(){

    multiplication(6 , 1);


    return 0;
}