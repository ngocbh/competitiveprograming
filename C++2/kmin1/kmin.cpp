#include <bits/stdc++.h>

using namespace std;
const long maxn=50000+100;
int n,m,k,a[maxn],b[maxn];
typedef pair<int,int> p2;
typedef pair<int,p2>  p3;
priority_queue <p3,vector<p3>,greater<p3> > d;
int main()
{  freopen("kmin1.inp","r",stdin);
   freopen("kmin1.out","w",stdout);
   scanf("%d%d%d",&m,&n,&k);
   for (int i=1; i<=m; i++) scanf("%d",&a[i]);
   for (int i=1; i<=n; i++) scanf("%d",&b[i]);
   sort(a+1,a+m+1);
   sort(b+1,b+n+1);
   for (int i=1; i<=n; i++) d.push(a[1]+b[i]);
   for (int i=1; i<=k; i++){
   printf("%d",d.top());
   d.pop();
   }
}
