#include <bits/stdc++.h>

const long N = 3*100000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
int n, p;
int a[N], b[N], d[N], cs[N], cf[N];
LL ans;
map <ii,int> MAP;
bool cmp(int i,int j)
{
    return d[i] < d[j];
}
int main()
{   //freopen("P156SUMA.inp","r",stdin);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if ( a[i] > b[i]) swap(a[i],b[i]);
        ++MAP[ii(a[i] , b[i])];
        ++d[a[i]];
        ++d[b[i]];
        cs[i] = i;
    }
    sort(cs+1,cs+n+1,cmp);
    sort(d+1,d+n+1);
    for (int i = 1; i <= n; i++) cf[cs[i]] = i;
    for (int i = 1; i <= n; i++) {
        int u,v = 0;
        u = p - d[i];
        v = lower_bound(d+1,d+n+1,u) - d;
        ans  += n - v + 1;
        if ( d[i] >= u ) --ans;
    }
    ans /= 2;
    for (int i = 1; i <= n; i++) {
        if ( d[ cf[ a[i]]] + d[cf[b[i]]] - MAP[ii(a[i] , b[i])] < p && d[cf[a[i]]] + d[cf[b[i]]] >= p ) {
                --ans;
        }
        MAP[ii(a[i],b[i])] = 0;
    }
    cout << ans;

}
