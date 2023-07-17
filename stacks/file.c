#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    FILE* fp=NULL;
    int arr[100],a1,i,j,temp;
    fp=fopen("hi.txt","r");
    if(fp==NULL)
    {
        printf("Error in creating a file\n");
        exit(0);
    }
    
    fscanf(fp,"%d",&a1);
    arr[0]=a1;
    for(i=1;i<a1;i++)
    {
        fscanf(fp," %d",&arr[i]);
    }
    
    for(i=0;i<a1;i++)
    {
        for(j=i+1;j<a1;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    display(arr,a1);
    return 0;
}