/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 12 September, 2019, 5:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * 
 */
extern double pow1(double, int);
extern double log1(double);
extern double expdev(double);
int main(int argc, char** argv) {
    double power;
    double value;
    double x = -0.4;
    double rad = 2;
    double expdevvv;
    
    power = pow1(x,rad);
    value = log1(0.6);
    expdevvv = expdev(0.1);
    
    printf("%f %f %f\n", expdev(0.1), expdev(0.1), expdev(0.1));
    return (EXIT_SUCCESS);
}

