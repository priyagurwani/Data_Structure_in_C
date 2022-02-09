// Implementation of Queue Using Array
// Queue=FIFO (First In First Out)
// Queue= Element in Array that is inserted first will get removed first

// Methods on Queue : 

// 1. Enqueue = A Person is standing in a queue
// 2. Dequeue = A Person whose work is done and standing out of the queue
// Initially queue is empty so Front_Index and Back_Index is -1
// 3. First Person = First Element = Front_Index+1
// 4. Last Person = Last Element = Back_Index
// 5. Peek (Element at a Particular Position)
// 6. IsEmpty = Queue will be empty if Front_Index==BackIndex
// 7. IsFull = Queue will be Full if Back_Index = size-1
                    
                    
#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int size;
    // front_index and rear_index both stores the inddex values they are not pointers
    int front_index;
    int rear_index;
    int *arr;
};

int isEmpty(struct Queue *q){
    if(q->rear_index==q->front_index){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Queue *q){
    if(q->rear_index==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
// Enqueue=to insert an element in queue
void Enqueue(struct Queue *q,int val){
    if(isFull(q)){
        printf("As Queue is Full, No Elements can be inserted\n");
    }
    else{
        q->rear_index++;
        q->arr[q->rear_index]=val;
    }
}

// Deque = To remove an element from queue
int Deque(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Stack is Empty,You can't remove an element\n");
        
    }
    else{
        q->front_index++;
        a=q->arr[q->front_index];
    }
    return a;
}

int main() {
    struct Queue q;
    q.size=10;
    // q.size=4;  //full or not
    q.front_index=q.rear_index=-1;  //It means both points to -1 and queue is empty
    // Allocating dynamic memory to array
    q.arr=(int*)malloc(q.size*(sizeof(int)));
    
    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    // Enqueue (Insert) elements as queue is empty
    Enqueue(&q,12);
    Enqueue(&q,20);
    Enqueue(&q,33);
    Enqueue(&q,25);
    // In Queue, Element that is inserted first will get remove first
    printf("Dequeue Element %d\n",Deque(&q));   //here 12 is dequeue i.e. removed
    printf("Dequeue Element %d\n",Deque(&q));
    
    if(isFull(&q)){
        printf("Queue is Full\n");  //as we have inserted 4 elements and size is 10 so nothing will print
        
        //if size==elements inserted queue is full wlll be printed
    }
    return 0;
}
