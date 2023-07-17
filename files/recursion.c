#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//o(n*2)

void recursion(int n){
    if(n>0){
        
        printf("%d",n);
        recursion(n-1);
        recursion(n-1);
        printf("\n");
    }
}
int main()
{
    int n=5;
    recursion(n);
    return 0;
}