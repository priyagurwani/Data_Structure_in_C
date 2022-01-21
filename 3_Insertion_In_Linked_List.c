//Why Linked List over Array? It is easy to add or delete elements in linked list and You don't need to declare size of a linked list 
// You can add as many elements you wanted to add 
// DrawBacks of Linked List: You need more memory than array as it stores data as well as pointer to next element, Memory address of each element is accessed randomly 
// So you need to traverse all the elements to get a required element
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
//CASE-1:
struct Node *InsertAtFirst(struct Node *head,int data){
    
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//CASE-2:
struct Node *InsertAtBetween(struct Node *head,int data,int index){
    
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (i!=index-1)  //If we want to insert at 3 it will stop at 2,if we want to insert at 6 it will stop at 5 and so on
    {
    p=p->next;  //p will traverse through linked list and visit each element and will stop when i will be at 2 or 5
    i++;
    }
    ptr->data=data;
    ptr->next=p->next;  //Here,it means p->next it should be now ptr->next
    p->next=ptr;  //Here, it means p-next should be ptr(ptr is The node that we want to insert)
    return head;
}
//CASE-3:
struct Node *InsertAtEnd(struct Node *head,int data){
    
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while (p->next!=NULL)
    {
        /* code */
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
//CASE-4:
struct Node *InsertAfterNode(struct Node *prevNode,int data,struct Node *head)
{    
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    
    ptr->next=prevNode->next;  // same logic as Case2:prevNode next now it will be ptr's next[Here,after second Node a number i.e ptr will be inserted ]
    //In above line,second points to third but ptr will point to third and below second will point to ptr
    prevNode->next=ptr; //prevNode:HERE is second , so second Node will point to ptr that we want to insert
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

    Traversal(head);
    printf("\nAfter Inserting at First Elements are:\n");
    head=InsertAtFirst(head,44);
    Traversal(head);
    printf("\nInserting at Between Elements are:\n");
    head=InsertAtBetween(head,77,4);  //here 4 is the index number. At index 4 we want to insert 77 
    Traversal(head);
    printf("\nInserting at End Elements are:\n");
    head=InsertAtEnd(head,99);   
    Traversal(head);
    printf("\nInserting After Node Elements are:\n");
    head=InsertAfterNode(second,45,head);  //here after second node 45 will get inserted. 
    Traversal(head);
}
