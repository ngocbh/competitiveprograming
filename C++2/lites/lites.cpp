#include <bits/stdc++.h>

using namespace std;
const long maxn=100000+100;
int n,m,b[8*maxn],u,v,l,r,oo,res;
pair <int,int> f[8*maxn];
void update(int k,int l,int r)
{   if (f[k].second % 2==1){
       f[k].first=(r-l+1)-f[k].first;
       f[2*k].second++;
       f[2*k+1].second++;
       f[k].second=0;
    }
    if (l>v || r<u) return;
    if (l>=u && r<=v) {
        f[k].first=r-l+1-f[k].first;
        f[2*k].second++;
        f[2*k+1].second++;
        f[k].second=0;
        return;
    }
    int mid;
    mid=(l+r)/2;

    update(2*k,l,mid);
    update(2*k+1,mid+1,r);

    f[k].first=f[2*k].first+f[2*k+1].first;
}
void visit(int k,int l,int r)
{    if (f[k].second % 2==1){
       f[k].first=(r-l+1)-f[k].first;
       f[2*k].second++;
       f[2*k+1].second++;
       f[k].second=0;
    }
    if (l>v || r<u) return;
    if ( l>=u && r <=v ){
        res+=f[k].first;
        return;
    }
    int mid;
    mid=(l+r)/2;
    visit(k*2,l,mid);
    visit(k*2+1,mid+1,r);

}
void xuly1()
{
    scanf("%d%d",&u,&v);
    update(1,1,n);
    for (int i=1; i<=2*n; i++) printf("%d ",f[i]); printf("\n");
}
void xuly2()
{
    scanf("%d%d",&u,&v);
    res=0;
    visit(1,1,n);
    printf("%d\n",res);
}
int main()
{  freopen("lites.inp","r",stdin);
   freopen("lites.out","w",stdout);
   memset(b,false,sizeof(b));
   scanf("%d%d",&n,&m);
   for (int i=1; i<=m; i++){
     int loai;
     scanf("%d",&loai);
     //printf("%d\n",loai);
     if (loai==0) xuly1();
     else xuly2();
   }

   return 0;
}
