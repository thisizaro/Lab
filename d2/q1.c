#include <stdio.h>

void insertPos(int a[], int *l, int size);
void deletePos(int a[], int *l);
int linearSearch(int a[], int n, int x);

int main()
{
    int n, x;
    printf("Enter the size of the array: ");
    scanf("%d", &x);
    int a[x];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n > x)
    {
        printf("Invalid input\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    while (1)
    {
        printf("\nWhat's your choice: \n1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertPos(a, &n, x);
            break;
        case 2:
            deletePos(a, &n);
            break;
        case 3:
            printf("Enter the element to search: ");
            int ele;
            scanf("%d", &ele);
            int pos = linearSearch(a, n, ele);
            if (pos == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element found at index %d\n", pos);
            }
            break;

        case 4:
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}

void insertPos(int a[], int *l, int size)
{
    int n = *l;
    // n is the number of elements in the array
    if (n == size)
    {
        printf("Array is full\n");
        return;
    }

    int pos, x;
    printf("Enter the index and the element to insert: ");
    scanf("%d %d", &pos, &x);

    if (pos > n || pos < 0)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = x;
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", a[i]);
    }
    *l = n + 1;
}

void deletePos(int a[], int *l)
{
    printf("Enter the index to delete: ");
    int pos;
    scanf("%d", &pos);
    int n = *l;
    if (pos > n || pos < 0)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    *l = n - 1;
}

int linearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}