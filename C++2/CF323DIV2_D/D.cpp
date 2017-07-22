#include <iostream>
#include <algorithm>
#include <stdio.h>
#define fi cin
#define fo cout
using namespace std;
int n,x[1000010],y[1000010],a[1000010],pos[10001],b[1000010],f[1000010],k, as[1000010], ca[400];

int tim(int t,int k1,int k)
{ int l=k1, h=k,m, ret = 0;
  while(l <= h){
   int   m = ( l + h ) / 2;
       //if ((b[m+1]>t)&&(t>b[m])) return m;
        if (b[m]<=t) ret = m, l = m + 1;
        else h = m - 1;}
 //if (m>k) return k; else
  return ret;
}
void dctdn()
{ a[0]=-1;
  b[0]=-1;
  int p;
  k=0;
 for (int i=1;i<=n;++i)
 { p=tim(a[i],0,k);
   if (p==k) {++k; b[k]=a[i];}
   else b[p+1]=a[i];
   f[i]=p+1;
   //fo<<k;
 }
}

int main()
{   //freopen("D.inp","r",stdin);
    int TT,_max = 0;
    fi>>n >> TT;
    for (int i=1;i<=n;++i) fi>>a[i], ca[a[i]]++, _max = max(ca[a[i]],_max);

    for (int i = n+1; i <= n*min(TT,n); i++) a[i] = a[i-n];
    int nn = n;
    n = n*min(TT,n);
    dctdn();
    int ans = 0;
    if ( TT - nn > 0 )
    k += (TT-nn)*_max;
    cout << k;

}
