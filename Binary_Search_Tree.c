#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
} *root, *newnode;

typedef struct node node;
void search(node* , int, node*);

node *create(int item)
{
    newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *insertion(node *root, int item)
{
    if(root == 0) return create(item);

    if(item < root->data) root->left = insertion(root->left, item);

    else root->right = insertion(root->right, item);
}

void inorder(node *root)
{
    if(root == 0) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
    
}

node* inordersuccessor(node* curr)
{
    while(curr->left != NULL) curr = curr->left;
    return curr;
}

node* deleteNode(node* root, int data)
{
    if(root == NULL) return root;

    if(data < root->data) 
        root->left = deleteNode(root->left, data);
    else if(data > root->data) 
        root->right = deleteNode(root->right, data);
    else{
        if(root->left == NULL){
            node* tmp = root->right;
            free(root);
            return tmp;
        }
        else if(root->right == NULL){
            node* tmp = root->left;
            free(root);
            return tmp;
        }
        node* tmp = inordersuccessor(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}

int main()  
{  
  root = insertion(root, 45);  
  root = insertion(root, 30);  
  root = insertion(root, 50);  
  root = insertion(root, 25);  
  root = insertion(root, 35);  
  root = insertion(root, 45);  
  root = insertion(root, 60);  
  root = insertion(root, 4);  
  printf("The inorder traversal of the given binary tree is - \n");  
  inorder(root);  printf("\n");
  deleteNode(root, 45); 
  inorder(root);  
  /*printf("\nAfter deleting node 25, the inorder traversal of the given binary tree is - \n");  
  inorder(root);   
  insertion(root, 2);  
  printf("\nAfter inserting node 2, the inorder traversal of the given binary tree is - \n");  
  inorder(root);  
  return 0;  */
}

void search(node* curr, int item, node* parent)
{
    while(curr != NULL && curr->data != item){
        parent = curr;
        if(item < curr->data) curr = curr->left;
        else curr = curr->right;
    }
}
