#include<bits/stdc++.h>
using namespace std;
void linear(vector<int>&a,int n)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==n)
        {

            cout<<"ORREEEEEEEEE!"<<endl;
            return ;
        }

    }
    cout<<"FUCK AUST! "<<endl;

}

int main()
{

    vector<int>a;
    for(int i=0; i<5; i++)
    {

        int x;
        cin>>x;
        a.push_back(x);
    }
    int n;
    cin>>n;
    linear(a,n);

}
