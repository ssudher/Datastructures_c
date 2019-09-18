/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 10 May, 2019, 6:01 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef struct node{
    int data;
    struct node* next;
}node;

node *head1;
node *head2;

node* add_val(int val, node *h)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if(h == NULL)
    {
        h = newnode;
    }
    else
    {
        node *t;
        t =h;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = newnode;
    }
    return h;
}

void display_l(node *h)
{
    node *t;
    t = h;
    printf("\n--------\nThe elements of the LL are...\n");
    while(t!=NULL)
    {
        printf("%d,",t->data);
        t = t->next;
    }
}

int add(node *h1,node *h2)
{
    node *t1,*t2;
    t1 = h1;
    t2 = h2;
    int num1 = 0,num2 = 0,sum = 0;
    int count = 1;
    
    while(t1 != NULL)
    {
        num1 += (t1->data)*(count);
        count*=10;
        t1 = t1->next;
    }
    printf("\nnum1: %d\n",num1);
    
    count = 1;
    while(t2 != NULL)
    {
        num2 += (t2->data)*(count);
        count*=10;
        t2 = t2->next;
    }
    printf("\nnum2: %d\n",num2);
    sum = num1 + num2;
    return sum;
}

int main(int argc, char** argv) {    
    head1 = NULL;
    head2 = NULL;
    int sum;
    
    head1 = add_val(3,head1);
    head1 = add_val(6,head1);
    head1 = add_val(2,head1);
    head1 = add_val(4,head1);
    
    head2 = add_val(1,head2);
    head2 = add_val(4,head2);
    head2 = add_val(7,head2);
    head2 = add_val(9,head2);
    
    display_l(head1);
    display_l(head2);
    
    sum = add(head1,head2);
    printf("The sum is: %d\n",sum);
    printf("\n");
    return 0;
}

