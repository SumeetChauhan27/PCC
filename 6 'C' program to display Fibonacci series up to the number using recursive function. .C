//6 'C' program to display Fibonacci series up to the number using recursive function. 
#include <stdio.h>
#include <conio.h>

int fibonacci(int n) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void main() {
    int n, i;
    clrscr();

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series:\n");
    for(i = 0; i < n; i++)
        printf("%d ", fibonacci(i));

    getch();
}
