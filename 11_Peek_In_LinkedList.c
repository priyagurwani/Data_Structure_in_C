// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* top = NULL;
void Traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Elements are :%d\n",ptr->data);
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

int isFull(struct Node *top){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node *push(struct Node *top,int data){
    if(isFull(top)){
        printf("Stack overflow\n");
    }
    else{
        struct Node *n=(struct Node*)malloc(sizeof(struct Node));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct Node *tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node *n=tp;
        top=(tp)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
// To get a value at a particular position
int Peek(int pos){
    struct Node *ptr=top;
    int i=0;
    while(i<pos-1 && ptr!=NULL){
        ptr=ptr->next;
        i++;
    }
    if(ptr!=NULL){
        return ptr->data;
    }else{
        return -1;
    }
}

int StackTop(struct Node *top){
    return top->data;
}

int StackBottom(struct Node *top){
    while(top->next!=NULL){
        top=top->next;
    }
    return top->data;
}

int main() {
    // struct Node *top=NULL; //LinkedList is Empty
    // Push
    // top=push(top,12);  //12 is the data of a Node i.e. to be inserted
    top=push(top,15);
    top=push(top,20);
    top=push(top,33);
    top=push(top,22);
    

    Traversal(top);
    printf("Value at position 1 is :%d\n",Peek(1));
    // OR
    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, Peek(i));
    }
    
    top=StackTop(top);
    printf("TopMost element is %d\n",top);
    

    // To get the bottom element comment above as top should be == NULL after Traversal
    // printf("Bottom element is : %d\n",StackBottom(top));
    
    
   
    return 0;
}
