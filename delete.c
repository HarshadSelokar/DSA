#include <stdio.h>
#include <stdlib.h>

void display();
void create1();
void create2();
void concatinate();

struct node {

    int data;
    struct node *next;
} *head1, *head2;

void main(){

    printf("\nfirst list : ");
    create1();
    printf("\nsecond List : ");

    create2();
    
    concatinate();
    display();
}

void create1(){

    struct node *ptr;
    int n;
    printf("\nEnter node count : ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){

        if(i==1){
            ptr=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter data of %d node : ", i);
            scanf("%d", &ptr->data);
            ptr=(struct node *)malloc(sizeof(struct node));
            head1=ptr;
            ptr->next=NULL;
        }
        else{

            ptr->next=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter data of %d node : ", i);
            scanf("%d", &ptr->data);
            ptr=ptr->next;
            ptr->next=NULL;

        }
    }
}

void create2(){

    struct node *ptr;
    int n;
    printf("\nEnter node count : ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){

        if(i==1){
            ptr=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter data of %d node : ", i);
            scanf("%d", &ptr->data);
            ptr=(struct node *)malloc(sizeof(struct node));
            head2=ptr;
            ptr->next=NULL;
        }
        else{

            ptr->next=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter data of %d node : ", i);
            scanf("%d", &ptr->data);
            ptr=ptr->next;
            ptr->next=NULL;

        }
    }
}

void concatinate(){

    struct node *ptr;
    ptr=head1;
    while(ptr->next !=NULL){

        ptr=ptr->next;
    }
    ptr->next=head2;


}
void display(){

    struct node *ptr;

    ptr=head1;
    while(ptr->next !=NULL){

        printf("\t%d", ptr->data);
        ptr=ptr->next;

    }
}