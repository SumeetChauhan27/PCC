//12 'C' program to delete element from Singly Linked List and display it. (In any place as per your choice)
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

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

/* Function to delete a node at a user-defined position */
struct Node* deleteAtPosition(struct Node* head, int position) {
    struct Node* temp;
    struct Node* toDelete;
    int i;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (position == 1) {
        toDelete = head;
        head = head->next;
        printf("Deleted node with data: %d\n", toDelete->data);
        free(toDelete);
        return head;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position! Deletion failed.\n");
        return head;
    }

    toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted node with data: %d\n", toDelete->data);
    free(toDelete);
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

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    head = deleteAtPosition(head, pos);

    displayList(head);

    getch();
}
