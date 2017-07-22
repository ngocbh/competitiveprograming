#include <bits/stdc++.h>
#define x first
#define y second
const long N = 100000 + 10;
using namespace std;
typedef pair <int,int> ii;
int n,s,d;
int res;
ii a[N];
int main()
{  // freopen("DOANP2.inp","r",stdin);
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1); s = d = -1;
    for (int i = 1; i<= n; i++) {
        if ( a[i].x > d ) { res += a[i].y - a[i].x ; s = a[i].x; d = a[i].y; }
        if ( a[i].x > s && a[i].y < d ) continue;
        if ( a[i].x <= d && a[i].y > d ) { res += a[i].y - d; d = a[i].y; }
    }
    cout<<res;
}
