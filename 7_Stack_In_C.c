// Online C compiler to run C program online
// Stack is a collection of elements that follows LIFO manner i.e.Last In First Out.It means Items can be inserted or removed from one end
// push = to put , pop = to remove
// Implementing Stack using an Array
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;   //as array has fix size
    int top;    //as top returns an index number
    int *arr;   //*arr is made so we can request heap memory
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1; //if top==-1 it means array is an empty array
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    //Pushing an element in the array and it will show your stack is not empty
    // s->arr[0]=9;
    // s->top++;

    if (isEmpty(s))
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Stack is not Empty");
    }

    return 0;
}
