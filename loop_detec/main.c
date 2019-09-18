/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 17 May, 2019, 11:12 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

struct ll{
    int data;
    struct ll* next;
}*head;

void add(int val)
{
    struct ll *new;
    new = (struct ll*)malloc(sizeof(struct ll));
    new->data = val;
    new->next = NULL;
    
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        struct ll *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void loop(int n)
{
    struct ll *t1, *t2;
    t1 = head;
    t2 = head;
    int count = 1;
    
    while(t2->next!=NULL)
    {
        if(count<n)
        {
            t1 = t1->next;
        }
        t2 = t2->next;
        count++;
    }
    t2->next = t1;
}

void view()
{
    struct ll *temp;
    temp = head;
    printf("\n=====================\nPrinting the LL...\n");
    for(int i=0; i<14; i++)
    {
        printf("The node is: %p, val: %d, next_node: %p, next_val: %d\n",temp,temp->data,(temp->next),(temp->next)->data);
        if((temp->next)->next == NULL)
        {
            temp = temp->next;
            printf("The node is: %p, val: %d, next_node: %p\n",temp,temp->data,(temp->next));
            break;
        }
        temp = temp->next;
    }
    
}

void detect_loop()
{
    struct ll *slow, *fast;
    slow = head;
    fast = head;
    int flag = 0;
    
    if(head == NULL)
    {
        printf("The LL is empty!\n");
        exit(0);
    }
    if(head->next == NULL)
    {
        printf("The LL has just 1 element!\n");
        exit(0);
    }
    while(fast->next!=NULL && fast!=NULL)
    {
        slow = slow->next;
        fast = (fast->next)->next;
        if(slow == fast)
        {
            flag = 1;
            break;
        }
        if(fast == NULL)
        {
            break;
        }
    }
    
    if(flag == 0)
    {
        printf("\n..........There was no loop detected!.........\n");
    }
    else if(flag == 1)
    {
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        printf("\n..........The loop is detected at : %p->%d.........\n",fast,fast->data);
    }
}

int main(int argc, char** argv) {
    
    head = NULL;
    int arr[15] = {1,12,15,3,6,87,124,902,85,145,563,256,71139,50};
    int index;
    for(int i=0; i<14; i++)
    {
        add(arr[i]);
    }
    printf("\nEnter which element you want to loop at:");
    scanf("%d",&index);
    if(index != -1)
    {
        loop(index);
    }
    view();
    detect_loop();
    return 0;
}

