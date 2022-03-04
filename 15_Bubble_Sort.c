#include <stdio.h>
#include <stdlib.h>
void display(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("ELements:%d\n",arr[i]);
    }
}
// n-1 so if length is 6 index starts froom 0 to 5 
// n-i-1 
// 1. initially i=0 so 6-0-1 = 5 so when i at 0 it will do 5 comparisons
// 2.i=1 so 6-1-1 = 4 so when i at 1 it will do 4 comparisons
// 3.i=2 so 6-2-1 = 3 so when i at 2 it will do 3 comparisons and so on 

void bubblesort(int *arr,int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main() {
    // Write C code here
    // printf("Hello world");
    int arr[]={22,12,3,44,66,5};
    int n=6;
    display(arr,n);
    printf("After sorting through bubblesort\n");
    bubblesort(arr,n);
    display(arr,n);
    return 0;
}
