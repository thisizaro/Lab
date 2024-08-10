// reverse a 1d array using recursion

#include <stdio.h>

void reverse(int a[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
    reverse(a, l + 1, r - 1);
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
    reverse(a, 0, n - 1);
    printf("Reversed array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}