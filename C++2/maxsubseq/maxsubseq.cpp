#include <bits/stdc++.h>
using namespace std;
const long maxn=1000000+1000;
int a[maxn],f1[5*maxn],f2[5*maxn],f[maxn],resmax,resmin,res;
int t,n,u,v,l1,l2;
void update_t(int k,int l,int r)
{
     if (l==r) {f1[k]=f[l]; f2[k]=f[l]; return;}
    int mid;
    mid=(l+r)/2;
    update_t(2*k,l,mid);
    update_t(2*k+1,mid+1,r);
    f1[k]=max(f1[2*k],f1[2*k+1]);
    f2[k]=min(f2[2*k],f2[2*k+1]);
}
void visit(int k,int l,int r)
{
   if (l>v||r<u) return;
    if (l>=u&&r<=v){
        resmax=max(resmax,f1[k]);
        resmin=min(resmin,f2[k]);
        return;
    }
    int mid;
    mid=(l+r)/2;
    visit(2*k,l,mid);
    visit(2*k+1,mid+1,r);

}

void xuly()
{   int oo=100000000;
    scanf("%d %d %d",&n,&l1,&l2);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    for (int i=1; i<=n; i++) f[i]=f[i-1]+a[i];
    //for (int i=1; i<=n; i++) printf("%I64d ",f[i]); printf("\n");
    //cout<<l1<<" "<<l2;
    update_t(1,1,n);
    res=-oo;
    for (int i=0; i<=n-l1; i++){
        resmin=oo;
        resmax=-oo;
        u=i+l1;
        v=i+l2;
        if (v>n) v=n;
        visit(1,1,n);
        if ( resmax-f[i]>res ) res=resmax-f[i];
       // if (resmin-f[i]>res) res=resmin-f[i];
    }
    cout <<res<<endl;
}
int main()
{
    //freopen("maxsubseq.inp","r",stdin);
    //freopen("maxsubseq.out","w",stdout);
    scanf("%d",&t);
    for (int i=1; i<=t ; i++) {
        memset(a,0,sizeof(a));
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        memset(f,0,sizeof(f));
        xuly();
    }
}
