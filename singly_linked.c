#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
}*head = NULL;

void create();
void display(); 
void insert_begin();
void insert_at_end();
void insert_at_specific();
void delete_at_beginning();
void delete_at_end();
void delete_at_specific();
void search();

int main() {
    int choice;

    for(int i=0; i<3; i++){
        printf("\nMenu\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Specific Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Specific Position\n");
        printf("9. Search Element\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); 
                break;
            case 2: display(); 
                break;
            case 3: insert_begin(); 
                break;
            case 4: insert_at_end(); 
                break;
            case 5: insert_at_specific(); 
                break;
            case 6: delete_at_beginning(); 
                break;
            case 7: delete_at_end(); 
                break;
            case 8: delete_at_specific(); 
                break;
            case 9: search(); 
                break;
            case 10: exit(0); 
                break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void create() {
    struct node *ptr, *temp;
    int n, data;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        ptr->data = data;
        ptr->next = NULL;       

        if (head == NULL) {
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
}

void display() {
    struct node* temp = head;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("\nLinked List Data: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_begin() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter data to insert at beginning: ");
    scanf("%d", &new_node->data);

    new_node->next = head;
    head = new_node;

}

void insert_at_end() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;

    printf("Enter data to insert at end: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

}

void insert_at_specific() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    int pos, i;

    printf("Enter data to insert: ");
    scanf("%d", &new_node->data);
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
    } 
    else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_at_beginning() {
    struct node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    head = head->next;
    free(temp);
}

void delete_at_end() {
    struct node *temp = head, *prev;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void delete_at_specific() {
    struct node *temp = head, *prev;
    int pos, i;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void search() {
    struct node* temp = head;
    int value, pos = 1;

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found in the list\n", value);
}