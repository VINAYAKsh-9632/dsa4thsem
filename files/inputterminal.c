#include<stdio.h>
int main()
{
    FILE* fp=fopen("Mohit.txt","w");
    char a;
    for(int i=0;i<10;i++)
    {
        scanf("%c",&a);
        fprintf(fp,"%c",a);
    }
    fclose(fp);
    return 0;

}