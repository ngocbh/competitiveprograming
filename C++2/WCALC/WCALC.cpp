#include <iostream>
#include <cmath>
using namespace std;
int64_t n,m,a,b,res=0;
int main()
{   cin>>b>>n;
    for (int m=0; m<=3*n; m++) {
        long long d,dx,dd;
        float du;
        d=2*b*m*n-b*m*m;
        dx=n*n;
        if ( d % dx == 0 ) {
            dd=d/dx;
            if ( dd < 0 ) continue;
            dx=(double) dd/m - (double)b/n;
            d=(double)(dd-b)/(m-n);
            //cout<<dd<<" "<<m<<endl;
            if ( d==dx ) {++res;  }
            else continue;
        }
    }
    cout<<res;
}
