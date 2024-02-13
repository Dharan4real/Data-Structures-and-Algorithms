#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
    int height;
} *root;
typedef struct Node node;

int height(node* n)
{
    if(n==NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a > b)? a:b;
}

int getBalance(node *n)
{
    if (n==NULL)
        return 0;
    return height(n->left) - height(n->right);
}

node* newnode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

node* leftRotate(node *x)
{
    node *y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node* rightRotate(node *y)
{
    node *x = y->left, *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return x;
}

node* insert(node* root, int x)
{
    if(root == NULL)
        return newnode(x);

    if(root->data > x)
        root->left = insert(root->left, x);
    else if(root->data < x)
        root->right = insert(root->right, x);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && root->left->data > x)
        return rightRotate(root);

    if(balance < -1 && root->right->data < x)
        return leftRotate(root);

    if(balance > 1 && root->left->data < x)
    {   root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && root->right->data > x){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    root = NULL;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 45);
    root = insert(root, 43);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 65);

    preOrder(root);
    return 0;
}
