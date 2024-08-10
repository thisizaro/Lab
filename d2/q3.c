// Remove duplicates from a sorted array
#include <stdio.h>

void removeDuplicates(int a[], int *n)
{
    int j = 0;
    for (int i = 0; i < *n - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            a[j++] = a[i];
        }
    }
    a[j++] = a[*n - 1];
    *n = j;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    removeDuplicates(a, &n);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}