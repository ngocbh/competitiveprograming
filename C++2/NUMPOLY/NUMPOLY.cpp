#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define maxn 100000+100
#define base 100000
using namespace std;
int n,m,res=0,a[maxn],f[2*maxn],sum,ci,cj,nn,cii,cjj,cs;
vector <int> l,r;
int main()
{   freopen("NUMPOLY.inp","r",stdin);
    freopen("NUMPOLY.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    for (int i=1; i<=n; i++) sum=sum+a[i];
    sort(a+1,a+n+1);
    r.push_back(a[n]);
    nn=n-1; ci=1; cj=n-1;
    while ( nn > 0 ) {
       l.push_back(a[ci]); ++ci; --nn;
       if ( nn==0 ) break;
       r.push_back(a[ci]); ++ci; --nn;
       if ( nn==0 ) break;
       l.push_back(a[cj]); --cj; --nn;
       if ( nn==0 ) break;
       r.push_back(a[cj]); --cj; --nn;
    }
    cs=0;
    for (int i=l.size()-1; i>=0; i-- ) f[++cs]=l[i];
    for (int i=0; i<=r.size(); i++ ) f[++cs]=r[i];
    f[0]=f[n];
    f[n+1]=f[1];
    for (int i=1; i<=n; i++) cout<<f[i]<<" ";

    cout<<endl;
    for (int i=1; i<=n; i++) {res+=f[i]*(sum-f[i-1]-f[i+1]); cout<<res<<endl; }
    cout<<res/2;
}
