#include <bits/stdc++.h>
using namespace std;

typdef struct node
{
    int val;
    struct node *nxt;
} Node;

struct node *getNode(int val)
{
    struct node *temp = new node;
    temp->val = val;
    temp->nxt = NULL;
    return temp;
}

void insertQ(Node *head, int data)
{
    // if no element
    if(head == NULL)
    {
        Node temp = getNode(data);
        
    }
    // 
    int n = count(head);
    insertPos(*head, n, data);
}

void insertFrontQ(Node *head, int data)
{
}

void delQ(Node *head)
{
}

void delRearQ(Node *head)
{
}

int main()
{
    Node *head = NULL;
    int front = -1, rear = -1;

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
            insertQ(&head, data);
            break;

        case 2:
            cin >> data;
            insertFrontQ(&head, data);
            break;
        case 3:
            delQ();
            break;
        case 4:
            delRearQ();
            break;

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