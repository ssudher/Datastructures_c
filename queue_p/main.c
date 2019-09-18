/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 17 May, 2019, 9:18 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct queue{
    int prio;
    struct queue* next;
}q;

q *front;
q *rear;

void queue(int p, q **f, q **r)
{
    q *newq;
    newq = (q*)malloc(sizeof(q));
    newq->prio = p;
    newq->next = NULL;
    printf("\nThis is the new elem: %p, priority: %d\n",newq,newq->prio);
    
    if(*f == NULL)
    {
        *f = newq;
        *r = newq;
    }
    else
    {
        if((*r)->prio >= p)
        {
           (*r)->next = newq;
           *r = newq;
           printf("The rear is moved to: %p, prio: %d",*r,(*r)->prio);
        }
        else if((*f)->prio < p)
        {
            q *t;
            t = *f;
            *f = newq;
            newq->next = t;
            printf("The front is moved to: %p, prio: %d",*f,(*f)->prio);
        }
        else
        {
            q *curr;
            q *temp;
            curr = *f;

            while(curr!= NULL || curr!=*r)
            {
                if((curr->next)->prio>=p)
                {
                    curr = curr->next;    
                }
                else
                {
                    break;
                }
            }
            temp = curr->next;
            curr->next = newq;
            newq->next = temp;
        }
    }
    
}

void dequeue(q **f, q **r)
{
    q *temp;
    temp = *f;
    *f = (*f)->next;
    
    printf("The element at the front is: %p with priority: %d\n",temp,temp->prio);
}

void view(q **f, q **r)
{
    q *temp;
    temp = *f;
    if(*f == NULL)
    {
        printf("The queue is empty!\n");
    }
    else
    {
        printf("\nPrinting the queue....front: %p, rear: %p\n\n",*f,*r);
        printf("Element: %p, priority: %d\n",temp, temp->prio);
        while(temp!=*r)
        {
            temp = temp->next;
            printf("Element: %p, priority: %d\n",temp, temp->prio);
        }
    }
}

int main(int argc, char** argv) 
{
    front = NULL;
    rear = NULL;
    int priority, opt, flag = 1;
    while(flag != 0)
    {
        printf("\n-----------\n 1.Queue\n 2.Dequeue\n 3.view\n -1.exit\n\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("\nEnter the priority of the new element you wish to queue:");
                scanf("%d",&priority);
                queue(priority, &front, &rear);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                view(&front, &rear);
                break;
            case -1:
                flag = 0;
                break;
        }
    }
    return 0;
}