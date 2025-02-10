#include <stdio.h>
#include <stdlib.h>
void display();
void push();
void pop();

struct node
{
    int data;
    struct node *next;
}*top,*p;

void main()
{
    push();
    push();
    push();
    push();
    push();
    display();
    pop();
    pop();
    display();
}

void display()
{
    struct node *ptr;
    ptr=top;
    printf("Stack Data:\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void push()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=top;
    top=temp;
    printf("Enter the item to be pushed\n");
    scanf("%d",&temp->data);
}

void pop()
{
    struct node *t;
    t=top;
    top=top->next;
    free(t);
    printf("\nLast Element Deleted\n");
}












