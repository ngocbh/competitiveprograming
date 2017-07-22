#include <bits/stdc++.h>
const long N = 1000000 + 10;
using namespace std;

int a[N],n;
int64_t d1[N],d0[N];
int main()
{   //afreopen("LINEGAME.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i = 1; i <= n; i++) cin>>a[i];
    for (int i = 1; i <= n; i++)  {
        d1[i] = max( d1[i-1] , d0[i-1] + a[i]);
        d0[i] = max( d0[i-1] , d1[i-1] - a[i]);
    }
    cout<<max(d1[n],d0[n]);
}
