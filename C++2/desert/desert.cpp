#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#define maxn 5000+100
using namespace std;
int n,x[maxn],y[maxn],f[maxn],ta[maxn],res=10000000000,kq[maxn],ca[maxn];
int ln(int i,int j)
{
    return ( abs(x[i]-x[j]) + abs( y[i]-y[j] ) );
}
int main()
{
    freopen("desert.inp","r",stdin);
    freopen("desert.out","w",stdout);

    cin>>n;
    fill(f,f+n+1,100000000+100+7);
    f[1]=0;
    for (int i=1; i<=n ;i++) cin>>x[i]>>y[i];
    for (int j=1; j<=n; j++){
        for (int i=2; i<=n; i++) {
            if (f[i] > max(f[j],ln(i,j)))
            {
                f[i]=max(f[j],ln(i,j));

            }

        }
    }
    for (int i=1; i<=n; i++) cout<<f[i]<<" ";
    cout<<endl;
    int ss=0,res=0,nn;
   cout<<f[n]<<endl;
   memset(ca,true,sizeof(ca));
   ca[n]=false;
   nn=n;
   while (nn!=1){
    int nho;
   for (int i=1; i<=n; i++)
      if (ca[i] && (ln(nn,i)<=f[n]) && f[i]<=f[n]) {
        ca[i]=false;
        nho=i;
        break;
      }
    nn=nho;
    kq[++ss]=nn;

   }
   for (int i=ss; i>=1; i--) cout<<kq[i]<<" ";
   cout<<n;


}
