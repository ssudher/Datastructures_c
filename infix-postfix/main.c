/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 14 May, 2019, 9:48 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define SIZE 100
/*
 * 
 */

typedef struct stack{
    char o;
    struct stack *next;
}stack;

void push(char c, stack **t)
{
    stack* new;
    new = (stack*)malloc(sizeof(stack));
    new->o = c;
    new->next = NULL;
    if(*t == NULL)
    {
        *t = new;
    }
    else
    {
        new->next = *t;
        *t = new;
    }
}

char pop(stack **t)
{
    stack *c;
    if(*t == NULL)
    {
        //printf("\nThe stack is empty\n");
        return '\0';
    }
    else
    {
        c = *t;
        *t = (*t)->next;
    }
    return (c->o);
}

char peek(stack **t)
{
    char ret;
    ret = '0';
    if(*t == NULL)
    {
        //printf("The stack is empty!\n");
    }
    else
    {
        ret = (*t)->o;
    }
    return ret;
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[], stack **t)
{ 
    int i, j;
    char item;
    char x;

    i=0;
    j=0;
    item=infix_exp[i];

    while(item != '\0')
    {
        if(item == '(')
        {
            push(item,t);
        }
        else if( isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            x=peek(t);
            while(is_operator(x) == 1 && precedence(x)>= precedence(item))
            {
                x = pop(t);
                postfix_exp[j] = x;
                j++;
                x = peek(t);
            }
            push(item,t);
        }
        else if(item == ')')
        {
            x = pop(t);
            while(x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop(t);
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    if(*t!=NULL)
    {
        while(*t != NULL)
        {
            x = pop(t);
            postfix_exp[j] = x;
            j++;
        }
    }
    postfix_exp[j] = '\0';
}


void reverse_replace(char infix_exp[], char reverse[])
{
    int k,l;
    for (k = strlen(infix_exp) - 1, l= 0; k >= 0; k--, l++)
    {
        reverse[l] = infix_exp[k];
    }
    
    for(int i=0; i<strlen(reverse); i++)
    {
        if(reverse[i] == '(')
        {
            reverse[i] =  ')';
        }
        else if(reverse[i] == ')')
        {
            reverse[i] = '(';
        }
    }
       
    reverse[l] = '\0';
}

int operate(char first, char sec, char opr)
{
    int f,s;
    f = first - '0';
    s = sec - '0';
    
    switch(opr)
    {
        case '+':
            return(f+s);
        case '-':
            return(f-s);
        case '*':
            return(f*s);
        case '/':
            return(f/s);
    }
}

void evaluate(char exp[SIZE], stack **t)
{
    char x,sec,first,push_x;
    int tobe_pushed;
    int i = 0;
    x = exp[i];
    while(x!= '\0')
    {
        if(isdigit(x))
        {
            push(x,t);
        }
        else
        {
            sec = pop(t);
            first = pop(t);
            tobe_pushed = operate(first,sec,x);
            push_x = tobe_pushed + '0';
            push(push_x,t);
        }
        i++;
        x = exp[i];
    }
}

int main()
{
    stack *top;
    stack *top2;
    stack *top3;

    top = NULL;
    top2 = NULL;
    top3 = NULL;
    
    char infix[SIZE], postfix[SIZE], prefix[SIZE], eval[SIZE], reverse[SIZE], pre_temp[SIZE];
    printf("\nEnter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix,postfix,&top);
    printf("\nPostfix Expression: ");
    puts(postfix);
   
    reverse_replace(infix,reverse);
    printf("\nThe reverse is: ");
    puts(reverse);
    
    InfixToPostfix(reverse,pre_temp,&top2);
    reverse_replace(pre_temp,prefix);
    printf("\nPrefix Expression is: ");
    puts(prefix);
    
    
    printf("\nEnter the postfix expression to evaluate..\n");
    gets(eval);
    evaluate(eval,&top3);
    int val;
    val = (top3->o) - '0';
    printf("The result of the evaluation is: %d\n",val);
    printf("\n");
    return 0;
}

