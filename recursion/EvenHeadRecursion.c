#include<stdio.h>
// head recusrion some statement remain unexecuted
int even(int n){

  if(n<0){
return 0;
  }
    else if(n%2!=0){
        return even(n-1);
    }
    else {
         even(n-2);
    }
    printf("%d\n",n);

}
int main(){
    int a ;
    printf("Enter the number\n");
    scanf("%d",&a);
    even(a);
    return 0;
}