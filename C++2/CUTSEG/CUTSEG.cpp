/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 200 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m;
int a[N], t[N];
LL f[N][N];
string s;

LL calc(int x,int y)
{
    if ( x > y ) return 0;
    if ( f[x][y] ) return f[x][y];
    if ( x == y ) return f[x][y] = t[x]*t[x];

    int dy = 0, sum = 0, prev = y;
    LL res = calc(x,y-1) + t[y]*t[y];

    dy = t[y];

    for (int i = y-1; i >= x; i--) {
        if ( a[i] == a[y] ) {
            dy += t[i];
            sum += calc(i+1,prev-1);
            res = max(res,calc(x,i-1) + dy*dy + sum);
            prev = i;
        }
    }

    if ( a[x] == a[y] ) res = max(res,calc(x+1,y-1) + (t[x] + t[y])*(t[x] + t[y]) );

    f[x][y] = res;

    return res;
}

int main()
{
    freopen("CUTSEG.inp","r",stdin);
    freopen("CUTSEG.out","w",stdout);

    cin >> n;
    cin >> s;
    s = 'a' + s + 'a';
    int cur = 0;

    for (int i = 1; i <= n+1; i++) {
        if ( s[i] != s[i-1] ) {
            a[m] = s[i-1] - '0';
            t[m] = cur;
            ++m;
            cur = 1;
        }
        else {
            ++cur;
        }
    }
    m--;
    n = m;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            calc(i,j);

    LL ans = f[1][n];

    cout << ans;

}
