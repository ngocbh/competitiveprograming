#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int n, st_size;
int a[N], b[N];
int st[N];
LL dp[N];
bool check(int i1,int i2,int i3)
{
    double cx = 1.0 * (dp[i2] - dp[i1]) / (b[i1] - b[i2] );
    double cy = 1.0 * (dp[i3] - dp[i1]) / (b[i1] - b[i3] );
    return ( cy <= cx );
}
void add(int x)
{
    while ( st_size > 1 && check(st[st_size],st[st_size-1],x) )
            --st_size;
    st[++st_size] = x;
}
int get(int x)
{
    int ans = 0;
    int l = 1, r = st_size, m;
    while ( l + 1 < r ) {
            m = ( l + r ) >> 1;
            /*if ( m == 1 ) {
                ans = 1;
                l = m + 1;
                continue;
            }*/
            if ( dp[st[m]] - dp[st[m-1]] <= 1LL * x * ( - b[st[m]] + b[st[m-1]]) ) {
                    l = m;

            }
            else r = m;
    }
    return st[l];
}
int main()
{   //freopen("C.inp","r",stdin);
    //freopen("C.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
            scanf("%d ", &a[i]);
    for (int i = 1; i <= n; i++)
            scanf("%d ", &b[i]);
    st[++st_size] = 1;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
            int x;
            x = get(a[i]);
            dp[i] = dp[x] + 1LL * a[i]*b[x];
            add(i);
    }
    cout << dp[n] << endl;
}
