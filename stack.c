
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{

    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    if (top == MAX - 1)
    {
        printf("Stack Overflow! Unable to push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

void pop()
{

    if (top == -1)
    {

        printf("Stack Underflow! Stack is empty.\n");
    }
    else
    {

        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

void peek()
{

    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}

void display()
{

    if (top == -1)
    {

        printf("Stack is underflow.\n");
    }
    else
    {

        printf("Stack elements: ");

        for (int i = 0; i <= top; i++)
        {

            printf("| %d | ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{

    int choice;
    int c;
    c = 4;

    printf("\n \nName - Harshad Vijay Selokar\n");
    printf("UID - 23001063");

    while (c--)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            push();
            push();
            display();
            break;

        case 2:
            pop();
            display();
            break;

        case 3:
            peek();
            display();
            break;

        case 4:
            display();
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
