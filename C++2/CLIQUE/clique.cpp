#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <memory.h>
#define maxn 600+10
using namespace std;
int n,m,k,c[maxn],u[maxn],a[maxn][maxn],lenc=0,lenu,d[maxn];
bool ok;
void ikq()
{
    for (int i=1; i<=lenc; i++) cout<<c[i]<<" ";
    cout<<endl;
}
void duyet(int c[],int u[])
{
    if ( ok ) return;
    if ( lenu+lenc<k ) return;
    if ( lenc == k ) { ikq(); ok=true; return; }
    for (int i=1;  i<=n; i++)
        if ( u[i] == 1 ) {
            ///==khong chon i;
            u[i]=0;
            --lenu;
            duyet(c,u);
            u[i]=1;
            ++lenu;
            ///==chon i;

            int uu[maxn],llu=0,lu;
            lu=lenu;
            for (int v=1; v<=n; v++) uu[v]=u[v];
             u[i]=0;
            for (int v=1; v<=n; v++)
                if ( a[i][v] && u[v] ) u[v]=1,++llu;
                else u[v]=0;
            c[++lenc]=i; lenu=llu;
            duyet(c,u);
            --lenc; lenu=lu;
            for (int i=1; i<=n; i++) u[i]=uu[i];
            break;
        }
}
void xuly1()
{
     memset(a,false,sizeof(a));
        for (int i=1; i<=m;i++) {
                int u,v;
               cin>>u>>v;
                a[u][v]=true;
                a[v][u]=true;
        }
        ok=false;
        lenu=n;
        lenc=0;
        for (int i=1; i<=n; i++) u[i]=1;

        for (int i=1; i<=n; i++) c[i]=0;
        duyet(c,u);
        if ( !ok ) cout<<-1<<endl;
}
void xuly2()
{
    memset(a,false,sizeof(a));
    memset(d,0,sizeof(d));
       for (int i=1; i<=m;i++) {
                int u,v;
                scanf("%d%d",&u,&v);
                a[u][v]=true;
                a[v][u]=true;
        }
    for (int i=1; i<=n-1; i++)
        for (int j=1; j<=n; j++)
            if ( i!=j && !d[i] && !d[j] && !a[i][j] ){
            d[i]=1;
            d[j]=1;
        }
        int sl=0;
    for (int i=1; i<=n; i++) {if ( sl == k ) break;
        if ( d[i]==0 ) {
        cout<<i<<" ";
        ++sl;
        }

    }
printf("\n");
}
int main()
{   freopen("clique.inp","r",stdin);
    freopen("clique.out","w",stdout);
    int t;
    scanf("%d",&t);

    while ( t-- ){
        scanf("%d%d%d",&n,&m,&k);
        if ( n<=60 )
       xuly1();
        else
            xuly2();
    }

}
