#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createCircularLinkedList(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    Node *head = new Node();
    head->data = arr[0];
    Node *current = head;

    for (int i = 1; i < size; ++i)
    {
        Node *newNode = new Node();
        newNode->data = arr[i];
        current->next = newNode;
        current = newNode;
    }

    current->next = head; // Complete the circle
    return head;
}

void displayCircularLinkedList(Node *head)
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *circularList = createCircularLinkedList(arr, size);

    cout << "Elements in the circular linked list are: ";
    displayCircularLinkedList(circularList);

    // Free the memo
    if (circularList)
    {
        Node *current = circularList;
        Node *nextNode;
        do
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != circularList);
    }

    return 0;
}
