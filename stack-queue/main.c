/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 10 May, 2019, 10:58 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/*
 * 
 */
int arr[MAX];
int top = -1;

void push(int elem)
{
    top++;
    if(top == 9)
    {
        printf("The stack is FULL!\n\n");
    }
    else
    {
        arr[top] = elem;
    }
}

int pop()
{
    int top_elem = 0;
    if(top == -1)
    {
        printf("The stack is empty!\n\n");
    }
    else
    {
        top_elem = arr[top];
        arr[top] = 0;
        top--;
    }
     return top_elem;
}

int peek()
{
    return(arr[top]);
}

int display_stack()
{
    
    printf("Printing the stack elements...top is %d\n",top);
    
    for(int i=0; i<10; i++)
    {
        printf("%d,",arr[i]);
    }
}

int main(int argc, char** argv) {
    
    int n = 10;
    int elem,opt,flag = 1;
    int ret;
    
    while(flag != 0)
    {
        printf("\n-----------------------------\n "
                "1.PUSH\n "
                "2.PEEK\n "
                "3.POP\n "
                "4.Show Stack\n "
                "-1.exit\n ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("Enter new elements to the stack..\n");
                scanf("%d",&elem);
                push(elem);
                break;
            case 2:
                ret = peek();
                printf("The top element is: %d\n",ret);
                break;
            case 3:
                ret = pop();
                printf("The top element is: %d\n",ret);
                break;
            case 4:
                display_stack();
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

