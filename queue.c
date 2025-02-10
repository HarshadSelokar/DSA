#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

void push(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->arr[q->rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

int pop(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int dequeuedValue = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        printf("%d dequeued from the queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    displayQueue(&q);

    printf("Peek front: %d\n", peek(&q));

    pop(&q);
    displayQueue(&q);

    push(&q, 40);
    push(&q, 50);
    displayQueue(&q);

    printf("Peek front: %d\n", peek(&q));

    pop(&q);
    displayQueue(&q);

    return 0;
}