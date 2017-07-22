#include <bits/stdc++.h>
const long N = 100000 + 10;
using namespace std;

int64_t n,m,a[N],u,l,res=0;
int64_t f[8*N],t[8*N];
void taocay(int64_t k,int64_t l,int64_t r)
{
    if (l == r){
        f[k] = a[l];
        //t[k] = f[k];
        return;
    }

    int mid;
    mid=(l+r)/2;
    taocay(k*2,l,mid);
    taocay(k*2+1,mid+1,r);
    f[k]=max(f[2*k],f[k*2+1]);
    //t[k] = f[k];
}
void visit(int64_t k,int64_t l, int64_t r,int64_t u,int64_t v)
{
    if ( f[k] < t[k] )f[k] = t[k];
    if ( t[2*k] < t[k] )t[2*k] = t[k];
    if ( t[2*k+1] < t[k] )t[2*k+1] = t[k];
    if (l>v or r<u) return;
    if (l>=u and r<=v) {
        res=max(res,f[k]);
        return;
    }
    int mid;
    mid=(l+r)/2;
    visit(k*2,l,mid,u,v);
    visit(k*2+1,mid+1,r,u,v);
}
void update(int64_t k,int64_t l,int64_t r,int64_t u,int64_t v,int64_t oo)
{   if ( f[k] < t[k] )f[k] = t[k];
    if ( t[2*k] < t[k] )t[2*k] = t[k];
    if ( t[2*k+1] < t[k] )t[2*k+1] = t[k];
    if (l>v || r<u) return;
    if (l>=u && r<=v) {
        f[k]=oo;
        t[k]=oo;
        t[k*2]=oo;
        t[k*2+1]=oo;

        return;
    }
    int mid;
    mid=(l+r)/2;
    update(k*2,l,mid,u,v,oo);
    update(k*2+1,mid+1,r,u,v,oo);
    f[k]=max(f[2*k],f[k*2+1]);
}
int main()
{   //freopen("GAMES.inp","r",stdin);
    scanf("%d %d", &n,&m);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    taocay(1,1,n);
    //for (int i=1; i<=8*n; i++) t[i] = f[i];
    int64_t v;
    for (int i=1; i<=m; i++) {
            scanf("%d %d", &u, &l);
            res=0;
            v = min(u+l-1,n);
            visit(1,1,n,u,v);
            //for (int i=1; i<=4*n; i++) cout<<f[i]<< " "; cout<<endl;
            printf("%lld\n",res+1);
            update(1,1,n,u,v,res+1);
            //for (int i=1; i<=4*n; i++) cout<<f[i]<< " "; cout<<endl;
    }
}
