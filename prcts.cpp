#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<vector<int>>a;
    set<int>t;
    
    for(int i=0;i<a.size();i++)
    {
        for(auto it:a[i])
        {
            cout<<it<<endl;
        }
    }
}