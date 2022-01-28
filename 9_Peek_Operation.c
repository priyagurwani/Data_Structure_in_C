// Online C compiler to run C program online

// Operations Performed on Stack:
// Peek operation in stack Using Array = to get a value of a specific position
// i.e i = position starts from 1 and Array index starts from 0
// position of i = top-i+1   // Here,top=index at the top
// index starts from bottom and position starts from top
#include <stdio.h>
#include <stdlib.h>
struct stack{
    int *arr;
    int top;
    int size;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("\nStack Overflow cannot push %d to stack\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Under Overflow cannot pop from stack\n");
        return -1;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int peek(struct stack *s,int i){ //i=position (not index)
 if(s->top-i+1<0){
     printf("Not a valid position");
     return -1;
 }
 else{
     return s->arr[s->top-i+1];
 }
}
int main() {

// allocation of stack in dynamic memory
struct stack *s=(struct stack*)malloc(sizeof(struct stack));
s->size=10;
s->top=-1;  //array is empty so top = -1
s->arr=(int*)malloc(s->size*sizeof(int));
printf("Stack has been created Successfully");

// 0=not , 1 = yes 
printf("\nBefore Pushing is full or not :%d\n",isFull(s));
printf("Before Pushing is empty or not:%d\n",isEmpty(s));
push(s,11);
push(s,12);
push(s,13);
push(s,14);
push(s,15);
push(s,16);
push(s,17);
push(s,18);
push(s,19);
push(s,20); //Pushed 10 values
push(s,21); //Stack Overflow as size is 10
printf("After Pushing is full or not :%d\n",isFull(s));
printf("After Pushing is empty or not:%d\n",isEmpty(s));

printf("\nPopped %d from stack\n",pop(s)); //LIFO
printf("Popped %d from stack\n",pop(s));  //LIFO i.e.Last in First Out

printf("\nAfter Popping is full or not :%d\n",isFull(s));
printf("After Popping is empty or not:%d\n",isEmpty(s));
  
for (int j=0; j < s->top+1;j++){
        printf("\nThe value at index %d is %d\n",j,peek(s,j));
    }
    

}
