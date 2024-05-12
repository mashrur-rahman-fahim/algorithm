#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&a,int l,int h)
{
    int i=l-1;
    int piv=a[h];
    for(int j=l;j<h;j++)
    {
        if(a[j]<=piv)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return (i+1);
}
int partition_r(vector<int>&a,int l,int h)
{
    srand(time(NULL));
    int random=l+rand()%(h-l);
    swap(a[random],a[h]);
    return partition(a,l,h);
}
void quick_sort(vector<int>&a,int l,int h)
{
    if(l<h)
    {
        int j=partition_r(a,l,h);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,h);
    }
}
void print(vector<int>&a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    vector<int>a;
    for(int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    quick_sort(a,0,a.size()-1);
    print (a);
}