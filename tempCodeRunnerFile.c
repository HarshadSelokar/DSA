#include <stdio.h>
#include <stdlib.h>

struct node{

	int data;
	struct node* next;

}*head=NULL;

void create(){

	struct node *temp, *ptr;
	int n, data;
	printf("\nEnter number of Nodes : ");
	scanf("%d", &n);


	for(int i=0; i<n; i++){
		ptr=(struct node*)malloc(sizeof(struct node));

		printf("\nEnter data : ");
		scanf("%d", &data);

		ptr->data=data;
		ptr->next=NULL;

		if(head==NULL){
			head=ptr;
		}
		else{
			temp = head;
			while(temp->next != NULL){

				temp=temp->next;

			}
			temp->next=ptr;



		}

	}

}


void display(){

	struct node *ptr;

	ptr=head;
	if(head == NULL){

		printf("Linked list is empty!\n");
		return;
	}

	
	while(ptr != NULL){

		printf("%d -> ", ptr->data);
		ptr=ptr->next;

	}

}

void ib(){

	struct node *new=(struct node*)malloc(sizeof(struct node));

	printf("\nEnter new data :");
	scanf("%d", &new->data);
	new->next=head;
	head=new;
	

}


void ie(){

	struct node *temp, *new=(struct node*)malloc(sizeof(struct node));

	printf("\nEnter new data :");
	scanf("%d", &new->data);
	new->next=NULL;

	if(head == NULL){

		head=new;
	}
	else{

		temp=head;

		while(temp->next != NULL){

			temp=temp->next;
		}
		temp->next=new;
	}

}

void main(){

	create();
	display();
	// ib();
	ie();
	display();
}
