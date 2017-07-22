#include <bits/stdc++.h>
const long N = 100000 + 10;
using namespace std;
typedef pair<int,int> ii;
int n,l[N],d[N],sc, ans, snl;
ii a[N];
bool cmp(int i,int j)
{
    return l[i] < l[j];
}
int main()
{   freopen("C.inp","r",stdin);
    cin>>n;
    for (int i = 1; i <= n; i++) cin>>a[i].first;
    for (int i = 1; i <= n; i++) cin>>a[i].second;
    sort(a+1,a+n+1);
    for (int i = n; i > 0; i--) {
        if ( a[i].first != a[i+1].first ) {
                if ( sc > n/2 ) { cout<<ans; return 0; }
                ans += snl;
                sc = 1;
                snl += a[i].second;
        } else {++sc;
        snl += a[i].second;
        }
    }
    cout<<n;
}
