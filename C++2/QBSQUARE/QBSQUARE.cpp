#include <iostream>
#include <stdio.h>
#include <stack>
#include <memory.h>
#define maxn 1000+10
using namespace std;
int n,m,a[maxn][maxn],h[maxn],l[maxn],r[maxn],res=0,hh[maxn];
void search_l(int h[])
{   stack <int> s;
    s.push(0);
    for (int i=1; i<=n; i++) {
        while ( h[s.top()] >= h[i] ) s.pop();
        l[i]=s.top();
        s.push(i);
    }
}
void search_r(int h[])
{   stack <int> s;
    s.push(n+1);
    for (int i=n; i>=1; i--) {
        while ( h[s.top()] >= h[i] ) s.pop();
        r[i]=s.top();
        s.push(i);
    }
}
int main()
{   //freopen("QBSQUARE.inp","r",stdin);
    //freopen("QBSQUARE.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) scanf("%d",&a[i][j]);
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++)
            if ( a[i][j] == 1 ) ++h[j],hh[j]=0;
            else h[j]=0,++hh[j];
        h[0]=-1;    hh[0]=-1;
        h[n+1]=-1;  hh[n+1]=-1;
        search_l(h);
        search_r(h);
        for (int o=1; o<=n; o++) {
            int aa;
            aa=min( h[o] , r[o]-l[o]-1 );
            res=max(res,aa);
        }
        search_l(hh);
        search_r(hh);
        for (int o=1; o<=n; o++) {
            int aa;
            aa=min( hh[o] , r[o]-l[o]-1 );
            res=max(res,aa);
        }
    }
    cout<<res;
}
