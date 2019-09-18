/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 8 May, 2019, 8:55 PM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* head;
/*
 * 
 */

node* create_newnode(int value)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    return newnode;
}

void display_ll()
{
    printf("\n--------------\nPrinting the Doubly LL...\n");
    node* curr;
    curr = head;
    while(curr!= NULL)
    {
        printf("\nPrev node: %p, curr node: %p, next node: %p, data: %d",curr->prev,curr,curr->next,curr->data);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}

void add_head(int value)
{
    node* newnode = create_newnode(value);
    node* current;
    current = head;
    
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        current->prev = newnode;
        newnode->next = current;
        head = newnode;
    }
    
}

void add_end(int value)
{
    node* newnode = create_newnode(value);
    node* current;
    current = head;
    
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        newnode->prev = current;
        current->next = newnode;
    }
}

void add_inmid(int val, int loc)
{
    node* newnode = create_newnode(val);
    node *before, *after;
    before = head;
    for(int i=0; i<loc-1; i++)
    {
        if(before == NULL)
        {
            printf("The location you entered is out of bounds!\n");
            break;
        }
        before = before->next;
    }
    if(before->next != NULL)
    {
        after = before->next;
        before->next = newnode;
        after->prev = newnode;
        newnode->prev = before;
        newnode->next = after;    
    }
    else
    {
        printf("The location you entered is the end, use option 2 to add elements at the end!\n");
    }
    
}
void delete_node_loc(int loc)
{
    node *before,*curr,*after;
    if(head == NULL)
    {
        printf("The LL is empty!\n");
    }
    else
    {
        //deleting the head location.
        if(loc == 0)
        {
            curr = head;
            //if only one element is left, then else part is executed
            if(curr->next != NULL)
            {
                after = curr->next;
                head = after;
                after->prev = NULL;
                free(curr);
            }
            else
            {
                head = NULL;
                free(curr);
            }
        }
        else
        {
            curr = head;
            for(int i=0; i<loc; i++)
            {
                if(curr == NULL)
                {
                    printf("The location you entered is out of bounds!\n");
                    break;
                }
                curr = curr->next;
            }
            
            //deleting the last location.
            if(curr->next!= NULL)
            {
                before = curr->prev;
                after = curr->next;

                before->next = after;
                after->prev = before;
                curr->prev = NULL;
                curr->next = NULL;
                free(curr);
            }
            else
            {
                before = curr->prev;
                before->next = NULL;
                curr->prev = NULL;
                free(curr);
            }
        }
    }
}

int main(int argc, char** argv) {

    head = NULL;
    int value,index,loc;
    int opt;
    
    while(opt!=-1)
    {
        printf("What do you want to do?\n 1.Add at the end\n 2.Add at the start\n 3.add in the middle\n 4.Delete by location\n 5.Delete by value\n 6.Display linked-list\n 7.reverse\n -1.exit!\n");
        scanf("%d",&opt);
        
        switch(opt)
        {
            case 1:
                printf("Enter the new node's data\n");
                scanf("%d",&value);
                add_end(value);
                break;
            case 2:
                printf("Enter a new value for the head\n");
                scanf("%d",&value);
                add_head(value);
                break;
                
            case 3:
                printf("Add a value to node in the middle and enter the location(Index starts from 0)\n");
                scanf("%d%d",&value,&index);
                add_inmid(value,index);
                break;
                
            case 4:
                printf("Enter the location: ");
                scanf("%d",&loc);
                delete_node_loc(loc); 
                break;
                /*
            case 5:
                printf("Enter the value you want to delete!\n");
                scanf("%d",&value);
                delete_node_value(value);
                break;
            case 6:
                display_ll();
                break;
            case 7:
                reverse1();
                break;
            case -1:
                flag = 0;
                break;
                 */
                case 6:
                display_ll();
                break;
            default:
                printf("Enter a valid entry!\n");
                break;
        }
    }
}

