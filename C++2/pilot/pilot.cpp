#include <bits/stdc++.h>

using namespace std;
const long maxn=10000+100;
int n,sum=0,a[maxn],b[maxn],nho=0,kq=0;
priority_queue <int,vector<int> > qu;
int main()
{ //freopen("pilot.inp","r",stdin);
  //freopen("pilot.out","w",stdout);
scanf("%d",&n);
  for (int i=1; i<=n; i++) scanf("%d%d",&a[i],&b[i]);
  ///==============
  for (int i=1; i<=n; i++){
    sum+=a[i];
    qu.push(a[i]-b[i]);
    if (i % 2==1) {
        kq+=qu.top();
        qu.pop();
        }
    }
    printf("%d",sum-kq);
}
