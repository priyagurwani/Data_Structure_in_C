#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *next;
    int data;
};

// Traversing in a Linked List
void Traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Elements in Linked List are:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
// if malloc= Null it means there is no memory allocation
int isFull(struct Node *top){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node *top,int data){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node *n=(struct Node*)malloc(sizeof(struct Node));
        n->data=data;
        n->next=top;  //as we will push an element so node inserted next will be top so they would link
        top=n;  // again our top will be element that is inserted Node and after insertion our top will be pushed Node
        return top;
    }
}
// we are calling top through reference (pointer) so ** is used 
int pop(struct Node **top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node *n=*top;  //pointer is assigned to top
        (*top)=(*top)->next;  //top is stored that is next to top so we could remove the topmost element of an Linked List
        int x=n->data;  //popped element will be stored in x
        free(n);
        return x;
    }
}
int main() {
    struct Node *top=NULL; //LinkedList is Empty
    // Push
    top=push(top,12);  //12 is the data of a Node i.e. to be inserted
    top=push(top,15);
    top=push(top,20);
    top=push(top,33);
    top=push(top,22);
    
    
    // Pop
    int element=pop(&top);   //we passed an address as whatever maybe the element, we are calling through reference i.e. pointer
    printf("Popped element is %d\n",element);
    
    // Traversal in Linked List
    Traversal(top);
    
    return 0;
}
