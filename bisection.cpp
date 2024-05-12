#include<bits/stdc++.h>
using namespace std;
float f(float x)
{
    return pow(x,5)+14*pow(x,4)-5*x+10;
}
float f1(float x){
return (5*pow(x,4)+(14*4)*pow(x,3)-5);}
int main()
{
    float a,b;
    
    
    a=0;
    b=2;
    
    if(f1(a)*f1(b)>0)
    cout<<"FUCK YOU!"<<endl;
    else
    {
        float x0;
        int i=0;
        
        do{
            i++;
            float prev=x0;
           
             //x0=(a+b)/2.0;
            x0= (a-(f1(a)*(b-a)))/(f1(b)-f1(a));

             float t1=a;
             float t2=b;
            
             
            float f0=f1(x0);
            if(f0*f1(a)<0)
            {
                b=x0;
            }
            else
            a=x0;
            cout<<i<<" "<<a<<" "<<b<<" "<<x0<<" "<<t1<<" "<<t2<<" "<<f(x0)<<endl;
            if(i<=1)
            continue;
            else
            {
                if(abs(prev-x0)<0.0001 && f(x0)<10.00)
                break;
            }
        }while(1);
        
        
    }

}