/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 8 May, 2019, 10:09 AM
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *next;
}*head;
    
/*
 * 
 */

void add_node_end(int value)
{
    struct node* p;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = value;
    temp -> next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void add_inmid(int value, int loc)
{
    int flag = 0;
    struct node* p;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        for(int i=0;i<loc-1;i++)
        {
            //reached the end before the location is reached.
            if(p->next == NULL)
            {
                printf("The location is out of bound.!");
                flag = 1;
                break;
            }
            p = p->next;
        }
        
        if(flag != 1)
        {
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void add_head(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    
    temp->next = head;
    head = temp;
}


void delete_node_loc(int loc)
{
    struct node* p;
    struct node* q;
    p = head;
    int flag = 1;
    if(loc == 0)
    {
        head = p->next;
        p->next = NULL;
    }
    else
    {
        for(int i=0; i<loc-1; i++)
        {
            if(p->next == NULL)
            {
                printf("the requested location is out of bounds!\n");
                flag = 0;
                break;
            }
            p = p->next;
        }
        if(flag!= 0)
        {
            q = (p->next);
            (p->next) = (p->next)->next;
            free(q);
        }
    }
}
    
void delete_node_value(int val)
{   
    int flag = 0;
    struct node* t;
    struct node* q;
    t = head;
    int count = 0;
    if(t->data == val)
    {
        flag = 1;
    }
    while(t->next != NULL && flag!=1)
    {
        if((t->next)->data == val)
        {
            flag = 1;
            break;
        }
        t = t->next;
        count++;
    }
    
    if(t == head && t->data == val)
    {
        flag = 1;
    }
    
    if(flag == 1)
    {
        if(count == 0)
        {
            if(head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                t->next = (t->next)->next;    
            }
        }
        else
        {
            printf("The data has been found at index: %d\n",count);
            q = (t->next);
            (t->next) = (t->next)->next;
            free(q);
        }
    }
    else
    {
        printf("The data you entered was not found in the LL!\n");
    }
}

void display_ll()
{
    printf("\n---------------------------\nprinting the linked list...\n");
    struct node* t;
    t = head;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    printf("\n--------------------\n");
}

void reverse1()
{
    struct node* t;
    t = head;
    
    while(t != NULL)
    {
        add_head(t->data);
        t = t->next;
    }
}

void reverse()
{
    struct node* curr;
    struct node* prev;
    if(head->next != NULL)
    {
        prev = NULL;
        curr = head;
        head = head->next;
        curr->next = prev;

        prev = curr;
        curr = head;
        head = head->next;
        while(head != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = head;
            head = head->next;
        }
        curr->next = prev;
        head = curr;
    }    
}


void find_mid()
{
    struct node *p1, *p2;
    p1 = head;
    p2 = head;
    while(p1!= NULL)
    {
        if(p1->next == NULL)
        {
            break;
        }
        p1 = (p1->next)->next;
        p2 = p2->next;
    }
    printf("The middle value is: %d\n",p2->data);
}


int main(int argc, char** argv) {    
    
    head = NULL;
    int value,index,opt,loc;
    int flag = 1;
    
    while(flag!=0)
    {
        printf("What do you want to do?\n 1.Add at the end\n 2.Add at the start\n 3.add in the middle\n 4.Delete by location\n 5.Delete by value\n 6.Display linked-list\n 7.reverse\n 8.Find the middle element\n -1.exit!\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("Enter the new node's data\n");
                scanf("%d",&value);
                add_node_end(value);
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
            case 8:
                find_mid();
                break;
            case -1:
                flag = 0;
                break;
            default:
                printf("Enter a valid entry!\n");
                break;
        }
            
    }
    
    /*
    while(value != -1)
    {
        printf("Enter the new node's data, to stop enter -1\n");
        scanf("%d",&value);
        add_node_end(value);
    }
    printf("printing the linked list...\n");
    struct node* t;
    t = head;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    
    int index;
    printf("Add a value to node in the middle and enter the location(Index starts from 0)\n");
    scanf("%d%d",&value,&index);
    add_inmid(value,index);
    
    
    printf("-----------------------\nprinting the linked list...\n");
    t = head;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    
    printf("Enter a new value for the head\n");
    scanf("%d",&value);
    add_head(value);

    printf("-----------------------\nprinting the linked list...\n");
    t = head;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    
    printf("Delete a node?\n 1.Delete a node by location\n 2.Delete a node by value.\n");
    int opt,loc;
    scanf("%d",&opt);
    if(opt == 1)
    {
        printf("Enter the location: ");
        scanf("%d",&loc);
        delete_node_loc(loc);    
    }
    else if(opt == 2)
    {
        printf("Enter the value you want to delete!\n");
        scanf("%d",&value);
        delete_node_value(value);
    }
    printf("\n-----------------------\nprinting the linked list...\n");
    t = head;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    */
    return 0;
}

