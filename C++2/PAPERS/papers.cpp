#include <iostream>
#include <stdio.h>
#include <cmath>
#define maxn 100000+1000
#define base 1000000000+7
using namespace std;
int n,m,a[maxn],res=0,ress1=1,ress2=1;

int main()
{   freopen("papers.inp","r",stdin);
    freopen("papers.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=n; i++) cin>>a[i],res+=a[i];
    m=m-res;
    for (int i=1; i<=n-1; i++) ress1=( ress1 * i );
    for (int i=m+1; i<=n+m-1; i++) ress2*=i;
    res=ress2/ress1;
    cout<<res;
}
