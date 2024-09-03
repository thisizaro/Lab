#include <bits/stdc++.h>
using namespace std;

int isEmpty(int *stack, int top)
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

int isFull(int *stack, int top, int n)
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

int peek(int *stack, int top)
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

void push(int *stack, int &top, int n, int value)
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

int pop(int *stack, int &top)
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
    int stack[5];
    int top = -1;

    int choice = 0, value;
    while (choice != 4)
    {

        cout << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Peek" << endl
             << "4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (isFull(stack, top, 5))
            {
                cout << "Stack is full." << endl;
                break;
            }
            else
            {
                cout << "Enter the value to push: ";
                cin >> value;
                push(stack, top, 5, value);
            }
            break;
        case 2:
            if (isEmpty(stack, top))
            {
                cout << "Stack is empty." << endl;
            }
            else
                cout << "Popped value: " << pop(stack, top) << endl;
            break;
        case 3:
            if (isEmpty(stack, top))
                cout << "Stack is empty." << endl;
            else
                cout << "Top value: " << peek(stack, top) << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}
