/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: shrik
 *
 * Created on 16 August, 2019, 10:53 PM
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int,int> ump;
    int count = 0;
    for(auto i=nums.begin(); i!=nums.end(); i++)
    {
        ump.insert(make_pair(*i,count));
        count++;
    }

    for(auto k=ump.begin(); k!=ump.end(); k++)
    {
        int r;
        r = target - k->first;
        if(ump.find(r) != ump.end() && ump[r]!=k->second)
        {
            res.push_back(k->second);
            res.push_back(ump[r]);
            break;
        }
    }
    
    return res;
    }

vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> ump;
        int count = 0;
        for(auto i=nums.begin(); i!=nums.end(); i++)
        {
            int r;
            r = target - (*i);
            unordered_map<int, int>::iterator k;
            k = ump.find(r);
            if(k != ump.end())
            {
                res.push_back(k->second);
                res.push_back(count);
                break;
            }
            else
            {
                ump.insert(make_pair(*i,count));
                count++;
            }
        }
        return res;
    }
/*
 * 
 */
int main(int argc, char** argv) {
    
    vector<int> v1,r;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    r = twoSum2(v1, 12);
    
    cout<<"the indices are: "<<r[0]<<"&"<<r[1]<<endl;
    return 0;
}

