#include <bits/stdc++.h>

using namespace std;
ifstream fi("sum.inp");
ofstream fo("sum.out");
const long oo=1000000000+7;
double a1,b1;
int64_t tich1,tich2,tich3;
int main()
{  fi>>a1>>b1;
int a,b;
a=(int) a1; b=(int) b1;
   if (a1!=a) ++a;
///===============
int64_t m1,m2,m3;
m1=b; m2=b+1; m3=2*b+1;
if (m1%2==0) m1=m1/2;
else m2=m2/2;
if (m1%3==0) m1=m1/3;
else {
    if (m2%3==0) m2=m2/3;
    else m3=m3/3;
}
tich1=(((m1*m2) % oo) *(m3%oo)) %oo;

m1=a-1; m2=a; m3=2*(a-1)+1;
if (m1%2==0) m1=m1/2;
else m2=m2/2;
if (m1%3==0) m1=m1/3;
else {
    if (m2%3==0) m2=m2/3;
    else m3=m3/3;
}
tich2=(((m1*m2) % oo) *(m3%oo)) %oo;
tich3=(tich1-tich2)%oo;
if (tich3<0) tich3=tich3+oo;

fo<<tich3;
}
