//7 'C' program to Implementation of Stack (PUSH operations and display) using array. 
#include <stdio.h>
#include <conio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if(top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

void display() {
    int i;
    if(top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for(i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void main() {
    int choice, value;
    clrscr();
    
    while(1) {
        printf("\n1. Push\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
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
