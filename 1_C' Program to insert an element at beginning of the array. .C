//1_C' Program to insert an element at beginning of the array. 

#include <stdio.h>
#include <conio.h>

void main() {
    int arr[100], n, i, item;
    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to insert at beginning: ");
    scanf("%d", &item);

    for(i = n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = item;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    getch();
}
