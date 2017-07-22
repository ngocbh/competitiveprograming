#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define maxn 100
using namespace std;
int n,m,ca[maxn][maxn],c[maxn][maxn],cs[maxn],a[maxn],b[maxn],aa[maxn],bb[maxn],b1[maxn];
bool cmp(int i, int j )
{
    return b[i]>=b[j];
}
void xuly()
{   memset(c,0,sizeof(c));
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));
    for (int i=1; i<=n; i++) b1[i]=b[i];
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) cs[j]=j;
        sort(cs+1,cs+n+1,cmp);
        //for (int i=1; i<=n; i++) cout<<b[i]<<" ";
        //cout<<endl;
        for (int j=1; j<=a[i]; j++) {
            c[i][cs[j]]=1;
            --b[cs[j]];
        }
    }
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if ( c[i][j] ) ++aa[i],++bb[j];
    for (int i=1; i<=m; i++) if ( a[i]!=aa[i] ) { cout<<-1<<endl; return; }
    for (int i=1; i<=n; i++) if ( b1[i]!=bb[i] ) { cout<<-1<<endl; return; }
 //   for (int i=1; i<=n; i++) if ( b[i]!=0 ) { cout<<-1<<endl; return; }

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) cout<<c[i][j];
    cout<<endl;

}
int main()
{   freopen("DDD.inp","r",stdin);
    freopen("DDD.out","w",stdout);
    while ( cin>>m != 0 ){
        cin>>n;
        for (int i=1; i<=m; i++) cin>>a[i];
        for (int i=1; i<=n; i++) cin>>b[i];
        xuly();
    }
}
