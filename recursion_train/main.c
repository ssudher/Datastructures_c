/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 21 May, 2019, 9:15 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
print_num(n+1);
printf("%d,",n);
print_num(n+1);

n=1

r(2) p(1) r(2)
r(3) p(2) r(3) p(1) r(3) p(2) r(3)
r(4) p(3) r(4) p(2) r(4) p(3) r(4) p(1) r(4) p(3) r(4) p(2) r(4) p(3) r(4)
p(4) p(3) p(4) p(2) p(4) p(3) p(4) p(1) p(4) p(3) p(4) p(2) p(4) p(3) p(4)
 * 
 */

void print_num(int n)
{
    if(n == 4)
    {
        printf("%d,",n);
        return;
    }
    print_num(n+1);
    printf("%d,",n);
    print_num(n+1);
}

int exp(int x, int y)
{
    if(y == 1)
    {
        return x;
    }
    return(x*exp(x,y-1));
}

int main(int argc, char** argv) {
    
    int ex;
    //print_num(1);
    
    ex = exp(5,4);
    printf("\n%d",ex);
    
    printf("\n");
    return 0;
}

