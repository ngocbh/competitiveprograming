#include <bits/stdc++.h>

using namespace std;
ifstream fi("triangle.inp");
ofstream fo("triangle.out");
const long maxn=1000+10;
int t,n,w,a[maxn],b[maxn],c[maxn];
int tim(int x)
{   bool ok=false;
    int l=1,r=n,res=0;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if (c[mid]<=x) res=mid,l=mid+1,ok=true;
        else r=mid-1;
    }
   //if (!ok) return n;
    return res;
}
int tim1(int x)
{
    int l=1,r=n,res=n+1;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if (c[mid]>=x) res=mid,r=mid-1;
        else l=mid+1;
    }
    return res;
}
int64_t solve1()
{   int64_t res=0;
    for (int i=1; i<=n; i++){
        int m1=0,m2=0;
        for (int j=1;j<=n; j++){
            if (a[i]==b[j]) ++m1;
            if (a[i]==c[j]) ++m2;
         }
        res+=m1*m2;
    }

    return res;
}
void solve2()
{
    int64_t mm,res=0;
    mm=solve1();
    for (int i=1; i<=n; i++){
        int m1=0,m2=0;
        for (int j=1; j<=n; j++)
            {if (a[i]==b[j]) ++m1;
            if (2*a[i]>c[j]) ++m2;}
        res+=m1*m2;
    }
    //=====================
    for (int i=1; i<=n; i++){
        int m1=0,m2=0;
        for (int j=1; j<=n; j++)
            {if (b[i]==c[j]) ++m1;
            if (2*b[i]>a[j]) ++m2;}
        res+=m1*m2;
    }
    //=====================
    for (int i=1; i<=n; i++){
        int m1=0,m2=0;
        for (int j=1; j<=n; j++)
            {if (a[i]==c[j]) ++m1;
            if (2*a[i]>b[j]) ++m2;}
        res+=m1*m2;
    }
    fo<<res-2*mm<<endl;
}
void solve3()
{   int64_t res=0;
    int m1,m2;
    sort(c+1,c+n+1);
    //fo<<m1<<" "<<m2;
    for (int i=1; i<=n; i++)
      for (int j=1;j<=n; j++)
        {   if (a[i]+b[j]<=c[1]) continue;
            if (abs(a[i]-b[i])>c[n]) continue;
            int m1,m2;
            m1=tim1(a[i]+b[j]);
            m2=tim(abs(a[i]-b[j]));
            ++m2;
          //  if (m1-m2>0 && m1<n && m2>0)
           if (m1-m2>0)
            res+=m1-m2;
            //fo<<m1<<" "<<m2<<"*"<<a[i]<<" "<<b[j]<<endl;

        }
  fo<<res<<endl;
}
void xuly()
{
    fi>>n>>w;
    for (int i=1; i<=n; i++) fi>>a[i];
    for (int i=1; i<=n; i++) fi>>b[i];
    for (int i=1; i<=n; i++) fi>>c[i];
    if (w==1) fo<<solve1()<<endl;
    if (w==2) solve2();
    if (w==3) solve3();
}
int main()
{  fi>>t;
    for (int i=1;i<=t; i++)
    {
        xuly();
    }
}
