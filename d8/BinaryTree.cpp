#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} Node;

Node *getnode(int val)
{
    Node *temp = new Node;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Create binary tree

Node *create()
{
    Node *root = getnode(1);
    root->left = getnode(2);
    root->right = getnode(3);
    root->left->left = getnode(4);
    root->left->right = getnode(5);
    root->right->left = getnode(6);
    root->right->right = getnode(7);
    return root;
}

// height of binary tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lht = height(root->left);
        int rht = height(root->right);

        if (lht > rht)
        {
            return lht + 1;
        }
        else
        {
            return rht + 1;
        }
    }
}

// preorder traversal non recursive
void preorder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        cout << temp->val << " ";
        s.pop();
        if (temp->right)
        {
            s.push(temp->right);
        }
        if (temp->left)
        {
            s.push(temp->left);
        }
    }
}

// inorder traversal non recursive
void inorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

// postorder traversal non recursive
void postorder(Node *root)
{
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
        {
            s1.push(temp->left);
        }
        if (temp->right)
        {
            s1.push(temp->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

int main()
{
    Node *root = create();
    cout << "Height of binary tree: " << height(root) << endl;

    while (1)
    {
        cout << "Choice of traversal: \n"
             << "1. Preorder\n"
             << "2. Inorder\n"
             << "3. Postorder\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
}
