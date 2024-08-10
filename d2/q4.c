// First postive no. missing from an array
#include <stdio.h>

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int first(int a[], int n)
{
    sort(a, n);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            continue;
        }
        if (a[i] == ans)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    return ans;
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
    int ans = first(a, n);
    printf("First missing positive number: %d\n", ans);
    return 0;
}