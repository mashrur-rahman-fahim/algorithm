#include<bits/stdc++.h>
using namespace std;
void sum_sub(int s,int k,int r,vector<int>&x,vector<int>&a,int m)
{
    x[k]=1;
    if(s+a[k]==m)
    {
        for(int i=0;i<=k;i++)
        cout<<x[i]<<" ";
        cout<<endl;
    }
    else if(s+a[k]+a[k+1]<=m)//porer item nite prbo naki && neowa jabe
    sum_sub(s+a[k],k+1,r-a[k],x,a,m);
    if(s+r-a[k]>=m && s+a[k+1]<=m)
    {
        x[k]=0;
        sum_sub(s,k+1,r-a[k],x,a,m);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int m;
    cin>>m;
    sort (a.begin(),a.end());
    int sum=0;
    
    for(int i=0;i<n;i++){
    sum=sum+a[i];
    cout<<a[i]<<' ';
    }
    cout<<endl;
    vector<int>x(n);
    if(sum>=m && a[0]<=m)
    {
        sum_sub(0,0,sum,x,a,m);
    }
   
    
}