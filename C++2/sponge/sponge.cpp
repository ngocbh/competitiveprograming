#include <bits/stdc++.h>

using namespace std;
const long long maxn=500000+100;
int n,a[maxn],kq=0,sum=0;
priority_queue <int,vector<int>,greater<int> > qu;
int main()
{  freopen("sponge.inp","r",stdin);
   freopen("sponge.out","w",stdout);
   scanf("%d",&n);
   for (int i=1; i<=n; i++) {scanf("%d",&a[i]);sum+=a[i];}
   //printf("%d",n);
   ///========================================
   for (int i=1; i<=n; i++)
        if (qu.empty()) qu.push(a[i]);
        else {
            int x;
            x=qu.top();
            qu.pop();
            qu.push(2*x);
            qu.push(a[i]);
            kq+=x;
            //printf("%d ",x);
            //kq+=a[i];
        }
   printf("%d",kq);
   return 0;
}
