#include <stdio.h>

void compareNumbers(int *a, int *b);

int main()
{
    int n1, n2;

    printf("Enter the first number: ");
    scanf("%d", &n1);
    printf("Enter the second number: ");
    scanf("%d", &n2);

    compareNumbers(&n1, &n2);
    return 0;
}

void compareNumbers(int *a, int *b)
{
    if (*a > *b)
    {
        printf("%d is greater than %d\n", *a, *b);
    }
    else if (*a < *b)
    {
        printf("%d is less than %d\n", *a, *b);
    }
    else
    {
        printf("%d is equal to %d\n", *a, *b);
    }
}
