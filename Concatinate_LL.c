#include<stdio.h>
void create_list1();
void create_list2();
void display();
void Concatinate();
struct node
{
    int data;
    struct node *next;
}*head1,*head2;
void main()
{
    printf("Enter First List\n");
    create_list1();
    printf("Enter Second List\n");
    create_list2();
    Concatinate();
    printf("List After Concatination\n");
    display();
}
void create_list1()
{
    struct node *ptr;
    int n,k;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        if(k==0)
        {
            ptr=(struct node*)malloc(sizeof(struct node));
            head1=ptr;
            ptr->next=NULL;
        }
        else
        {
            ptr->next=(struct node*)malloc(sizeof(struct node));
            ptr=ptr->next;
            ptr->next=NULL;
        }
        printf("Enter the data for %d node:\n",k+1);
        scanf("%d",&ptr->data);
    }
}
void create_list2()
{
    struct node *ptr;
    int n,k;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        if(k==0)
        {
            ptr=(struct node*)malloc(sizeof(struct node));
            head2=ptr;
            ptr->next=NULL;
        }
        else
        {
            ptr->next=(struct node*)malloc(sizeof(struct node));
            ptr=ptr->next;
            ptr->next=NULL;
        }
        printf("Enter the data for %d node:\n",k+1);
        scanf("%d",&ptr->data);
    }
}
void Concatinate()
{
    struct node *ptr;
    ptr=head1;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head2;
}
void display()
{
    struct node *ptr;
    ptr=head1;
    printf("Linked List Data:\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

