#include <bits/stdc++.h>

using namespace std;

void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move " << n << " from: " << a << " to " << c << endl;
        return;
    }
    Hanoi(n - 1, a, c, b);
    cout << "Move " << n << " from: " << a << " to " << c << endl;
    Hanoi(n - 1, b, c, a);
}

int main()
{
    int n = 4;
    cout << "n: ";
    cin >> n;
    Hanoi(n, 'A', 'B', 'C');
}