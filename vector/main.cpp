/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: shrik
 *
 * Created on 17 August, 2019, 3:10 PM
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * 
 */
void change(vector<int> *x)
{
    x->push_back(14);
}

int main(int argc, char** argv) {
    
    vector<int> y;
    y.push_back(10);
    y.push_back(11);
    y.push_back(12);
    y.push_back(13);
    change(&y);
    
    for(auto i=y.begin(); i!=y.end(); i++)
    {
        cout<<*i<<endl;
    }
        
    return 0;
}

