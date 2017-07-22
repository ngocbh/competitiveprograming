#include <iostream>
#include <memory.h>
#include <cmath>
#include <stdio.h>
#define maxn 100000+100
#define oo 1000000000+7
using namespace std;
int n,a[maxn],ca[maxn],kq[maxn],ss=0,se=0,cc[maxn],f[maxn];
int64_t res=1;
void ssnt()
{
    int nn=maxn-100;
    memset(ca,0,sizeof(ca));
    ca[1]=-1;
    for (int i=1; i<=nn; i++)
        if (ca[i]!=-1)
            for (int j=2; i*j<=nn; j++) ca[i*j]=-1;
    ///==============
            int ll=0;
    for (int i=1; i<=n; i++)
        if (ca[i]) cc[++ll]=i;
              for (int i=1; i<=100000; i++) if (ca[i]>0)cout<<ca[i]<<" ";

}
void dfs(int u)
{   ca[u]=false;
    ++ss;
    if (ca[a[u]]) dfs(a[u]);
}
int main()
{
    freopen("farm.inp","r",stdin);
    freopen("farm.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    memset(ca,true,sizeof(ca));
    for (int i=1; i<=n; i++)
        if (ca[i]){
            ss=0;
            dfs(i);
            kq[++se]=ss;
        }
    memset(ca,0,sizeof(ca));
    for (int i=1; i<=se; i++){
        int nn=kq[i],cnn;
        cnn=(int) sqrt(nn);
        for (int j=2 ;j<= cnn; j++ )
            if (nn % j==0 ){
                int cs=0;
                while ( nn % j ==0 ){
                    ++cs;
                    nn=nn/j;

                }
                if (cs>ca[j]) ca[j]=cs;
            }
         if (nn>0 && ca[nn]==0) ca[nn]=1;
    }
       for (int i=1; i<=100000; i++)
        if (ca[i]>0){
            for (int j=1; j<=ca[i]; j++) res=(res*i) % 1000000007;
        }
        cout<<res<<endl;
       // for (int i=1; i<=se; i++) cout<<kq[i]<<" "; cout<<endl;
      //  for (int i=1; i<=100000; i++) if (ca[i]>0) cout<<ca[i]<<" "<<i<<endl;

}
