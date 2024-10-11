#include <bits/stdc++.h>
using namespace std;

// double ended queue using array
void insertFront(int dQ[], int n, int *front, int *rear, int data)
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
            *rear++;
            *front++;
            // cout << "reached" << endl;
        }
    }
    if (*front == -1)
    {
        *front = *rear = 0;
        dQ[*front] = data;
    }
    else
    {
        *front = *front - 1;
        dQ[*front] = data;
    }
}

void insert(int dQ[], int n, int *front, int *rear, int data)
{
    if (*rear == n - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    if (*front == -1)
    {
        *front = *rear = 0;
        dQ[*rear] = data;
    }
    else
    {
        *rear = *rear + 1;
        dQ[*rear] = data;
    }
}

void deleteFront(int dQ[], int n, int *front, int *rear)
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
    int data = 5;
    insertFront(dQ, 10, &front, &rear, data);
    for (int i = 0; i < 10; i++)
    {
        cout << dQ[i] << " ";
    }
    cout << endl;

    data = 7;
    // insert at rear
    insert(dQ, 10, &front, &rear, data);
    for (int i = 0; i < 10; i++)
    {
        cout << dQ[i] << " ";
    }
    insertFront(dQ, 10, &front, &rear, data);
    insertFront(dQ, 10, &front, &rear, data);
    insertFront(dQ, 10, &front, &rear, data);

    // delete from front
    // deleteFront(dQ, 10, &front, &rear);

    // delete from rear
    // deleteRear(dQ, 10, &front, &rear);

    for (int i = 0; i < 10; i++)
    {
        cout << dQ[i] << " ";
    }
}