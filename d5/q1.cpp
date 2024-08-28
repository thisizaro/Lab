#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *pre;
    node *nxt;
};

node *getnode(int val)
{
    node *temp = new node;
    temp->val = val;
    temp->nxt = NULL;
    temp->pre = NULL;
    return temp;
}

void insertPos(node *&head, int pos, int val)
{
    node *newNode = getnode(val);

    if (pos < 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1)
    {
        newNode->nxt = head;
        if (head != NULL)
        {
            head->pre = newNode;
        }
        head = newNode;
        return;
    }

    node *ptr = head;

    // Traverse to the position where we need to insert
    for (int i = 1; i < pos - 1; i++)
    {
        if (ptr == NULL)
        {
            cout << "Invalid position\n";
            return;
        }
        ptr = ptr->nxt;
    }

    if (ptr == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    newNode->nxt = ptr->nxt;
    if (ptr->nxt != NULL)
    {
        ptr->nxt->pre = newNode;
    }
    ptr->nxt = newNode;
    newNode->pre = ptr;
}

void delPos(node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    node *temp = head;

    if (pos == 1)
    {
        head = head->nxt;
        if (head != NULL)
        {
            head->pre = NULL;
        }
        delete temp;
        cout << "Deleted at position 1" << endl;
        return;
    }

    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid position\n";
            return;
        }
        temp = temp->nxt;
    }

    if (temp == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    if (temp->pre != NULL)
    {
        temp->pre->nxt = temp->nxt;
    }

    if (temp->nxt != NULL)
    {
        temp->nxt->pre = temp->pre;
    }

    delete temp;
    cout << "Deleted at position " << pos << endl;
}

int countNodes(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->nxt;
    }
    return count;
}

void traverse(node *head)
{
    cout << "Traversing" << endl;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val;
        if (temp->nxt != NULL)
            cout << " <-> ";
        temp = temp->nxt;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;

    for (int i = 0; i < 10; i++)
    {
        insertPos(head, i + 1, i);
    }

    traverse(head);

    for (int i = 4; i < 7; i++) // Delete node at position 2
    {
        delPos(head, i);
    }
    traverse(head);
    return 0;
}
