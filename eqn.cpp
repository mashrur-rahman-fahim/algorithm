#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x,y;
    cin>>x>>y;
    double res=y+(3/(x+y));
    double res2=(((6-x*x)/x)+y)/2.00;
    cout<<res<<" "<<res2;
}