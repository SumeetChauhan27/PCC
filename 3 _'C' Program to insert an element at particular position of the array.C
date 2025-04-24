//3 'C' Program to insert an element at particular position of the array
#include <stdio.h>
#include <conio.h>

void main() {
    int arr[100], n, pos, i, item;
    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1) {
        printf("Invalid position!");
        getch();
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    for(i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = item;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    getch();
}
