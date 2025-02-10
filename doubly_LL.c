#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
} *head = NULL;

void create();
void insert_at_beginning();
void insert_at_end();
void insert_at_specific();
void delete_at_beginning();
void delete_at_end();
void delete_at_specific();
void display();

int main() {
    int choice;

    for(int i=0; i<3; i++){
        printf("\nMenu\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Specific Position\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_at_beginning(); break;
            case 3: insert_at_end(); break;
            case 4: insert_at_specific(); break;
            case 5: delete_at_beginning(); break;
            case 6: delete_at_end(); break;
            case 7: delete_at_specific(); break;  
            case 8: display(); break;
            case 9: exit(0); break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void create() {
    int n, data;
    struct node* new_node, *temp;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            temp = head; 
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
    printf("Doubly linked list created.\n");
}

void insert_at_beginning() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &new_node->data);

    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL) {
        head->prev = new_node;
    }

    head = new_node;
    printf("Node is inserted at the beginning.\n");
}

void insert_at_end() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;

    printf("Enter data to insert at the end: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
    printf("Node is inserted at the end.\n");
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
        new_node->prev = NULL;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: Position not available in the list\n");
    } else {
        new_node->next = temp->next;
        new_node->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = new_node;
        }

        temp->next = new_node;
        printf("Node is inserted at position %d.\n", pos);
    }
}

void delete_at_beginning() {
    struct node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Node deleted from the beginning.\n");
}

void delete_at_end() {
    struct node* temp = head;

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
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Node deleted from the end.\n");
}

void delete_at_specific() {
    struct node* temp = head;
    int pos, i;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
    } else {
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
    }
}

void display() {
    struct node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
