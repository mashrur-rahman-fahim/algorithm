#include<bits/stdc++.h>
using namespace std;
void insertion(vector<int>&a)
{
    for(int i=1; i<a.size(); i++)
    {
        int k=a[i];
        int j=i-1;
        while(j>=0 && k<a[j])
        {
            a[j+1]=a[j];
            j--;

        }
        a[j+1]=k;
    }
}
void print(vector<int>&a)
{

    for(int i=0; i<a.size(); i++)
    {

        cout<<a[i]<<" ";
    }
    cout<<endl;
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
    insertion(a);
    print(a);
}
