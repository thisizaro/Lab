#include <bits/stdc++.h>
using namespace std;

void trav(int dQ[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << dQ[i] << " ";
    }
    cout << endl;
}

// double ended queue using array
void insertFront(int dQ[], int n, int *front, int *rear, int v)
{
    if (*front == 0)
    {
        if (*rear == n - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            // cout << "reached" << endl;
            for (int i = *rear; i >= *front; i--)
            {
                // cout << "reached " << i << endl;
                dQ[i + 1] = dQ[i];
            }
            // cout << "reached" << endl;
            *rear = *rear + 1;
            *front = *front + 1;
            // cout << "f: " << *front << "r: " << *rear << endl;
        }
    }
    if (*front == -1)
    {
        *front = *rear = 0;
        dQ[*front] = v;
    }
    if (*front > 0)
    {
        *front = *front - 1;
        dQ[*front] = v;
    }
    trav(dQ, 10);
}

void insert(int dQ[], int n, int *front, int *rear, int v)
{
    if (*rear == n - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (*front == -1)
    {
        *front = *rear = 0;
        dQ[*rear] = v;
    }
    else
    {
        *rear = *rear + 1;
        dQ[*rear] = v;
    }
    trav(dQ, 10);
}

void del(int dQ[], int n, int *front, int *rear)
{
    if (*front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (*front == *rear)
    {
        cout << "Deleted element is " << dQ[*front] << endl;
        *front = *rear = -1;
    }
    else
    {
        cout << "Deleted element is " << dQ[*front] << endl;
        *front = *front + 1;
    } 
    trav(dQ, 10);
}

void deleteRear(int dQ[], int n, int *front, int *rear)
{
    if (*front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (*front == *rear)
    {
        cout << "Deleted element is " << dQ[*rear] << endl;
        *front = *rear = -1;
    }
    else
    {
        cout << "Deleted element is " << dQ[*rear] << endl;
        *rear = *rear - 1;
    }
    trav(dQ, 10);
}

int main()
{
    int dQ[10];
    int front = -1, rear = -1;

    for (int i = 0; i < 10; i++)
    {
        dQ[i] = 0;
    }

    // insert at front

    while (1)
    {

        int data = 5;
        int choice;
        cout << "1: insert()\n"
             << "2: insertFront()\n"
             << "3: del()\n"
             << "4: deleteRear()\n"
             << "5: exit()";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> data;
            insert(dQ, 10, &front, &rear, data);
            break;

        case 2:
            cin >> data;
            insertFront(dQ, 10, &front, &rear, data);
            break;
        case 3:
            del(dQ, 10, &front, &rear);
            break;
        case 4:
            deleteRear(dQ, 10, &front, &rear); break;

        case 5:
            return 0;
            break;
        default:
            cout << "Invalid choice";
        }
    }

    // del from rear
    // deleteRear(dQ, 10, &front, &rear);
}