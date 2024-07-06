#include<bits/stdc++.h>
using namespace std;
bool place(int k,int i,vector<int>&sol)
{
    for(int j=1;j<k;j++)
    {
        if((sol[j]==i)|| abs(sol[j]-i)==abs(j-k))
        return false;
    }
    return true;
}
void nQueens(vector<int>&sol,int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i,sol))
        {
            sol[k]=i;
            if(k==n)
            {
                for(int i=1;i<=n;i++)
                cout<<sol[i]<<" ";

                cout<<endl;
            }
            else
            nQueens(sol,k+1,n);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>sol(n+1);
    int k=1;
    nQueens(sol,k,n);
}