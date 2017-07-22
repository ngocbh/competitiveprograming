#include <bits/stdc++.h>

using namespace std;
const long maxn=500000+100;
int n,a[maxn],sum,c[maxn],st[maxn],top;
int main()
{  freopen("patrik.inp","r",stdin);
   freopen("patrik.out","w",stdout);
   scanf("%d",&n);
   for (int i=1; i<=n; i++) scanf("%d",&a[i]);
   //==========================
   top=0;
   for (int i=1; i<=n; i++){
        while (a[i]>st[top] && top>0 ) {
            sum+=c[top] ;
            --top;
        }
       if (a[i]==st[top]){
            if (top>1) ++sum;
            sum+=c[top];
            ++c[top];
        }
        else
        {
            if (top>0) ++sum;
            ++top;
            st[top]=a[i];
            c[top]=1;
        }
  }
   printf("%d",sum);
}
