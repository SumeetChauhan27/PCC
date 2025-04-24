//2 'C' Program to delete an element from beginning of the array. 
#include <stdio.h>
#include <conio.h>

void main() {
    int arr[100], n, i;
    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Deleting first element...\n");
    for(i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;

    printf("Array after deletion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    getch();
}
