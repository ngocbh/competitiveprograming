#include <bits/stdc++.h>

using namespace std;
ifstream fi("avg.inp");
ofstream fo("avg.out");
const long maxn=1000+10;
int t,n,a[maxn],b[maxn],k,res;
int tim(int aa)
{
    int l=k+1,r=n,res=k;
    while (l<=r){
        int mid;
        mid = (l+r)/2;
        if (b[mid]<aa) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
int tim1(int aa)
{
    int l=k+1,r=n,res=k;
    while (l<=r){
        int mid;
        mid = (l+r)/2;
        if (b[mid]<=aa) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
void xuly()
{   res=0;
    fi>>n;
    for (int i=1; i<=n; i++) fi>>a[i];
    ///=================
    for ( k=2; k<=n-1; k++){
        for (int i=1; i<=n; i++) b[i]=a[i];
        sort(b+k+1,b+n+1);
      //  for (int i=1; i<=n; i++) fo<<b[i]<<" "; fo<<endl;
        for (int i=k-1; i>=1; i--){
            int m,m1;
            m=tim(2*a[k]-a[i]);
            m1=tim1(2*a[k]-a[i]);
            res+=m1-m;
           // fo<<m1<<" "<<m<<endl;
        }
    }
    fo<<res<<endl;

}
int main()
{  fi>>t;
   for (int i=1; i<=t; i++) xuly();
}
