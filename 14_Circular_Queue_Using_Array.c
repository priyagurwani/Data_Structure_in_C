// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
// Why Circular Queue ? Because We can use space efficiently
// In Linear Queue , if the elemnet is forwarded then you can't insert element at same index so space is not used efficiently.
// In Circulat Queue, you can reuse the space and reinsert the element at same index so space is reused.
struct CircularQueue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct CircularQueue *q){
    if(q->rear==q->front){
        return 1;
    }
    else{
        return 0;
    }
}
// (q->rear+1)%q->size==q->front
// It means suppose there are 3 elements thn size=3,front=0,rear=2 (index starts from 0)
// rear=2, 2+1=3 % 3 == 0 i.e. front 
// Then it is full i.e. Circular Queue
int isFull(struct CircularQueue *q){
    if((q->rear+1)%q->size==q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(struct CircularQueue *q,int val){
    if(isFull(q)){
        printf("Queue is Full i.e. Overflow\n");
    }
    else{
        printf("Enqueued element : %d\n",val);
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=val;
    }
}

int Dequeue(struct CircularQueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is empty i.e. Underflow\n");
    }
    else{
        // Initially front =0 then f+1 = f[1] that is first element of array is removed
        // 1%3=1 so element at 1 (first) index is removed
        // Because Queue follows FIFO
        q->front=(q->front+1)%q->size;
        a=q->arr[q->front];
    }
    return a;
}
int main() {
    struct CircularQueue q;
    q.size=3;
    // In Circular Queue, front=rear=0 then size-1 element you can insert
    // size is 3 you can insert 2 elements ,size is 4 you can insert 3 elements
    q.front=q.rear=0;
    q.arr=(int*)malloc(q.size * sizeof(int));
    
    Enqueue(&q,12);
    Enqueue(&q,15);

    
    printf("Dequeing element %d\n",Dequeue(&q));
    printf("Dequeing element %d\n",Dequeue(&q));
    
    // As you reinserted the elments and you can use the same space so circular Queue is useful
    // So below gives stack is full
    // EVen if you enque and deque and try to reinsert the elements in Linear Queue it will show queue is full
    // As you can see here same process is done we can reinsert the elements
    Enqueue(&q,97);
    Enqueue(&q,99);
    
    
    if(isEmpty(&q)){
        printf("Stack Empty\n");
    }
    
    if(isFull(&q)){
        printf("Stack Full\n");
    }
  
    return 0;
}
