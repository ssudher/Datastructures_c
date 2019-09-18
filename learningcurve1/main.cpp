/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include<unordered_map>
#include <map>

using namespace std;


////-----------------------------------------------------------
//class calc{
//public:
//    template <typename t>
//    t add(t x, t y)
//    {
//        return x+y;
//    }
//    int sub(int x, int y)
//    {
//        return x-y;
//    }
//    int mul(int x, int y)
//    {
//        return x*y;
//    }
//    int div(int x, int y)
//    {
//       return x/y;
//    }
//};
//
//int main()
//{
//    calc obj;
//    int x, y;
//    cout<<"Enter the numbers"<<endl;
//    cin>>x>>y;
//    cout<<"SUM:"<<obj.add(4.2,2.4)<<endl
//            <<"DIFF:"<<obj.sub(x,y)<<endl
//            <<"PROD:"<<obj.mul(x,y)<<endl
//            <<"DIV:"<<obj.div(x,y)<<endl;
//}
//
//
////-----------------------------------------------------------



int main()
{
    
    string sent = "geeks for geeks geeks quiz practice qa for";
    unordered_map<string, int> freq;
    string word = "";
    
    for(auto c: sent)
    {
        if(c == ' ')
        {
            if(freq.find(word)==freq.end())
            {
                freq.insert(make_pair(word,1));
                word = "";
                continue;
            }
            else
            {
                int curr = freq.at(word);
                freq[word] = curr+1;
                word = "";
                continue;
            }
        }
        else
        {
            word = word+c;
        }
    }
    
    for(auto k=freq.begin(); k!=freq.end(); k++)
    {
        cout<<k->first<<": "<<k->second<<endl;
    }
    
    
    cout<<"_________________________"<<endl;
    multimap<int, string> mp;
    
    for(auto i=freq.begin(); i!=freq.end(); i++)
    {
        mp.insert(make_pair(i->second,i->first));
    }
    
    for(auto i=mp.begin(); i!=mp.end(); i++)
    {
        cout<<i->second<<":"<<i->first<<endl;
    }
    
}



