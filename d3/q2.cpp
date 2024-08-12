#include <bits/stdc++.h>
using namespace std;

void sparse(int **a, int n, int m)
{
    // cout << "Sparse Matrix: \n";

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                c++;
            }
        }
    }

    int sp[c + 1][3];
    sp[0][0] = n;
    sp[0][1] = m;
    sp[0][2] = c;

    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k++][2] = a[i][j];
            }
        }
    }
    cout << "Sparse Matrix: \n";
    for (int j = 0; j < 3; j++)
    {
        cout << sp[0][j] << " ";
    }
    cout << endl;
    for (int i = 1; i <= c; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sp[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n = 5, m = 4;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m]();
    }

    // Randomly put some non zero elements elements
    a[0][2] = 3;
    a[1][1] = 4;
    a[3][0] = 5;
    a[3][3] = 6;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    sparse(a, n, m);
}