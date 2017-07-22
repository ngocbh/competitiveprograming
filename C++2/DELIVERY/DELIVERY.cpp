#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxn 1000+10
using namespace std;
int t,n,m,a[maxn],b[maxn];
int main()
{   freopen("DELIVERY.inp","r",stdin);
    freopen("DELIVERY.out","w",stdout);
    cin>>t;
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    cin>>m;
    for (int i=1; i<=m; i++) cin>>b[i];
    int nho=1,tt=0,res=0;
    for (int i=1; i<=n; i++)
       { if ( tt+a[i] > t ) break;
         tt+=a[i];
         nho=i;
         ++res;
       }
    //cout<<nho<<endl;
    for (int i=nho+1; i<=n; i++)
         {   ++m;
             b[m]=a[i];
         }
    sort(b+1,b+m+1);
    tt=0;
    for (int i=1; i<=m; i++) {
        if ( tt+b[i] > t ) break;
        tt+=b[i];
        ++res;
    }
    cout<<res;


}
