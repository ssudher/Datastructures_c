/*
 * File:   main.c
 * Author: shrik
 *
 * Created on 13 May, 2019, 11:22 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*
 * 
 */

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct stack
{
    struct node *elem;
    struct stack *next;
}stack;

node *head1;
node *head2;

void push(node *e, node **top1)
{
    stack *new;
    new = (stack*)malloc(sizeof(stack));
    new->elem = e;
    new->next = NULL;
    if(*top1 == NULL)
    {
        *top1 = new;
    }
    else
    {
        new->next = *top1;
        *top1 = new;
    }
}

stack* pop(stack **top)
{
    stack *temp = *top;
    *top = (*top)->next;
    return temp;
}

void print_stack(stack **top)
{
    if(*top == NULL)
    {
        printf("\nThe stack is empty!\n");
    }
    else
    {
        stack *t;
        t = *top;
        printf("\n---------\nPrinting the stack with top: %p\n",top);
        while(t!=NULL)
        {
            printf("Node: %p, data: %p, next; %p\n",t,t->elem,t->next);
            t = t->next;
        }
    }
}

void add_elem(int val, node **h)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    
    if(*h == NULL)
    {
        newnode->next = NULL;
        *h = newnode;
    }
    else
    {
        node *curr;
        curr = *h;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newnode;
        newnode->next = NULL;
    }
}

void add_elem_both(int val)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    
    node *curr;
    curr = head1;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
    
    
    node *curr2 = head2;
    while(curr2->next != NULL)
    {
        curr2 = curr2->next;
    }
    curr2->next = newnode;
}

void print_ll(node **h)
{
    node *curr;
    curr = *h;
    
    if(*h == NULL)
    {
        printf("\nThe LL is empty!\n");
    }
    else
    {
        printf("\nThe elements of the LL %p are...\n",curr);
        while(curr!=NULL)
        {
            printf("node: %p, data: %d, next: %p\n",curr,curr->data,curr->next);
            curr = curr->next;
        }
    }
}

void reverse(node **head, stack **top)
{
    if(*head == NULL)
    {
        printf("The LL is empty!\n");
    }
    else
    {
        node *temp;
        temp = *head;
        while(temp!=NULL)
        {
            push(temp, top);
            temp = temp->next;
        }
    }
}

void intersection(stack** t1, stack** t2)
{   
    node* inter;
    
    if(*t1==NULL || *t2==NULL)
    {
        printf("\nThe stack is empty!check...\n");
    }
    else
    {
        while(*t1!=NULL && *t2!=NULL)
        {
            if((*t1)->elem == (*t2)->elem)
            {
                inter = (*t1)->elem;
                pop(t1);
                pop(t2);
            }
            else
            {
                break;    
            }
        }
    }
    printf("\n==========\nThe intersection point is:\n node: %p, data: %d\n\n",inter,inter->data);
}

int main(int argc, char** argv) {
    
    head1 = NULL;
    head2 = NULL;
    add_elem(1,&head1);
    add_elem(2,&head1);
    add_elem(3,&head1);
    add_elem(4,&head1);
    add_elem(5,&head1);
    add_elem(6,&head1);
    add_elem(21,&head1);
    add_elem(12,&head1);
    add_elem(25,&head1);
    add_elem(67,&head1);
    
    add_elem(11,&head2);
    add_elem(12,&head2);
    add_elem(13,&head2);
    
    add_elem_both(234);
    add_elem(42,&head2);
    add_elem(43,&head2);
    add_elem(44,&head2);
    add_elem(45,&head2);
    
    print_ll(&head1);
    print_ll(&head2);
    
    printf("\n----------------------\n");
    stack *top1, *top2;
    top1 = NULL;
    top2 = NULL;
    reverse(&head1,&top1);
    reverse(&head2,&top2);
    print_stack(&top1);
    print_stack(&top2);
    intersection(&top1,&top2);
    return 0;
}

