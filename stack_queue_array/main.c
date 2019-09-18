/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 1 June, 2019, 5:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
int top = -1;

void push(int n, int arr[])
{
    if(top == -1)
    {
        top = 0;
        arr[0] = n;
    }
    else
    {
        top++;
        arr[top] = n;
    }
}

int pop(int arr[])
{
    if(top == -1)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    int temp;
    temp = arr[top];
    top--;
    return temp;
}

void view(int arr[])
{
    int t;
    t = top;
    while(t!=-1)
    {
        printf("%d, ",arr[t]);
        t--;
    }
}

int peek(int arr[])
{
    if(top == -1)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    else
    {
        return arr[top];
    }
}

int main(int argc, char** argv) {
    
    int arr[100];
    int pop_elem,num;
    int flag = 1,opt;
    
    
    while(flag)
    {
        printf("\n---------------\n 1.Push elements"
        "\n 2.Peek the top element"
        "\n 3.Pop the Stack"
        "\n 4.view the Stack"
        "\n -1.to exit!\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("Enter elements, enter -1 to stop\n");
                while(num!=-1)
                {
                    scanf("%d",&num);
                    if(num!=-1)
                    {
                        push(num, arr);
                    }
                }
                break;
            case 2:
                pop_elem = peek(arr);
                printf("\nThe top element is: %d\n",pop_elem);
                break;
            case 3:
                pop_elem = pop(arr);
                printf("\nThe top element was: %d\n",pop_elem);
                break;
            case 4:
                view(arr);
                break;
            case -1:
                flag = 0;
                break;
            default:
                printf("\nEnter a valid input...\n");
                break;
        }
    }
    return (EXIT_SUCCESS);
}

