#include<stdio.h>
int lcm(int a , int b , int multiple){
    if(multiple%a==0 && multiple%b==0){
        multiple = b;
        return a;
    }
   
    else {
        return lcm();
    }
}
int main(){
    // lcm(5,6);
    int a = 5, b=6 ;
    int multiple = 0;
    if(a>b){
        multiple= b;
    }
    else {
        multiple= a;
    }
    printf("%d",lcm(a,b,multiple));
    return 0;
}