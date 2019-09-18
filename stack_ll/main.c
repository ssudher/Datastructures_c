
/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 13 May, 2019, 5:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef struct node
{
    int data;
    struct node *next;
}node;

node *top;


void push(int val)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    
    if(top == NULL)
    {
        top = newnode;
    }
    else
    {
        node *t;
        t = top;
        top = newnode;
        newnode->next = t;
    }
}


node* pop()
{
    node* newtop;
    if(top == NULL)
    {
        printf("The stack is empty!\n");
    }
    else
    {
        newtop = top;
        top = newtop->next;
    }
    return newtop;
}

void print_ll()
{
    node *n;
    if(top == NULL)
    {
        printf("The stack is empty!\n");
    }
    else
    {
        n = top;
        printf("\n=====\nprinting the stack with top: %p\n",top);
        while(n!=NULL)
        {
            printf("Node: %p, data: %d, next: %p\n",n,n->data,n->next);
            n = n->next;
        }
    }
}

int main(int argc, char** argv) {
    
    top = NULL;
    int flag=1,val,opt;
    node *ret;
    
    while(flag != 0)
    {
        printf("\n-----------------\n 1.PUSH\n 2.POP\n 3.VIEW\n -1.exit\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("\nEnter the value you wish you push into the stack.\n");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                ret = pop();
                printf("\nThe value you popped is; Node: %p, value: %d",ret,ret->data);
                break;
            case 3:
                print_ll();
                break;
            case -1:
                flag = 0;
                break;
        }
    }
    
    
    return 0;
}

