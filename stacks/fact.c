#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int fact(int n){
    if(n==1){
    return 1;
    }
    int fac = n*fact(n-1);
    return fac;
}
int main()
{int n=1;
    int val = fact(n);
    printf("%d\n", val);
    
    return 0;
}
