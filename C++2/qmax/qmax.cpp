#include <bits/stdc++.h>
#define maxn 50500
using namespace std;
int n,m,q,a[maxn],f[4*maxn],res,u,v,k;
void update(int k,int l ,int r)
{   //if (l>r) return;
    if (l==r) {f[k]=a[l];return;}
    int mid;
    mid=(l+r)/2;
    update(2*k,l,mid);
    update(2*k+1,mid+1,r);
    f[k]=max(f[2*k],f[2*k+1]);
}
void visit(int k,int l,int r)
{
    if (l>v||r<u) return;
    if (l>=u&&r<=v){
        res=max(res,f[k]);
        return;
    }
    int mid;
    mid=(l+r)/2;
    visit(2*k,l,mid);
    visit(2*k+1,mid+1,r);
}
int main()
{
    freopen("qmax.inp","r",stdin);
   freopen("qmax.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++){
        //int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        a[u]+=k;
        a[v+1]-=k;
    }
    for (int i=1; i<=n; i++) a[i]=a[i-1]+a[i];
     //for (int i=1; i<=n; i++) printf("%d ",a[i]);
     update(1,1,n);
     //visit(1,1,n);
    scanf("%d",&q);
     for (int i=1; i<=q; i++)
     { scanf("%d%d",&u,&v);
       res=0;
       visit(1,1,n);
       printf("%d\n",res);
     }
}
