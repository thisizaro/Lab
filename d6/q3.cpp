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

// void printArray(int *n, int &top)
// {
//     cout << "Length: " << top << endl;
//     for (int i = 0; i <= sizeof(n); i++)
//     {
//         cout << n[i] << " ";
//     }
//     cout << endl;
// }

int main()
{
    int n;
    cout << "Enter the size of the stack: " << endl;
    cin >> n;

    int stack[n];
    int max[n];
    int top = -1, mtop = -1;
    int choice = 0, value;

    while (choice != 5)
    {

        cout << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Peek" << endl
             << "4. Max" << endl
             << "5. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // Push
            if (isFull(stack, top, n))
            {
                cout << "Stack is full." << endl;
                break;
            }
            else
            {
                cout << "Enter the value to push: ";
                cin >> value;

                if (isEmpty(stack, top))
                {
                    // cout << "... Stack is empty... pushing in both max and stack. " << endl;
                    push(stack, top, n, value);
                    push(max, mtop, n, value);
                    // printArray(stack, top);
                    // printArray(max, mtop);
                }
                else
                {
                    push(stack, top, n, value);
                    if (value >= max[mtop])
                    {
                        push(max, mtop, n, value);
                    }
                    // printArray(stack, top);
                    // printArray(max, mtop);
                }
            }

            break;

        case 2: // Pop
            // cout << "Popping..." << endl;
            if (isEmpty(stack, top))
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                int popped = pop(stack, top);
                if (popped == peek(max, mtop))
                {
                    pop(max, mtop);
                }
                cout << "Popped value: " << popped << endl;
            }
            break;
        case 3: // Peek
            // cout << "Peeking..." << endl;
            if (isEmpty(stack, top))
                cout << "Stack is empty." << endl;
            else
                cout << "Top value: " << peek(stack, top) << endl;

            break;
        case 4:
            if (isEmpty(max, mtop))
                cout << "Stack is empty." << endl;
            else
                cout << "Max value in the stack: " << max[mtop] << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    cout << "Max value in the stack: " << max[mtop] << endl;
}