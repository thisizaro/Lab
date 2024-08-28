#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *nxt;
};

struct node *getnode(int val)
{
    struct node *temp = new node;
    temp->val = val;
    temp->nxt = NULL;
    return temp;
}

void insertPos(node *head, int pos, int val)
{
    struct node *temp = head;
    struct node *newNode = getnode(val);
    if (pos == 1)
    {
        newNode->nxt = head;
        head = newNode;
        return;
    }
    while (temp->nxt != NULL && --pos)
    {
        temp = temp->nxt;
        if (pos == 0)
        {
            newNode->nxt = temp->nxt;
            temp->nxt = newNode;
            return;
        }
    }
    cout << "Invalid position\n";
}

void delPos(node *head, int pos)
{
    struct node *temp = head;
    if (temp == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    if (pos == 1)
    {
        head = head->nxt;
        free(temp);
        return;
    }
    while (temp->nxt != NULL && --pos)
    {
        temp = temp->nxt;
        if (pos == 0)
        {
            struct node *temp2 = temp->nxt;
            temp->nxt = temp2->nxt;
            free(temp2);
            return;
        }
    }
    cout << "Invalid position\n";
}
int count(node *head)
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->nxt;
    }
    return count;
}

void traverse(node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->nxt;
        cout << " -> ";
    }
    cout << endl;
}

int search(node *head, int k)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->val == k)
        {
            return 1;
        }
        temp = temp->nxt;
    }
    return 0;
}
void sortLinkedList(node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *temp2 = temp->nxt;
        while (temp2 != NULL)
        {
            if (temp->val > temp2->val)
            {
                int t = temp->val;
                temp->val = temp2->val;
                temp2->val = t;
            }
            temp2 = temp2->nxt;
        }
        temp = temp->nxt;
    }
}

void rev(node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nxt = NULL;
    while (curr != NULL)
    {
        nxt = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

int main()
{
    int ch;
    struct node *head = getnode(1);
    head->nxt = getnode(2);
    head->nxt->nxt = getnode(3);
    head->nxt->nxt->nxt = getnode(4);
    while (1)
    {
        cout << "1. Insert at position" << endl
             << "2. Delete at position" << endl
             << "3. Count" << endl
             << "4. Traverse" << endl
             << "5. Search" << endl
             << "6. Sort" << endl
             << "7. Reverse" << endl
             << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            int pos, val;
            cout << "Enter position and value: ";
            cin >> pos >> val;
            insertPos(head, pos, val);
            break;
        case 2:
            delPos(head, pos);
            break;
        case 3:
            count(head);
            break;
        case 4:
            traverse(head);
            break;
        case 5:
            search(head, val);
            break;
        case 6:
            sortLinkedList(head);
            break;
        case 7:
            rev(head);
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }
}