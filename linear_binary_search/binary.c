/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "binary.h"

int binary_s(int elem, int a[])
{
    int found_index = -1;
    int min =0, max =9999, mid;
    for(int i=0; min<=max; i++)
    {
        mid = (min + max)/2;
        //printf("min: %d, mid : %d, max: %d\n",min,mid,max);
        if(a[mid] == elem)
        {found_index = mid; break;}
        if(a[mid] < elem)
        {min = mid + 1;}
        if(a[mid] > elem)
        {max = mid - 1;}
    }
    return found_index;
}
/*
int binary_s(int elem, int a[])
{
    int found_index = -1;
    int min =0, max =9999, mid;
    while(min<=max)
    {
        mid = (min+max)/2;
        //printf("min: %d, mid : %d, max: %d\n",min,mid,max);
        if(a[mid] == elem)
        {
            found_index = mid;
            break;
        }
        else if(a[mid] > elem)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return found_index;
}*/