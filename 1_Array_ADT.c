//Array as Abstract Data Type (ADT)
// ADT is a class for objects contains a set of value and a set of operations.
// It shows only what operations are performed not how they are implemented or organized in memory.

#include <stdio.h>
#include<stdlib.h>
struct myArray{
    int total_size;
    int used_size;
    int *ptr; //it will point to first element
    
};
void createArray(struct myArray *a,int Tsize, int Usize){
    // (*a).total_size=Tsize;
    // (*a).used_size=Usize;
    // (*a).ptr=(int *)malloc(Tsize*sizeof(int)); //memory allocation in heap memory
    a->total_size=Tsize;
    a->used_size=Usize;
    a->ptr=(int *)malloc(Tsize*sizeof(int));
    
}

void show(struct myArray *a){
    for(int i=0; i < a->used_size ; i++)
    {
        printf("Elements are :%d\n",(a->ptr)[i]);
        
    }
    
}
void set(struct myArray *a){
    int n;
    for(int i=0; i < a->used_size ; i++)
    {
        printf("Enter element %d index: ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
        
    }
    
    
}
int main() {

    struct myArray marks;
    createArray(&marks,10,4);
    set(&marks);
    show(&marks);
    
    return 0;
}
