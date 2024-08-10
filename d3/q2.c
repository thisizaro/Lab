// C program to input a 2d array and print the sparse matrix

#include <stdio.h>

void sparseMatrix(int a[][100], int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != 0)
                count++;

    int sparseMatrix[3][count];
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != 0)
            {
                sparseMatrix[0][k] = i;
                sparseMatrix[1][k] = j;
                sparseMatrix[2][k] = a[i][j];
                k++;
            }

    printf("Sparse Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < count; j++)
            printf("%d ", sparseMatrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    sparseMatrix(a, n, m);
}