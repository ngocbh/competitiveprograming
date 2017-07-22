#include <bits/stdc++.h>
using namespace std;

const int maxn=50000+100;

int n,m,a[maxn],f[8*maxn],t[8*maxn],u,v,oo,l,r,res;

void update(int k,int l,int r)
{   f[k]+=t[k];
    t[k*2]+=t[k];
    t[k*2+1]+=t[k];
    t[k]=0;
    if (l>v || r<u) return;
    if (l>=u && r<=v) {
        f[k]+=oo;
        t[k*2]+=oo;
        t[k*2+1]+=oo;
        return;
    }
    int mid;
    mid=(l+r)/2;
    update(k*2,l,mid);
    update(k*2+1,mid+1,r);
    f[k]=max(f[2*k],f[k*2+1]);
}

void visit(int k,int l, int r)
{
    f[k]+=t[k];
    t[k*2]+=t[k];
    t[k*2+1]+=t[k];
    t[k]=0;
    if (l>v or r<u) return;
    if (l>=u and r<=v) {
        res=max(res,f[k]);
        return;
    }
    int mid;
    mid=(l+r)/2;
    visit(k*2,l,mid);
    visit(k*2+1,mid+1,r);
}

void xuly1()
{
    scanf("%d%d%d",&u,&v,&oo);
    update(1,1,n);
}

void xuly2()
{
    scanf("%d%d",&u,&v);
    res=0;
    visit(1,1,n);
    printf("%d\n",res);
}
int main()
{
   // freopen("qmax2.inp","r",stdin);
  //  freopen("qmax2.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++){
        int truy;
        scanf("%d",&truy);
        if (truy==0) xuly1();
        else xuly2();
    }
}
