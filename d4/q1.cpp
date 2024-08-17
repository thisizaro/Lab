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

void delPos() {}
void count() {}

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

void search()
{
}
void sort() {}
void rev() {}

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
            delPos();
            break;
        case 3:
            count();
            break;
        case 4:
            traverse(head);
            break;
        case 5:
            search();
            break;
        case 6:
            sort();
            break;
        case 7:
            rev();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }
}