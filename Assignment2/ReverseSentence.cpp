#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = s.size() - 2;

    string words = "";
    stack<string> st;

    char c = s[n];
    s = s.substr(1, n - 1);
    s = s + " ";
    n = s.size();
    s[0] = (char)(s[0] + 32);
    int f = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (f == 0)
            {
                f = 1;
                words = words + c;
            }
            st.push(words);
            words = "";
        }
        else
        {
            words += s[i];
        }
    }

    cout << "\"";
    while (!st.empty())
    {
        words = st.top();
        if (f == 1)
        {
            f = 0;
            cout << (char)(words[0] - 32);
            cout << words.substr(1, words.size() - 1);
        }
        else
        {
            cout << words;
        }

        st.pop();
        if (!st.empty())
        {
            cout << " ";
        }
    }
    cout << "\"";
}