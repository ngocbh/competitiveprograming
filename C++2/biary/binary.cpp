#include <fstream>
#include <stdio.h>

using namespace std;
const long maxn=30000+100;
int t,n,a[maxn],f0[maxn],f1[maxn],res=0;
void xuly()
{
    scanf("%d",&n);
    res=0;
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);

    for (int i=1; i<=n; i++)
        {if (a[i]==0) f0[i]=f0[i-1]+1; else f0[i]=f0[i-1];
         if (a[i]==1)  f1[i]=f1[i-1]+1; else f1[i]=f1[i-1];}
    //for (int i=1; i<=n; i++) printf("%d ",f0[i]);
    for (int i=0; i<=n-1; i++)
        for (int j=i+1; j<=n; j++)
            if ((f1[j]-f1[i])==(f0[j]-f0[i])) {
                if ((j-i) >res ) res=j-i;
            }
printf("%d\n",res);

}
int main()
{   //freopen("binary.inp","r",stdin);
    //freopen("binary.out","w",stdout);
    scanf("%d",&t);
    for (int i=1;i<=t; i++) xuly();

}
