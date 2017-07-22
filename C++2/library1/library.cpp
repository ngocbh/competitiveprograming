#include <iostream>
#include <stdio.h>

using namespace std;
const long maxn=1000000+100;
int n,t,a[maxn],b[maxn],f[maxn];
int tim(int x,int ll,int rr)
{
    int l=ll,r=rr,res=0;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if (b[mid]<x) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
void xuly()
{
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    a[0]=-1;
    b[0]=-1;
    int k=0,p;
    for (int i=1; i<=n; i++){
        p=tim(a[i],0,k);
        if (p==k) { ++k; b[k]=a[i]; }
            else b[p+1]=a[i];
        f[i]=p+1;
    }
    cout<<n-k<<endl;

}
int main()
{
   freopen("library.inp","r",stdin);
   freopen("library.out","w",stdout);
   cin>>t;
   while (t--) xuly();
}
