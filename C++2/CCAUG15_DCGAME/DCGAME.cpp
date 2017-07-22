#include <bits/stdc++.h>

const long N = 1000000 + 10;
const long long oo = 1000000000 + 7000;
using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;
int n , m, scs = 0;
LL a[N], l[N], r[N], cs[N];
LL ct[N];
ii f[N], cf[N];
void find_l()
{
    stack <int> s;
    s.push(0);
    for (int i = 1; i <= n; i++) {
        while ( a[s.top()] < a[i] ) s.pop();
        l[i] = s.top();
        s.push(i);
    }
}
void find_r()
{
    stack <int> s;
    s.push(n+1);
    for (int i = n; i > 0; i--) {
        while  ( a[s.top()] <= a[i] ) s.pop();
        r[i] = s.top();
        s.push(i);
    }
}
bool cmp(ii x,ii y)
{
    return a[x.first] < a[y.first];
}
int binarysearch(int x)
{
    int l = 0, r = scs, m, ans = 0;
    while ( l <= r ) {
        m = (l + r ) / 2;
        if ( f[m].first <= x ) {
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return ans;
}
void solve()
{
    find_l();
    find_r();
    for (int i = 1; i <= n; i++)
        cf[i].second = 1LL * ( i - l[i] ) * ( r[i] - i ) , cf[i].first = a[i];
    sort(cf+1,cf+n+1);
    for (int i = 1; i <= n; i++) {
        if ( cf[i].first != cf[i-1].first ) {
            f[++scs].first = cf[i].first;
            f[scs].second = cf[i].second;
        }
        else f[scs].second += cf[i].second;
    }

    for (int i = 1; i <= scs; i++)
        ct[i] = ct[i-1] + f[i].second;
    //for (int i = 1; i <= scs; i++) cout << f[i].first << " " << f[i].second <<  " " << ct[i] << endl;
    for (int i = 1; i <= m; i++) {
        int x, ci;
        char c,C;
        //scanf("%c %d %c", &c, &x, &C);
        cin >> c >> x >> C;
        LL res = 0;
        ci = binarysearch(x);
        if ( c == '=' ) {
            if ( f[ci].first == x ) res = f[ci].second;
            if ( res % 2 == 0 ) C = (char) ('C' + 'D' - C ) ;
            cout << C;
        }
        if ( c == '>' ) {
            res = ct[scs] - ct[ci];
            if ( res % 2 == 0 ) C = (char) ('C' + 'D' - C ) ;
            cout << C;
        }
        if ( c == '<' ) {
            if ( f[ci].first == x ) --ci;
            res = ct[ci];
            if ( res % 2 == 0 ) C = (char) ('C' + 'D' - C ) ;
            cout << C;
        }
    }
}
int main()
{
    //freopen("DCGAME.inp","r",stdin);
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[n+1] = oo;
    solve();
}


/*
void solve_sub1()
{
    for (int i = 1; i <= n; i++) {
        int it = i-1;
        while ( a[it] < a[i] ) --it;
        l[i] = it;
        it = i+1;
        while ( a[it] <= a[i] ) ++it;
        r[i] = it;
    }
    for (int i = 1; i <= n; i++) {
        cf[i].second = 1LL * ( i - l[i] ) * ( r[i] - i ) ;
        cf[i].first = a[i];
    }
    cf[0].first = -1;
    sort(cf,cf+n+1);

    for (int i = 1; i <= n; i++) {
        if ( cf[i].first != cf[i-1].first ) {
            f[++scs].first = cf[i].first;
            f[scs].second = cf[i].second;
        }
        else f[scs].second += cf[i].second;
    }
    for (int i = 1; i <= scs; i++)
        ct[i] = ct[i-1] + f[i].second;
    //for (int i = 1; i <= scs; i++) cout << f[i].first << " " << f[i].second <<  " " << ct[i] << endl;
    for (int i = 1; i <= m; i++) {
        int x,ci = 0;
        char c,C;
        cin >> c >> x >> C;
        for (int i = 1; i <= n; i++)
            if ( f[i].first > x ) {
                break;
            }
            else ci = i;
        LL res = 0;
        if ( c == '=' ) {
            if ( f[ci].first == x ) res = f[ci].second;
            if ( res % 2 == 0 ) C = (char) ('C' + 'D' - C ) ;
            cout << C;
        }
        if ( c == '>' ) {
            res = ct[scs] - ct[ci];
            if ( res % 2 == 0 ) C = (char) ('C' + 'D' - C ) ;
            cout << C;
        }
        if ( c == '<' ) {
            if ( f[ci].first == x ) --ci;
            res = ct[ci];
            if ( res % 2 == 0 ) C = (char) ('C' + 'D' - C ) ;
            cout << C;
        }
    }
}
*/
