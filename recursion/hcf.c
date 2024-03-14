#include<stdio.h>

int hcf(int a,int b){
    if(a==b){
        return a;
    }
    else if(a==1 || b==1){
        return 1;
    }
    else if(a>b){
        return hcf(a-b,b);
    }
    else {
        return hcf(a, b-a);
    }
}
int main(){
    // hcf(5,7);
    printf("%d",hcf(5,25));
    return 0;
}