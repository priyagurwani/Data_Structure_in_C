// Linear Search is used for Sorted and unsorted Array both
// Linear Search = traverse the elements one by one
// Binary Search works only for Sorted Array
// Binary Search - Breaks array by half and half
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high){
         mid=(low+high)/2;  //It will give 1,10=5 middle index of an array
         if(arr[mid]==element){
             return mid;
         }
         if(arr[mid]<element){
             low = mid +1 ; //if 1,10 now its on 5 then it will search from 6 to 10 (not from 5 to 10) so mid+1
         }
         else{
             high = mid-1;
         }
         }
         return -1;
}     
int main() {
    // Linear Search = Sorted and Unsorted
    int check[]={22,33,12,44,55,67,88,99};
    int element=12;
    int size=7;
    // If the array is of 20 30 size you can't sit and count so use bellow code
    // int size=sizeof(check)/sizeof(int);
    int index=linearSearch(check,size,element);
    printf("\nThrough Linear Search:\n");
    printf("The element %d is at index %d",element,index);
    
    
    // Binary Search = Only for Sorted
    int check1[]={2,4,6,8,10,55,88};
    int element1=10;
    int size1=sizeof(check1)/sizeof(int);  //size starts from 1 while index from 0
    int index1=binarySearch(check1,size1,element1);
    printf("\nThrough Binary Search:\n");
    printf("\nthe element %d is at index %d",element1,index1);
    return 0;
}
