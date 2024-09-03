#include <bits/stdc++.h>
using namespace std;

int isEmpty(char *stack, int top)
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(char *stack, int top, int n)
{
    if (top == n - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek(char *stack, int top)
{
    if (isEmpty(stack, top))
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void push(char *stack, int &top, int n, char value)
{
    if (isFull(stack, top, n))
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop(char *stack, int &top)
{
    if (isEmpty(stack, top))
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

int main()
{
    char stack[5];
    int top = -1;

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            push(stack, top, 5, s[i]);
        }
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
        {
            if (isEmpty(stack, top))
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                char c = pop(stack, top);
                if (c == '{' && s[i] == '}')
                    continue;
                else if (c == '(' && s[i] == ')')
                    continue;
                else if (c == '[' && s[i] == ']')
                    continue;
                else
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    if (isEmpty(stack, top))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
