#include <bits/stdc++.h>
const long N = 10e9;
const double P = 10000;
using namespace std;
int64_t t,tt1,tt2,TT1,TT2;
double res,kq,T1,T2,t1,t2;
double cc(double x)
{
    if ( x < 0 ) return 0;
    else return x;
}
int main()
{  // freopen("FRNDMTNG.inp","r",stdin);
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d%d",&TT1,&TT2,&tt1,&tt2);

        T1 =(double) TT1 * P; T2 =(double) TT2 * P; t1 = (double) tt1 * P; t2 =(double) tt2 * P;
        res=0; ++T1; ++T2;
        //cout<<T1<<" "<<T2<<" "<<t1<<" "<<t2<<endl;
        if ( T1 + t1 > T2 ) { swap(T1,T2); swap(t1,t2); }
        if ( t1 < T1 )
                res += min(cc(T2-t1),T1)*(t1+1) + (t1*(t1+1))/2;
        else
                res += cc(T2-t1) * t1 + (min(T2,t1)*(min(T2,t1)-1)) /2;
           // cout<<res<<endl;
        if ( t2 > T1 ) res += (T1*(T1-1))/2;
        else res += (T1-t2)*t2 +( (t2-1)*t2 ) /2;
       // cout<<res<<endl;
        kq = res / ( T1*T2 );
        printf("%0.6lf\n" , kq );
    }

}
