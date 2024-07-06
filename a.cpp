#include <bits/stdc++.h>
using namespace std;
#define f double
f func(vector<f> &coff, f x)
{
    f res = 0;
    for (int i = 0; i < coff.size(); i++)
    {
        res = res * x + coff[i];
    }
    return res;
}

int main()
{
    f n, x1, x2, x0, ds;
    cin >> n >> ds;
    vector<f> coff(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> coff[i];
    f f0;
    f x_max = sqrt((pow((coff[1] / coff[0]), 2)) - (2 * (coff[2] / coff[0])));
    f a = -x_max;
    while (1)
    {
        x1 = a;
        x2 = x1 + ds;
        f f1 = func(coff, x1);
        f f2 = func(coff, x2);
        if (f1 * f2 > 0)
        {
            if (x2 >= x_max)
            break;
                a = x2;
            continue;
        }
        else
        {
            while (1)
            {
                x0 = (x1 + x2) / 2;
                f0 = func(coff, x0);
                if (f1 * f0 < 0)
                {
                    x2 = x0;
                }
                else
                {
                    x1 = x0;
                    f1 = f0;
                }
                if ((fabs(x2 - x1) / x2) < 0.00005)
                {
                    x0 = (x1 + x2) / 2;
                    break;
                }
            }
            cout<<x0<<endl;
            if (x2 >= x_max)
                break;
            a=x2;
        }
    }
}