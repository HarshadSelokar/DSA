#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

typedef struct Queue
{
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full! Cannot enqueue %d\n", value);
    }
    else
    {
        if (q->front == -1)
        { // If queue is empty
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    else
    {
        int dequeuedValue = q->arr[q->front];
        if (q->front == q->rear)
        {                            // Only one element in the queue
            q->front = q->rear = -1; // Reset the queue
        }
        else
        {
            q->front = (q->front + 1) % MAX;
        }
        printf("%d dequeued from the queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    }
    else
    {
        return q->arr[q->front];
    }
}

void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue contents: ");
        int i = q->front;
        while (i != q->rear)
        {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[q->rear]); // Print the last element
    }
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    printf("Peek front: %d\n", peek(&q));

    dequeue(&q);
    displayQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This will be inserted into the circular part
    displayQueue(&q);

    printf("Peek front: %d\n", peek(&q));

    dequeue(&q);
    displayQueue(&q);

    return 0;
}