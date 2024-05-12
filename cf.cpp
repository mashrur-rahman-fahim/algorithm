#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{ 
    
    int res = min(a, b); 
    while (res > 0) { 
        if (a % res == 0 && b % res == 0) { 
            break; 
        } 
        res--; 
    } 
  
    
    return res; 
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int m=INT_MIN;
        int y=1;
        for(int i=1;i<x;i++)
        {
            if(gcd(x,i)+i>m)
            {
                m=gcd(x,i)+i;
                y=i;
            }
 
        }
        cout<<y<<endl;
 
    }
}