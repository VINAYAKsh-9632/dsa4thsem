#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
int random_pivot(int arr[], int left, int right) {
    srand(time(NULL));
    int random_index = rand() % (right - left + 1) + left;
    return random_index;
}

// // Function to partition the array using a random pivot
// int partition(int arr[], int left, int right) {
   
//     int pivot_value = arr[pivot_index];



int partition(int arr[],int si,int ei){
     int pivot_index = random_pivot(arr, si, ei);
    int pivot=arr[pivot_index];
    int i=si-1;
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            }
    }
    i++;
    int temp = arr[ei];
    arr[ei]=arr[i];
    arr[i]=temp;
    return i;



}

void quickSort(int arr[],int si,int ei){
    if(si>=ei){
        return;
        
    }
    int pidx=partition(arr,si,ei);
    quickSort(arr,si,pidx-1);
    quickSort(arr,pidx+1,ei);

}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        }
        printf("\n");
}

int main()
{
    int n;
    
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr,0,n-1);
    print(arr,n);

    return 0;
}