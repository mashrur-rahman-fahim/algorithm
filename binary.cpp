#include<bits/stdc++.h>
using namespace std;
void bin(vector<int>&a,int n)
{
    int l=0;
    int h=a.size()-1;
    while(l<h)
    {

        int mid=l+(h-l)/2;
        if(a[mid]==n)
        {

            cout<<"Found"<<endl;
            return ;
        }
        else if(a[mid]<n)
        {
            l=mid+1;
        }
        else
            h=mid-1;
    }
    cout<<"fuck you!"<<endl;

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

    bin(a,n);

}
