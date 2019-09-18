/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 13 May, 2019, 9:27 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef struct node{
    int data;
    struct node *next;
}node;

node *front;
node *rear;


void add_node(int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    if(front == NULL)
    {
        front = new_node;
        new_node->next = front;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        new_node->next = front;
        rear = new_node;
    }
}

node* rem_node()
{
    node* curr = front;
    if(front == NULL)
    {
        printf("The circular LL is empty!\n");
    }
    else if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    return curr;
}

void print_ll()
{
    node *curr;
    curr = front;
    if(front == NULL)
    {
        printf("The circular LL is empty! front: %p, rear = %p\n",front,rear);
    }
    /*
    else if(front == rear)
    {
        printf("\n--------front: %p, rear = %p---------\n",front,rear);
        printf("\nnode: %p, data: %d, next: %p\n",curr,curr->data,curr->next);
    }
    else
    {
        printf("\n--------front: %p, rear = %p---------\n",front,rear);
        while(curr!=rear)
        {
            printf("\nnode: %p, data: %d, next: %p\n",curr,curr->data,curr->next);
            curr = curr->next;
        }
        printf("\nnode: %p, data: %d, next: %p\n",rear,rear->data,rear->next);
    }
     */
    else
    {
        printf("\n--------front: %p, rear = %p---------\n",front,rear);
        do
        {
            printf("\nnode: %p, data: %d, next: %p\n",curr,curr->data,curr->next);
            curr = curr->next;
        }while(curr!=front);
    }
}

int main(int argc, char** argv) {

    front = NULL;
    rear = NULL;
    int opt,elem;
    int flag = 1;
    node *curr;
    while(flag != 0)
    {
        printf("\n----------------\n");
        printf(" 1.add element\n 2.delete element\n 3.print circular LL\n -1.exit\n");
        scanf("%d",&opt);
        
        switch(opt)
        {
            case 1:
                printf("\nEnter the element you want to add: ");
                scanf("%d",&elem);
                add_node(elem);
                break;
            case 2:
                curr = rem_node();
                printf("\nThe element at the head was:\n node: %p, data: %d\n",curr,curr->data);
                free(curr);
                break;
            case 3:
                print_ll();
                break;
            case -1:
                flag = 0;
                break;
            default:
                printf("\nEnter a valid selection!.\n");
                break;
        }
    }
    return 0;
}

