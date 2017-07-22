#include <bits/stdc++.h>
const long N = 100+10;
using namespace std;
int n,a[N],res=0;
int main()
{   //freopen("TILE.inp","r",stdin);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++) {
        if ( a[i] >= res ) ++res;
    }
    cout<<res;
}
