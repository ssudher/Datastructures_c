/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>

double pow1(double base, int rad)
{
    int i;
    double power = 1;
    if(rad < 0)
    {
        rad = -1*rad;
        for(i=0; i<rad; i++)
        {
            power = base*power;
        }
        power = 1/power;
    }
    else
    {
        for(i=0; i<rad; i++)
        {
            power = base*power;
        }
    }
    return power;
}

double log1(double x)
{
    int i;
    double sum = 0;
    double power;
    for(i=1;i<20;i++)
    {
        power = pow1(-1,(i+1));
        sum = sum + (power)*(pow1((x-1),i)/i);
    }
    return sum;
}

double expdev(double lambda)
{
    double dummy;
    do
    {
        dummy = (double) rand() / RAND_MAX;
    }
    while(dummy == 0.0);
    return (-log1(dummy)/lambda);
}