#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *newnode, *temp;
struct node* top;

void push(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    if(top == NULL) top = newnode;
    else{
        newnode->next = top;
        top = newnode;
    }
}

void pop()
{
    temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    temp = top;
    while(temp!=0){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    //this is the main method
    push(40);
    push(400);
    push(4);
    push(44);
    pop();
    display();printf("\n");
    push(0.4);
    pop();
    pop();
    push(404);
    display();
}