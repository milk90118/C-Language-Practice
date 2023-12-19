#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct
{
    int items[SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q -> front = -1;
    q -> rear = -1;
}

bool isFull(Queue *q)
{
    if(q -> rear == SIZE - 1) return true;
    else return false;
}

bool isEmpty(Queue *q)
{
    if(q -> front == -1) return true;

    else return false;
}

void enqueue(Queue* q, int element)
{
    if(isFull(q))
    {
        printf("Queue is full!\n");
    }

    else
    {
        if(q -> front == -1) q -> front = 0;

        q -> rear++;
        q -> items[q -> rear] = element;
        printf("Inserted -> %d\n", element);
    }
}

int dequeue(Queue *q)
{
    int element;

    if(isEmpty(q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        element = q -> items[q -> front];
        q -> front++;

        if(q -> front > q -> rear)
        {
            printf("Resetting queue.\n");
            initQueue(q);
        }
        return element;
    }
}

void display(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty!\n");
    }
    else{
        printf("Queue elements are:\n");

        for(int i = q -> front; i <= q -> rear; ++i)
        {
            printf("%d ", q -> items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);

    return 0;
}