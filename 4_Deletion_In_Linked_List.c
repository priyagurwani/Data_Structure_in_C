#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void Traversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}

//Case 1: Delete the first element
struct Node *deletefirst(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;

}

//Case 2 : Delete the element from between
struct Node *deleteBetween(struct Node *head, int index){
    struct Node *p=head;
    struct Node *q=head->next;
    int i=0;
    while(i < index-1){
        q=q->next;
        p=p->next;
        i++;
    }
        p->next=q->next;
        free(q);
        return head;
}

//Case 3 : Delete the element from LinkedList (Specific Value) A similar to index
//there you need to find index , here you need to find a specific element 
struct Node *deleteValue(struct Node *head,int value){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
        return head;
}

//Case 4 : Delete the last element
struct Node *deleteLast(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
    }
        p->next=NULL;
        free(q);
        return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //memory allocating to the variable in list in heap memory
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    //link first and second nodes
    head->data=7;
    head->next=second;
    
    //link second and third nodes
    second->data=17;
    second->next=third;
    
    //link third and fourth nodes
    third->data=27;
    third->next=fourth;
    
    //Terminating fourth node
    fourth->data=37;
    fourth->next=NULL;

    printf("LinkedLISt Before Deletion is:\n");
    Traversal(head);


    head=deletefirst(head);
    //head=deletefirst(head);//If you run twice second element will also get delete
    printf("LinkedLISt After Deletion is:\n");
    Traversal(head);

    head=deleteBetween(head,2);
    printf("LinkedList deleting from Index number is:\n");
    Traversal(head);

    
    head=deleteValue(head,27);
    //If the element is not present it will return saame and nothing will be deleted
    //head=deleteValue(head,44);
    printf("LinkedList deleting The sepcific element is:\n");
    Traversal(head);


    // Comment above 3 deletion and then run the deleteLast 
    // i.e.below one
    // head=deleteLast(head);
    // printf("LinkedList deleting from last number is:\n");
    // Traversal(head);

}
