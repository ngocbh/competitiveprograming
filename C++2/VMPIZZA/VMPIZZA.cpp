#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int n , B;
int t[N], a[N], b[N];
LL dp[N], suma[N], sumb[N], sumbt[N];
int st[N];
int st_size;
bool check(int i1,int i2,int i3)
{
    /*double cx = 1.0 * ((dp[i2] - suma[i2] + sumbt[i2]) - (dp[i1] - suma[i1] + sumbt[i1])) / ( sumb[i1] - sumb[i2] );
    double cy = 1.0 * ((dp[i3] - suma[i3] + sumbt[i3]) - (dp[i1] - suma[i1] + sumbt[i1])) / ( sumb[i1] - sumb[i3] );
    return ( cy <= cx );*/
    LL cx, cy;
    cx =  ((dp[i2] - suma[i2] + sumbt[i2]) - 1LL * (dp[i1] - suma[i1] + sumbt[i1])) * ( sumb[i1] - sumb[i3] );
    cy =  ((dp[i3] - suma[i3] + sumbt[i3]) - 1LL * (dp[i1] - suma[i1] + sumbt[i1])) * ( sumb[i1] - sumb[i2] );
    return cy <= cx;
}
void add(int x)
{
    while ( st_size > 2 && check(st[st_size],st[st_size-1],x) )
        --st_size;
    ++st_size;
    st[st_size] = x;
}
int get(int x)
{   int ans = 0;
    int l = 1, r = st_size, m;
    while ( l <= r ) {
        m = (l + r) >> 1;
        if ( m == 1 ) {
            if (  ((dp[m] - suma[m] + sumbt[m]) - (dp[m-1] - suma[m-1] + sumbt[m-1])) <=  1LL * x * ( sumb[m] - sumb[m-1] ) ) {
             ans = m;
            }
            l = m + 1;
            continue;
        }
        if (  ((dp[m] - suma[m] + sumbt[m]) - (dp[m-1] - suma[m-1] + sumbt[m-1])) <=  1LL * x * ( sumb[m] - sumb[m-1] ) ) {
             l = m + 1;
             ans = m;
        }
        else r = m - 1;
    }
    return st[ans];
}
int main()
{       freopen("VMPIZZA.inp","r",stdin);
        scanf("%d %d", &n, &B);
        for (int i = 1; i <= n; i++) {
                scanf("%d %d %d ", &t[i], &a[i], &b[i]);
        }
        for (int i = 1; i <= n; i++) {
                suma[i] = suma[i-1] + a[i];
                sumb[i] = sumb[i-1] + b[i];
                sumbt[i] = sumbt[i-1] + 1LL * b[i] * t[i];
        }
        for (int i = 1; i <= n; i++) {
                cout << suma[i] << " " << sumb[i] << " " << sumbt[i] << endl;
        }
        dp[0] = 0;
        st[++st_size] = 0;
        for (int i = 1; i <= n; i++) {
                int j = get(t[i]);
                dp[i] = dp[j] + suma[i] - suma[j] - 1LL * t[i]*sumb[i] + sumbt[i] - sumbt[j] + 1LL * t[i] * sumb[j] - B;
                add(i);
        }
        cout << dp[n];

}
