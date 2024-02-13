#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *newnode, *temp;
struct node* front = 0;
struct node* rear = 0;

void enqueue(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    if(front == 0 && rear == 0){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    temp = front;
    if(front == 0 && rear == 0) printf("Queue is empty");
    else{
        front = front->next;
        free(temp);
    }
}

void display()
{
    temp = front;
    while(temp!=0){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void main()
{
    enqueue(20);
    enqueue(40);
    enqueue(60);
    enqueue(80);
    display();printf("\n");
    dequeue();
    dequeue();
    display();
}
