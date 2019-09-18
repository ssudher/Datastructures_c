/*
Replace even nodes of a doubly linked list with the elements of an array
 * Geeks for geeks URL: https://www.geeksforgeeks.org/replace-even-nodes-of-a-doubly-linked-list-with-the-elements-of-array/
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 18 June, 2019, 7:07 PM
 */

#include <stdio.h>
#include <stdlib.h>

struct double_ll{
    int data;
    struct double_ll *prev, *next;
};

struct double_ll *head;

struct double_ll *create_newnode(int d)
{
    struct double_ll *new;
    new = (struct double_ll*)malloc(sizeof(struct double_ll));
    new->data = d;
    new->next = NULL;
    new->prev = NULL;
    
    return new;
}

void push(int data)
{
    struct double_ll *new = create_newnode(data);
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        struct double_ll *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void display()
{
    struct double_ll *t;
    t = head;
    while(t!=NULL)
    {
        printf("prev:%p,curr:%p->%d,next:%p\n",t->prev,t,t->data,t->next);
        t = t->next;
    }
}

void swapodds(int a[])
{
    struct double_ll *t;
    int c = 0;
    t = head;
    while(t!=NULL)
    {
        if(t->data%2 == 0)
        {
            t->data = a[c];
        }
        t = t->next;
        c++;
    }
}

int main(int argc, char** argv) {
    head = NULL;
    
    int arr[] = {3,7,19,247,1};
    push(2);
    push(21);
    push(23);
    push(244);
    push(12);
    printf("\n---Before Swap---\n");
    display();
    swapodds(arr);
    printf("\n---After Swap---\n");
    display();
    return (EXIT_SUCCESS);
}

