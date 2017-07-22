/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

#define x first
#define t second
const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

int n, T;
ii a[N];
int main()
{
    freopen("CAKES.inp","r",stdin);
    //freopen("CAKES.out","w",stdout);

    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].t;

    sort(a+1,a+n+1);

    priority_queue <ii,vector<ii>,greater<ii> > qu;

    LL cur = a[1].x , ans = 0, TC = T;
    T -= a[1].x;
    a[n+1].x = oo+a[n].x;

    int i = 1;
    while ( i <= n ) {
        LL cx = oo, dt, an;
        if ( !qu.empty() ) cx = qu.top().first;
        an = a[i].t;
        dt = a[i+1].x - a[i].x;

        LL time = min(cx,min(an,dt));
        if ( time == oo ) break;
        if ( T < time ) break;

        if ( cx == time ) {
            T -= time;
            ++ans;
            TC = T;
            qu.pop();
            continue;
        }

        if ( an == time ) {
            T -= time;
            ++ans;
            TC = T;
            a[i].t = oo;
            continue;
        }

        if ( dt == time ) {
            T -= time;
            if ( a[i].t != oo ) qu.push(ii(a[i].t,a[i].x));
            ++i;
            continue;
        }

        break;
    }
    while ( !qu.empty() ) {
        int x = qu.top().first;
        qu.pop();
        if ( TC >= x ) {
            ans += 1;
            TC -= x;
        }
        else break;
    }
    cout << ans;
}
