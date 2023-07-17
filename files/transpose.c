#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{   FILE* fp;
    fp=fopen("text3.txt","r");
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int transpose[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d", &arr[i][j]);
        }
    }
    FILE*fpr=fopen("text4.txt","w");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            transpose[j][i]=arr[i][j];
            
        }
    }
    for (int i = 0; i < n; i++)
    {
       for(int j = 0; j < n; j++){
        fprintf(fpr,"%d ",transpose[i][j]);
       }
       printf("\n");
    }
    
    return 0;
}