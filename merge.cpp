#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&a,int l,int m,int h)
{

    int s1=m-l+1;
    int s2=h-m;
    int lft[s1],r[s2];
    for(int i=0;i<s1;i++)
        lft[i]=a[i+l];
    for(int i=0;i<s2;i++)
        r[i]=a[m+1+i];
    lft[s1]=INT_MAX;
    r[s2]=INT_MAX;
    int i=0,j=0;
    for(int k=l;k<=h;k++)
    {
        if(lft[i]<r[j])
        {
            a[k]=lft[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }

    }
}
void merge_sort(vector<int>&a,int l,int h)
{
    if(l<h)
    {
        int m=h+l/2;
        int m1=(l+m)/2;
        int m2=(m1+h)/2;
        merge_sort(a,l,m1);
        merge_sort(a,m1+1,m2);
        merge_sort(a,m2+1,h);
        merge(a,l,m1,h);
        merge(a,l,m2,h);
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
    merge_sort(a,0,a.size()-1);
    print(a);
}
