#include <iostream>
#include <stdio.h>
#include <stack>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define maxn 15000+100
#define maxm 1500+100
using namespace std;
int n,m,a[maxn][maxm],h[maxm],res=0,l[maxm],r[maxm],h1[maxm];
void xuly()
{
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            if ( a[i][j] == 1 ) h[j]=h[j]+1;
            else h[j]=0;
        h[0]=-1;
        h[m+1]=-1;
        for (int o=1; o<=m; o++) h1[o]=h[o];
        sort(h1+1,h1+m+1);
        for (int o=1; o<=m; o++) {
            int ress;
            ress=h1[o]*( m-o+1 );
            res=max(res,ress);
        }
    }
    printf("%d",res);
}
int main()
{   freopen("MAXREC.inp","r",stdin);
    freopen("MAXREC.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++) {

                char cc[maxm];
                gets(cc);
                for (int j=1; j<=m; j++) {
                if ( cc[j] =='1' ) a[i][j]=1;
                else a[i][j]=0;
        }
    }
    xuly();
}
