#include <bits/stdc++.h>
using namespace std;

int count0(int **a, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (a[i][j] == 0)
                k++;
        }
    }
    return k;
}

void upmat(int **a, int n)
{
    cout << "Upper Triangular Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
                cout << a[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Zeros = " << count0(a, n);
    upmat(a, n);
}