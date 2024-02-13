#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
} *head, *temp, *newnode, *tail;

void display();
void insert();
void delete();
int count();
void reverse();

void beginsert();
void endinsert();
void begindelete();
void endelete();

void main()
{
    int choice = 0, contin;
    head = 0;
    do{
    newnode = (struct node*)malloc(sizeof(struct node));   
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        newnode->prev =tail;
        tail->next=newnode;
        tail=newnode;
    }
    printf("Do u wish to continue?\n");
    scanf("%d", &contin);
    }while(contin);
    
    while(choice!=10){        
    printf("Enter operation:\n 1. Insert\n 2. Delete\n 3. Display the list\n 4. Length of the list\n 5. Reverse the List\n");
    scanf("%d", &choice);
        switch(choice){
            case 1:
              insert();
              break;
            case 2:
              delete();
              break;
            case 3:
              display();
              break;
            case 4:
              printf("Number of elements in the list is %d\n", count());
              break;
            case 5:
              reverse();
              break;
            case 6:
              exit(0);
              break;
            default:
              printf("\nPlease enter valid choice..\n");
        }
    }
}

void beginsert()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void endinsert()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &newnode->data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insert()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    int pos, n, data, i=1;
    n = count();
    printf("Enter the inserting position: ");
    scanf("%d", &pos);
    if(pos<1 || pos>n+1){
        printf("Invalid position\n");
    }
    else if(pos == 1){
        beginsert();
    }
    else if(pos == n+1){
        endinsert();
    }
    else{
        printf("Enter the data to be inserted: ");
        scanf("%d", &newnode->data);
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

int count()
{
    int counts;
    temp = head;
    while(temp != NULL){
        temp = temp->next;
        counts++;
    }
    return counts;
}

void display()
{
    temp = head;
    while(temp!=tail){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    /*while(temp!=head){
        printf("%d\t", temp->data);
        temp=temp->prev;
    }
    printf("%d",temp->data);*/
}

void begindelete()
{
    if(head==0) printf("List is Empty.\n");
    else{
        temp = head;
        head = head->next;
        head->prev = 0;
        free(temp);
    }
}

void endelete()
{
    if(tail == 0) printf("List is Empty.\n");
    else{
        temp = tail;
        tail = tail->prev;
        tail->next = 0;
        free(temp);
    }
}

void delete()
{
    int n = count(), i=1, pos;
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    if(pos>n) printf("Invalid position\n");
    else if(pos == 1) begindelete();
    else if(pos == n) endelete();
    else{
        temp = head;
        while(i<pos){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void reverse()
{
    
}

