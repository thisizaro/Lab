#include <bits/stdc++.h>

using namespace std;

void transpose(int a[][3], int c)
{
    for (int i = 0; i <= c; i++)
    {
        int temp = a[i][0];
        a[i][0] = a[i][1];
        a[i][1] = temp;
    }
}

int main()
{
    int n, m, c;
    cout << "Enter the First row of the sparse matrix: " << endl;

    cin >> n >> m >> c;
    int sp[c + 1][3];
    sp[0][0] = n;
    sp[0][1] = m;
    sp[0][2] = c;

    cout << "Enter the elemnts of the sparse matrix: " << endl;
    for (int i = 1; i < c + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> sp[i][j];
        }
    }

    cout << "Before Transpose: " << endl;
    for (int i = 0; i < c + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sp[i][j] << " ";
        }
        cout << endl;
    }

    transpose(sp, c);
    cout << "After Transpose: " << endl;
    for (int i = 0; i < c + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sp[i][j] << " ";
        }
        cout << endl;
    }
}
