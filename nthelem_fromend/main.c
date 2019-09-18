/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 17 May, 2019, 10:31 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct ll{
    int val;
    struct ll *next;
};

struct ll *head;

void add(int p)
{
    
    struct ll *new;
    new = (struct ll*)malloc(sizeof(struct ll));
    new->val = p;
    new->next = NULL;
    if (head == NULL)
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

void view()
{
    if(head == NULL)
    {
        printf("The LL is empty!\n");
    }
    else
    {
        struct ll *temp;
        temp = head;
        printf("\nThe nodes are... with head: %p\n",head);
        while(temp!=NULL)
        {
            printf("node: %p, val: %d, next: %p\n",temp,temp->val,temp->next);
            temp = temp->next;
        }
    }
}

void find_n(int n)
{
    struct ll *ref;
    struct ll *finder;
    ref = head;
    finder = head;
    for(int i=0; i<n; i++)
    {
        if(ref==NULL)
        {
            printf("\nThe nth element you wanted to find is out of bounds!!\n");
            exit(0);
        }
        ref = ref->next;
    }

    while(ref->next!= NULL)
    {
        ref = ref->next;
        finder = finder->next;
    }
    printf("\n==================\n");
    printf("The nth node is at : %p, val: %d\n\n",finder,finder->val);
}

int main(int argc, char** argv) {
    
    head = NULL;
    int elems[10] = {10,29,100,324,54,27,82,18,83,852};
    for(int i=0; i<10; i++)
    {
        add(elems[i]);
    }
    view();
    int n;
    printf("\n\nEnter the nth element from the last you wish to find: ");
    scanf("%d",&n);
    find_n(n);
    return 0;
}

