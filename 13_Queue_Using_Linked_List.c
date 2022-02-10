// Queue Using Linked List
// Enqueue= Insertion is done at rear (Last)
// Deque = DEletion is done at Front(First)
// n==NULL : Full
// Front==NULL : Empty
#include <stdio.h>
#include <stdlib.h>

// Initially , Queue IS Empty so Front and rear =  NULL
struct Node *front=NULL;
struct Node *rear=NULL;

struct Node{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Elements:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void Enqueue(int val){
    struct Node *n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(front==NULL){
            front=rear=n;   //Both will point to the element that is inserted
        }
        else{
            rear->next=n;
            // n->next=NULL;
            rear=n;
        }
    }
}

int Deque(){
    int val=-1;
    struct Node *ptr=front;
    if(front==NULL){
        printf("Queue is Empty\n");
    }
    else{
        front=front->next;
        val=ptr->data;
        free(ptr);
        
    }
    return val;
}

int main() {
    
    Traversal(front);
    
    printf("Initially Traversing when Queue is Empty:\n");
    // It will return -1 as initially Queue is empty
    printf("dequeing %d element\n",Deque());
    
    Enqueue(22);
    Enqueue(21);
    Enqueue(24);
    
    printf("After Traversing:\n");
    Traversal(front);
    
    // It will remove first element from Queue
    printf("dequeing %d element\n",Deque()); 
    printf("Traversing After Removing an element:\n");
    
    Traversal(front);
    
    return 0;
}
