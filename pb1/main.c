/*
 Given an array arr[] of size N. The task is to create linked list from the given array.
 
 Geeks for Geeks
 URL: https://www.geeksforgeeks.org/create-linked-list-from-a-given-array/

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll* next;
}ll;

ll *head;

ll* create_new(int d)
{
    ll *newnode;
    newnode = (ll*)malloc(sizeof(ll));
    newnode->data = d;
    newnode->next = NULL;
    return newnode;
}

void insert(int d)
{
    ll *newnode = create_new(d);
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        ll *t;
        t = head;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = newnode;
    }
}

void display()
{
    ll *temp;
    temp = head;
    printf("\n-----Printing the linked list!----------\n");
    while(temp != NULL)
    {
        printf("Node: %p->%d\n", temp, temp->data);
        temp = temp->next;
    }
}

int main(int argc, char** argv) {
    
    int arr[100], size;
    printf("Enter the size of the array!\n");
    scanf("%d",&size);
    printf("Enter the elements of the array\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    head = NULL;
    for(int i=0; i<size; i++)
    {
        insert(arr[i]);
    }
    display();
    return (EXIT_SUCCESS);
}

