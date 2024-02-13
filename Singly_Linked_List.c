#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head, *newnode, *temp;

void beginsert();
void endinsert();
void insert();
void begindelete();
void endelete();
void delete();
void display();
int  count();
//void reverse();
struct node* reverse(struct node*);
void printMiddleElement();
void largest_element();
bool search(struct node*, int);
void remove_duplicates();
void swap_nodes(int , int);

void main()
{
    int choice = 0, contin;
    head = 0;
    do{
    newnode = malloc(sizeof(struct node));   
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if(head == 0){
     head = temp = newnode;
    }
    else{
     temp->next = newnode;
     temp = newnode;
    }
    printf("Do u wish to continue?\n");
    scanf("%d", &contin);
    }while(contin);

    //printMiddleElement();
    //largest_element();
    //if(search(head, 40)) printf("Yes\n");

    while(choice!=7){        
    printf("Enter operation:\n 1. Insert\n 2. Delete\n 3. Display the list\n 4. Length of the list\n 5. Remove duplicates in the List\n 6. Reverse the List\n");
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
              printf("Number of elements in the list is %d\n", count(head));
              break;
            case 5:
              remove_duplicates();
              //swap_nodes(20, 40);
              break;
            case 6:
              head = reverse(head);
              break;
            case 7:
                exit(0);
                break;
            default:
              printf("\nPlease enter valid choice..\n\n");
        }
    }
}

void beginsert()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void endinsert()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    if(head == NULL){
        newnode->next = NULL;
        head = newnode;
    }
    else{
       temp = head;
       while(temp->next != NULL){
           temp = temp->next;
       }
       temp->next = newnode;
       newnode->next = NULL;
    }
}

void insert()
{
    int ind, i=1, n;
    n = count(head);
    printf("Enter the position: ");
    scanf("%d", &ind);
    if(ind<1 || ind>n+1){
        printf("Invalid position\n");
    }
    else if(ind == 1){
        beginsert();
    }
    else if(ind == n+1){
        endinsert();
    }
    else{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        temp = head;
        while(i<ind-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void largest_element()
{
    int max = head->data;
    temp = head;
    while(temp != NULL){
        
        if(temp->data > max) max = temp->data;
        temp = temp->next;
    }
    printf("%d is the largest element\n", max);
}

void display()
{
    temp = head;
    while(temp){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int count(struct node* head)
{
    if(head == NULL) 
        return 0;

    else
        return 1 + count(head->next);
}

void begindelete()
{
    temp = head;
    if(head == 0){
        printf("The list is empty\n");
    }
    else{
        head = head->next;
        free(temp);
    }
}

void endelete()
{
    struct node *prevnode;
    temp = head;
    if(temp == 0){
        printf("The list is empty\n");
    }
    else{
    while(temp->next != NULL){
        prevnode = temp;
        temp = temp->next;
    }    
    if(temp == head){
        head = 0;
    }
    else{
        prevnode->next = NULL;
    }
    free(temp);
    }
}

void delete()
{
    struct node *nextnode;
    int pos, i=1, m = count(head);
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    if(pos>m) printf("Invalid position\n");
    else if(pos == 1) begindelete();
    else if(pos == m) endelete();
    else{
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = temp->next->next;
        free(nextnode);
    }
}

/*void reverse()
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode!= NULL){
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}*/

struct node* reverse(struct node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

void printMiddleElement()
{
    struct node *slow_p = head, *fast_p = head;
    if(head != NULL){
        while(fast_p != NULL && fast_p->next != NULL){
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
        }
        printf("%d is the middle element\n", slow_p->data);
    }
}

bool search(struct node* head, int x)
{
    if(head == NULL) return false;

    if(head->data == x) return true;

    return search(head->next, x);
}

void remove_duplicates()
{
    struct node *curr = head, *temp = NULL, *index = NULL;

    if(curr == NULL) return;

    else{
        while(curr != NULL){
            temp = curr;             //temp will point to previous node to index. 
            index = curr->next;      //Index will point to node next to current
            while(index != NULL){
                if(index->data == curr->data)            
                    //Here, index node is pointing to the node which is duplicate of current node  
                    //Skips the duplicate node by pointing to next node
                    temp->next = index->next;

                else 
                    //Temp will point to previous node of index. 
                    temp = index;

                index = index->next;
            }
            curr = curr->next;
        }
    }
}

void swap_nodes(int x, int y)
{
    if(x == y)
        return;

    struct node *prevX = NULL, *currX = head;
    while(currX && currX->data != x){
        prevX = currX;
        currX = currX->next;
    }

    struct node *prevY = NULL, *currY = head;
    while(currY && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if(prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    if(prevY != NULL)
        prevY->next = currX;
    else   
        head = currX;

    struct node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;    
}