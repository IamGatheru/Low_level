#include <stdio.h>

int factorial(int x)
// Returns the factorial of x
{
    int i;

    for (i=1; i < x;  i++){
         x += i;
    }
    return x;
}

int main() {
    printf("The factorial of 5 is equal to: %d\n", factorial(5));

    return 0;
}