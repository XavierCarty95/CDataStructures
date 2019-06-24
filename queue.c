#include <stdlib.h>
#include <stdio.h>

#define SIZE 100



typedef struct{
    int item[SIZE];
    int rear , front;

}Queue;


void enqueue(Queue*, int);
int dequeue(Queue*);
void init(Queue*);

void init(Queue* qp){

     qp->front  = 0;
     qp->rear = 0;

 }

void enqueue(Queue* qp, int v )
{
    if(qp->rear == SIZE){
        printf("Queue Overflow");
        return;
    }

   qp->item[qp->rear] = v;
   qp->rear = qp->rear + 1;

}

int dequeue(Queue* qp){
    if(qp->front == qp->rear){
        printf("Queue Underflow");
        return -9999;
    }

    int v = qp->item[qp->front];
    qp->front = qp->front + 1;
    return v;
}

int main(){
    Queue q;
    init(&q);
    enqueue(&q, 20);
    enqueue(&q, 20);
    enqueue(&q, 20);
    enqueue(&q, 20);
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));

}
