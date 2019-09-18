/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 20 May, 2019, 9:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void selection_sort(int a[], int n)
{
    int small;
    int temp;
    int swap_j;
    for(int i=0; i<n-1; i++)
    {
        small = a[i];
        swap_j = i;
        for(int j = i; j<n; j++)
        {
            if(a[j] < small)
            {
                small = a[j];
                swap_j = j;
            }
        }
        temp = a[i];
        a[i] = small;
        a[swap_j] = temp;
    }
    
    printf("\nPrinting the sorted array(Selection Sort)...\n");
    for(int k=0; k<n; k++)
    {
        printf("%d,",a[k]);
    }
    printf("\n----------\n");
}

void bubble_sort(int a[], int n)
{
    int temp;
    int flag;
    int count = 0;
    
    while(1)
    {
        flag = 0;
        for(int i=0; i<n-count-1; i++)
        {
            if(a[i]>a[i+1])
            {
                flag = 1;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        count++;
        if(flag == 0)
        {
            break;
        }
    }
    
    printf("\nPrinting the sorted array(Bubble Sort)...\n");
    for(int k=0; k<n; k++)
    {
        printf("%d,",a[k]);
    }
    printf("\n----------\n");
}

void insertion_sort(int a[], int n)
{
    int value;
    int hole;
    for(int i=1; i<n; i++)
    {
        value = a[i];
        for(int j=i-1; j>=0; j--)
        {
            if(value<a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                hole = j+1;
                break;
            }
        }
        a[hole] = value;
    }
    
    printf("\nPrinting the sorted array(Insertion Sort)...\n");
    for(int k=0; k<n; k++)
    {
        printf("%d,",a[k]);
    }
    printf("\n----------\n");
}

void partition(int list[],int low,int high)
{
    int mid;
 
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergeSort(list, low, mid, high);
    }
}
 
void mergeSort(int list[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[50];
 
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (list[lo] <= list[mi])
        {
            temp[i] = list[lo];
            lo++;
        }
        else
        {
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = list[k];
             i++;
        }
    }
 
    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    }
}

int main(int argc, char** argv) {

    
    int arr[15] = {1,145,256,3,71139,87,124,50,85,12,563,15,6,902,4};
    printf("Printing the actual array...\n");
    for(int k=0; k<15; k++)
    {
        printf("%d,",arr[k]);
    }
    selection_sort(arr, 15);
    //bubble_sort(arr, 15);
    //insertion_sort(arr, 15);
//    partition(arr,0,14);
//    printf("\nPrinting the sorted array(Merge Sort)...\n");
//    for(int k=0; k<15; k++)
//    {
//        printf("%d,",arr[k]);
//    }
//    printf("\n----------\n");
    
    return 0;
}

