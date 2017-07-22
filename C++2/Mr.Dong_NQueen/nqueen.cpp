#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#define maxn 100+10
using namespace std;
int n,cc[4*maxn],cp[4*maxn],h[maxn],a[maxn];
bool ok;
void mark(int x,int y,bool ca)
{
    cc[x+y]=ca;
    cp[y-x+100]=ca;
    h[y]=ca;
}
void ikq()
{
    for (int i=1; i<=n; i++) printf("%d ",a[i]); printf("\n");
}
void duyet(int i)
{   if ( ok ) return;

    if ( i>n ) { ikq(); ok=true; return; }
    if ( a[i]!=0 ) { duyet(i+1); return; }
    for (int j=1; j<=n; j++)
        if ( h[j] && cp[j-i+100] && cc[i+j] ) {
            mark(i,j,false);
            a[i]=j;
            duyet(i+1);
            a[i]=0;
            mark(i,j,true);
        }
}
int main()
{   freopen("nqueen.inp","r",stdin);
    freopen("nqueen.out","w",stdout);
    while ( cin>>n != 0 ) {
        ok=false;
        memset(cc,true,sizeof(cc));
        memset(cp,true,sizeof(cp));
        memset(h,true,sizeof(h));
        for (int i=1; i<=n; i++) {
                cin>>a[i];
                if ( a[i] != 0 ) mark(i,a[i],false);
        }
        duyet(1);

    }
}
