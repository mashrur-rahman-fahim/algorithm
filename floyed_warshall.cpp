#include<bits/stdc++.h>
using namespace std;
#define ll long long
void floyed(vector<vector<pair<ll,ll>>>&a,vector<vector<ll>>&d, vector<vector<ll>>&path)
{
   
   
     
    
   
    
    
  
   
    
    for(int i=0;i<a.size();i++)
    {
        
        for(int j=0;j<a.size();j++)
        {
            for(int k=0;k<a.size();k++)
            {
                ll temp=d[j][k];
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
              
                if(temp!=d[j][k]){
                path[j][k]=path[i][k];
                
                }
               
            }
           
        }
        
       
       
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<pair<ll,ll>>>a(n);
    for(int i=0;i<e;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
    }vector<vector<ll>>path;
    vector<vector<ll>>D;
    for(int i=0;i<n;i++)
    {
        vector<ll>t,p;
        for(int j=0;j<n;j++)
        {
            if(i==j){
            t.push_back(0);continue;}
            t.push_back(INT_MAX);
            p.push_back(INT_MAX);
            
        }
        p.push_back(INT_MAX);
        D.push_back(t);
        path.push_back(p);
       
        p.clear();

        t.clear();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            D[i][a[i][j].first]=a[i][j].second;
        }
    }
   
   
    

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            path[i][a[i][j].first]=i;
        }
    }
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
 
    
    floyed(a,D,path);
    // cout<<D.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }

} 
//  5
// 9
// 0 1 3
// 0 4 -4
// 0 2 8
// 1 3 1
// 1 4 7
// 2 1 4
// 3 2 -5
// 3 0 2
// 4 3 6





