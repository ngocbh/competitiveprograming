#include <bits/stdc++.h>

using namespace std;
ifstream fi("meet.inp");
ofstream fo("meet.out");
const long maxn=100000+100;
int n,q,a[maxn],f[maxn],x,y;
int tim(int aa)
{
    int l=1,r=n,res=0;
    while (l<=r){
        int m;
        m=(l+r)/2;
        if (f[m]<=aa)
            res=m,l=m+1;
        else r=m-1;
    }
    return res;
}
void xuly(int x,int y)
{
    int i1,i2,m,cc,cc2,cc3;
    i1=tim(x); i2=tim(y);
    m=tim(abs(a[x]+a[y])/2);
   // fo<<m<<endl;
    cc=max(abs(f[m]-a[x]),abs(f[m]-a[y]));
    cc2 =max(abs(f[m+1]-a[x]),abs(f[m+1]-a[y]));
    cc3 =max(abs(f[m+2]-a[x]),abs(f[m+2]-a[y]));
   int kq;
   kq=min(cc,min(cc2,cc3));
  // fo<<a[x]<<" "<<a[y]<<endl;
   fo<<kq<<endl;

}
int main()
{ fi>>n>>q;
for (int i=1; i<=n; i++)
    {fi>>a[i]; f[i]=a[i];}
sort(f+1,f+n+1);
  for (int i=1; i<=q; i++){

    fi>>x>>y;
    xuly(x,y);
  }

}
