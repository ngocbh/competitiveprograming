#include <bits/stdc++.h>

using namespace std;
const long maxn=500000+100;
int n,a[maxn],l[maxn],r[maxn];
long long kq=0;
int main()
{  freopen("patrik.inp","r",stdin);
   freopen("patrik.out","w",stdout);
   scanf("%d",&n);
   fill(a+0,a+n+1000,1000000000);
   for (int i=1; i<=n; i++) scanf("%d",&a[i]);
   //=====================================
    for (int i=n;i>=1;i--) {
            int j=i;
            int max1=100000000;
            while (a[j]<=max1) { max1=a[j];++j;}
            r[i]=j;
    }
   ///====================================
    for (int i=1; i<=n; i++){printf("%d ",r[i]);} printf("\n");
    //for (int i=1; i<=n; i++){printf("%d ",l[i]);}printf("\n");
    ///======================================
    for (int i=1; i<=n-1; i++)
    if (r[i]==n+1) kq+=r[i]-i-1;
    else
    kq+=r[i]-i;
    printf("%d ",kq);

}
