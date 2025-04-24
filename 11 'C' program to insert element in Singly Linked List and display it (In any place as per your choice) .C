//11 'C' program to insert element in Singly Linked List and display it (In any place as per your choice) 
#include <stdio.h>
#include <conio.h>
#include <alloc.h>  /* For Turbo C */

struct Node {
    int data;
    struct Node *next;
};

/* Function to create a new node */
struct Node* createNode(int data) {
    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Function to display the linked list */
void displayList(struct Node* head) {
    struct Node* temp;
    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Function to insert a node at a user-defined position */
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode;
    struct Node* temp;
    int i;

    newNode = createNode(data);
    if (newNode == NULL)
        return head;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position! Node not inserted.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void main() {
    struct Node* head;
    struct Node* temp;
    struct Node* newNode;
    int n, i, data, pos;

    head = NULL;
    temp = NULL;

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = createNode(data);
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    displayList(head);

    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    head = insertAtPosition(head, data, pos);

    displayList(head);

    getch();
}
