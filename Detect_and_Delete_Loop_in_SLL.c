#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
} *head, *temp, *newnode;

void removeloop(struct node* head, struct node* node)
{
    struct node* node1 = node;
    struct node* node2 = node;

    unsigned int k=1, i;

    while(node1->next!=node2){
        node1 = node1->next;
        k++;
    }

    node1 = head;
    node2  = head;

    for(i=0; i<k; i++){
        node2 = node2->next;
    }

    while(node2!=node1){
        node1 = node1->next;
        node2 = node2->next;
    }

    while(node2->next!=node1){
        node2= node2->next;
    }

    node2->next = NULL;
}

void detectloop(struct node* list)
{
    struct node *slow_p = list, *fast_p = list;
  
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
  
        if (slow_p == fast_p) {
            removeloop(list, slow_p);
        }
    }
}

void display()
{
    temp = head;
    while(temp!=0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    int contin = 1;
    while(contin){
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if(head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        scanf("%d", &contin);
    }
    temp->next = head;
    //head->next->next->next->next->next = head->next->next;
    //detectloop(head);
    
    display();
}