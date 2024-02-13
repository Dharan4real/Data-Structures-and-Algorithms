#include<stdio.h>

#define N 100
int s1[N], s2[N], count =0, top1 = -1, top2 = -1;

void push1(int data)
{
    s1[++top1] = data;
}

void push2(int data)
{
    s2[++top2] = data;
}

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

void enqueue(int data)
{
    push1(data);
    count++;
}

void dequeue()
{
    int i, a;
    for(i=0; i<count; i++){
        push2(pop1());
    }
    a = pop2();
    printf("%d is dequeued\n", a);
    count--;
    for(i=0; i<count; i++){
        push1(pop2());
    }
}

void display()
{
    int i;
    for(i=0; i<=top1; i++){
        printf("%d\t", s1[i]);
    }
    printf("\n");
}

void main()
{
    enqueue(20);
    enqueue(40);
    enqueue(60);
    enqueue(80);
    display();
    dequeue();
    dequeue();
    display();
}