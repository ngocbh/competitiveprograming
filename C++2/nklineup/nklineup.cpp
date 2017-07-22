#include <bits/stdc++.h>
#define maxn 50050
using namespace std;
int n,q,a[maxn],f1[4*maxn],f2[4*maxn],max1,min1,u,v;
void build(int k,int l,int r)
{
    if (l>r) return;
    if (l==r) { f1[k]=a[l];f2[k]=a[l]; return;}
    int mid;
    mid =(l+r)/2;
    build(2*k,l,mid);
    build(2*k+1,mid+1,r);
    f1[k]=max(f1[2*k],f1[2*k+1]);
    f2[k]=min(f2[2*k],f2[2*k+1]);
}
void visit(int k,int l,int r)
{
    if (l>v || r<u) return;
    if (l>=u && r<=v){
        if (f1[k]>max1) max1=f1[k];
        if (f2[k]<min1) min1=f2[k];
        return;
    }
    int mid;
    mid=(l+r)/2;
    visit(2*k,l,mid);
    visit(2*k+1,mid+1,r);
}
int main()
{  //freopen("nklineup.inp","r",stdin);
  // freopen("nklineup.out","w",stdout);
   scanf("%d%d",&n,&q);
   memset(f2,0,sizeof(f2));
   memset(f1,0,sizeof(f1));
   for (int i=1; i<=n; i++) scanf("%d",&a[i]);
   ///========================================
   build(1,1,n);
   for (int i=1; i<=q; i++){
       scanf("%d%d",&u,&v);
       max1=-1000000000;
       min1=1000000000;
       //printf("%d %d\n",u,v);
       visit(1,1,n);
       printf("%d\n",max1-min1);
   }

}
