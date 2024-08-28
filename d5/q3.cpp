#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int row;
    int col;
    int value;
    Node *next;
};

Node *createLinkedList(int matrix[5][5], int rows, int cols)
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int count = 0;

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (matrix[r][c] != 0)
            {
                count++;
                Node *newNode = new Node{r, c, matrix[r][c], nullptr};
                if (head == nullptr)
                {
                    head = newNode;
                    tail = head;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
    }
    Node *temp = new Node;

    cout << rows << " :: " << cols << " :: " << count << endl;
    temp->row = rows;
    temp->col = cols;
    temp->value = count;
    temp->next = head;

    head = temp;
    return head;
}

void displayLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << "Row: " << current->row << ", Col: " << current->col << ", Value: " << current->value << endl;
        current = current->next;
    }
}

int main()
{
    int matrix[5][5] = {
        {0, 0, 3, 0, 4},
        {5, 0, 0, 0, 0},
        {0, 6, 0, 7, 0},
        {0, 0, 0, 0, 8},
        {9, 0, 0, 0, 0}};

    Node *head = createLinkedList(matrix, 5, 5);

    cout << "converted" << endl;
    // Display
    cout << "Sparse Matrix represented as a linked list:" << endl;
    displayLinkedList(head);

    // CLEANING THE MEMORRYYYY....
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}