#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <cmath>
#define maxn 1000+100
using namespace std;
int n,a[maxn][maxn],ss=0,d,kq[maxn*maxn],res,ress=0, ca[5][maxn][maxn];
typedef pair <int,int> ii;
void dfs(int u,int v,int ii)
{
    ca[ii][u][v]=d;
    ++res;
    for (int i=-1; i<=1; i++)
        for (int j=-1; j<=1; j++)
            { if ( (abs(i) == 1 && abs(j) == 1 ) || ( i==j && j==0 ) ) continue;
            int iii,iij;
            if ( i==-1 && j==0 ) iii=1,iij=3;
            if ( i==0 && j==-1 ) iii=2,iij=4;
            if ( i==1 && j==0 ) iii=3,iij=1;
            if ( i==0 && j==1 ) iii=4,iij=2;
            if ( ca[1][u+i][v+j]!=d && u+i>0 && u+i<=n && v+j>0 && v+j<=n && ca[2][u+i][v+j]!=d && ca[3][u+i][v+j]!=d && ca[4][u+i][v+j]!=d )
                if ( abs( a[u][v] - a[u+i][v+j] ) == d ) {
                ca[iij][u][v]==d;
                dfs(u+i,v+j,iii);
            }
        }
}
void ttplt()
{   ss=0;
    memset(ca,true,sizeof(ca));
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++){
            if ( i>1 && ca[1][i][j] ) {
                ++ss;
                res=0;
                d=abs(a[i][j]-a[i-1][j]);
                dfs( i,j,1 );
                if ( res>ress ) ress=res;
            }
            if ( j>1 && ca[2][i][j] ){
                ++ss;
                res=0;
                d=abs( a[i][j]-a[i][j-1]);
                dfs( i,j,2 );
                if ( res>ress ) ress=res;
            }
            if ( i<n && ca[3][i][j] ){
                ++ss;
                res=0;
                d=abs( a[i][j]-a[i+1][j] );
                dfs( i,j,3 );
                if ( res>ress ) ress=res;
            }
            if ( j<n && ca[4][i][j] ){
                ++ss;
                res=0;
                d=abs( a[i][j]-a[i][j+1] );
                dfs( i,j,4 );
                if ( res>ress ) ress=res;
            }

        }
    cout<<ress;
}
int main()
{   freopen("rselect.inp","r",stdin);
    freopen("rselect.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) scanf("%d",&a[i][j]);
    ttplt();

}
