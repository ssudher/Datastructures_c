/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 8 May, 2019, 11:54 AM
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int data;
    struct node* next;
}node;

node* head;
/*
 * 
 */

void add_nodeend(int value)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    
    if(head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        node* p;
        p = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
    }
    
}

node* search_ll(int value)
{
    node* result = NULL; 
    int index = 0;
    node* t = head;
    while(t->next != NULL)
    {
        if(t->data == value)
        {
            printf("\nThe data was found at index: %d\n",index);
            result = t;
            break;
        }
        index++;
        t = t->next;
    }
    return result;
}

int main(int argc, char** argv) {
    
    head = NULL;
    int data;
    printf("Enter values to be added to the LL, to stop enter -1\n");
    while(data!= -1)
    {
        scanf("%d",&data);
        add_nodeend(data);
    }
    
    printf("Printing the linked list...\n");
    node* t;
    t = head;
    while(t->next != NULL)
    {
        printf("The node is : %p, the data is: %d\n",t,t->data);
        t = t->next;
    }
    
    int to_search;
    printf("\nEnter the data to be searched for..");
    scanf("%d",&to_search);
    node* res = search_ll(to_search);
    if(res == NULL)
    {
        printf("\nThe data was not found in LL!\n");
    }
    else
    {
        printf("The data was found at: %p and the data is: %d\n" ,res,res->data);
    }
    return 0;
}

