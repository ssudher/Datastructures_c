/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 7 May, 2019, 4:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "linear.h"
#include "binary.h"

double total_time;
clock_t start,end;

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[100000], to_find;
    for(int i=0; i<9999; i++)
    {
        arr[i] = (i*3)+2;
    }
    printf("The actual array is: \n");
    for(int i=0; i<9999; i++)
    {
        printf("%d,",arr[i]);
    }
    
    printf("Please enter the number you wish to search: ");
    scanf("%d",&to_find);
    
    printf("\n\nEnter the method to be used:\n 1.Linear search\n 2.Binary search\n\n>>");
    int option, index;
    
    //starting the clock
    scanf("%d",&option);
    start = clock();
    if(option == 1)
    {index = linear_s(to_find, arr);}
    else if(option == 2)
    {index = binary_s(to_find, arr);}
    else
    {printf("The selected option is incorrect!\n");}
    
    //stopping the clock
    end = clock();
    
    if(index == -1)
    {
        printf("The entered element was not found!\n");
        printf("The total time taken is : %f\n\n", (double)(end - start));
    }
    else
    {
        printf("The element was found at: %d -> %d\n",index,arr[index]);
        printf("The total time taken is : %f\n\n", (double)(end - start));
    }
    return 0;
}