// Circular Linked List doesn't has first element 
// You choose any element and traverse all the elements
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
//Traversal in Circular Linked Lisst
void LinkedList(struct Node *head){
    struct Node *ptr=head;
//     printf("Element is:%d\n",ptr->data); //It prints the first element
//     ptr=ptr->next;
//     while(ptr!=head){
//         printf("Element is:%d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }
//INSTEAD OF THIS YOU CAN USE DO WHILE LOOP
do{
        printf("Element is:%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
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
    head->data=4;
    head->next=second;
    
    //link second and third nodes
    second->data=3;
    second->next=third;
    
    //link third and fourth nodes
    third->data=6;
    third->next=fourth;
    
    //Terminating fourth node
    fourth->data=1;
    fourth->next=head;

    LinkedList(head);
    
}
