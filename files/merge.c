#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void merge(int arr[],int si,int ei,int mid,int n){
    int i=si;
    int j=mid+1;
    int k=0;
    int temp[ei-si+1];
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        
        temp[k]=arr[i];
            i++;
            k++;
    }
    while(j<=ei){
         temp[k]=arr[j];
            j++;
            k++;
    }
    for(k=0,i=si;i<=ei;i++,k++){
        arr[i]=temp[k];
    }
  
}
void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        
        printf("%d ",arr[i]);
    }
    
}
void mergeSort(int arr[],int si,int ei,int n){
    if(si >= ei){
        return;
    }
    int mid = (si+ei)/2;
    mergeSort(arr,si,mid,n);
    mergeSort(arr,mid+1,ei,n);
    merge(arr,si,ei,mid,n);
}
void main()
{   int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf(" %d",&arr[i]);
    }
    
    printf("Before merge sort\n");
    print(arr,n);
    printf("\nAfter merge sort\n");
    mergeSort(arr,0,n-1,n);
    print(arr,n);
}