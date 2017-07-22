#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <stack>
#define maxn 1000000+1000
#define maxa 1000000000+100+10+1
using namespace std;
int n,k,a[maxn],res,min1,max1,f1[8*maxn],f2[8*maxn],u,v,nho;
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
void visit(int k,int l,int r,int u,int v)
{
    if (l>v || r<u) return;
    if (l>=u && r<=v){
        if (f1[k]>max1) max1=f1[k];
        if (f2[k]<min1) min1=f2[k];
        return;
    }
    int mid;
    mid=(l+r)/2;
    visit(2*k,l,mid,u,v);
    visit(2*k+1,mid+1,r,u,v);
}

int main()
{   freopen("cin.inp","r",stdin);
    freopen("cout.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=1; i<=n ;i++) scanf("%d",&a[i]);
    int j=1,cc=1;; nho=1; a[n+1]=15*maxa/10;
    build(1,1,n);
    int ii,jjj;
    while (true){
    for (int i=nho; i<=n+1; i++){
        max1=-maxa;
        min1=maxa;
        visit(1,1,n,j,i);
        if ( max1-min1>k ){
            res=max( res,i-j );
            if (res==i-j) {
                ii=i-1;
                jjj=j;
            }
            ++j;
            nho=i;
            break;
        }
        cc=i;
    }
    if ( cc==n+1 ) {res=max(res,n+1-j);
     break;}
    }
   // if (res==0) cout<<n<<endl; else
    cout<<res<<endl;
    cout<<ii<<" "<<jjj;
   /* res=0;
    for (int i=1; i<=n; i++)
    for (int j=i; j<=n; j++){
        max1=-maxa;
        min1=maxa;
        visit(1,1,n,i,j);
        if ( max1-min1<=k ){
            res=max( res,j-i+1 );
        }
    }
    cout<<res;*/

}
