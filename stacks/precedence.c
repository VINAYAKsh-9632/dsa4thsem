#include<stdio.h>
#include<math.h>
#include<stdlib.h>
    int precedence(char ch){
        switch(ch){
            case'#':return 0;
                    break;
            case'(':return 1;
            break;
            case'+':return 2;
            break;
            case'-':return 2;
            break;
            case'/':return 3;
            break;
            case '*':return 3;
            break;
            
        }

    }
int main()
{
    return 0;
}