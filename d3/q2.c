// C program to input a 2d array and print the sparse matrix

#include <stdio.h>

void sparseMatrix(int a[][100], int n, int m)
{
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != 0)
                count++;

    int sparseMatrix[3][count];
    int k = 1;
    sparseMatrix[0][0] = n;
    sparseMatrix[0][1] = m;
    sparseMatrix[0][2] = count;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != 0)
            {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = a[i][j];
                k++;
            }

    printf("Sparse Matrix:\n");
    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", sparseMatrix[i][j]);
        printf("\n");
    }

    // sparseMatrix(a, n, m);
}