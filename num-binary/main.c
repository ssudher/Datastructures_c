/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 14 May, 2019, 9:30 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct stack
{
    int bit;
    struct stack* next;
}stack;

stack *top;

void push(int n)
{
    stack* new;
    new = (stack*)malloc(sizeof(stack));
    new->bit = n;
    new->next = NULL;
    if(top == NULL)
    {
        top = new;
    }
    else
    {
        new->next = top;
        top = new;
    }
}

int pop()
{
    stack* t;
    if(top == NULL)
    {
        printf("The stack is empty!\n");
    }
    else
    {
        t = top;
        top = top->next;
        return (t->bit);
    }
    return 0;
}

void convert(int num)
{
    int div,rem;
    div = num;
    while(div!=0)
    {
        rem = div%2;
        push(rem);
        div = div/2;
    }
}

int main(int argc, char** argv) {

    top = NULL;
    int num;
    
    printf("Enter the number you wish to convert.\n");
    scanf("%d",&num);
    convert(num);
    
    stack* t;
    t = top;
    int n;
    printf("The binary equivalence of %d is: ",num);
    while(t!=NULL)
    {
        n = pop();
        printf("%d",n);
        t=t->next;
    }
    printf("\n");
    return 0;
}

