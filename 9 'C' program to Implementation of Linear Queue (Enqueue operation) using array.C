//9 'C' program to Implementation of Linear Queue (Enqueue operation) using array
#include <stdio.h>
#include <conio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        if(front == -1) front = 0;  // first element
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

void display() {
    int i;
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for(i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main() {
    int choice, value;
    clrscr();

    while(1) {
        printf("\n1. Enqueue\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    getch();
}
