/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "linear.h"

int linear_s(int elem, int a[])
{
    int found_index = -1;
    for(int i=0; i<9999; i++)
    {
        if(a[i] == elem)
        {found_index = i;break;}
    }
    return found_index;
}

