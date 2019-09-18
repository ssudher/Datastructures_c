/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 10 May, 2019, 12:28 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int arr[50];
int front = -1;
int rear = -1;

void queue(int elem)
{
    if(rear == 9)
    {
        printf("The queue is Full!\n");
    }
    else
    {
        if(front == -1)
        {front = 0;}
        rear++;
        arr[rear] = elem;
    }
}

int dequeue()
{
    if(front == -1 || front>rear)
    {
        printf("The queue is empty!");
        return 0;
    }
    else
    {
        int front_elem;
        front_elem = arr[front];
        front++;
        return front_elem;
    }
}

void display_q()
{
    printf("Printing the queue elements!...front: %d, rear: %d\n",front,rear);
    for(int i=front; i<=rear; i++)
    {
        printf("%d,",arr[i]);
    }
}

int main(int argc, char** argv) {
    
    int elem,opt,flag = 1;
    int ret;
    
    while(flag != 0)
    {
        printf("\n-----------------------------\n "
                "1.QUEUE\n "
                "2.DEQUEUE\n "
                "3.Show queue\n "
                "-1.exit\n ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("Enter new elements to the stack..\n");
                scanf("%d",&elem);
                queue(elem);
                break;
            case 2:
                ret = dequeue();
                printf("The top element is: %d\n",ret);
                break;
            case 3:
                display_q();
                break;
            case -1:
                flag = 0;
                break;
            default:
                printf("Enter a valid entry.\n");
                break;
        }
    }
    
    
}
