#include <bits/stdc++.h>

const long N = 20 + 1;
const long long inf = 100000000 + 7;
using namespace std;
typedef pair <int,int> ii;
typedef long long LL;

int n, m, k;
int a[N][N], ca[N], cb[N], x[N], ans = inf, sum , sl[N], dem, res[N], resdem, ressl[N];

void ktkq()
{
    if ( sum >= ans ) return;
    ans = sum;
    for (int i = 1; i <= n-2; i++) res[i] = x[i];
    resdem = dem;
    for (int i = 1; i <= dem; i++) ressl[i] = sl[i];
}

void tach(int i)
{
    if ( i > n - 2 ) {
        ktkq();
        return;
    }

    int p = 1, t = 0;
    for (int j = i; j <= min(n-2,i+k-1); j++) {
        t += a[p][x[j]];
        p = x[j];
        ++dem;
        sl[dem] = j-i+1;
        sum += (t+a[x[j]][2]);
        tach(j+1);
        dem--;
        sum -= (t+a[x[j]][2]);
    }

}

void duyet(int i)
{
    if ( i > n-2 ) {
        tach(1);
        return;
    }
    for (int j = 3; j <= n; j++) {
        if ( !ca[j] ) continue;
        x[i] = j;
        ca[j] = false;
        duyet(i+1);
        ca[j] = true;
    }
}

int main()
{   freopen("OPNET.inp","r",stdin);
    freopen("OPNET.out","w",stdout);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = inf;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] = c;
        a[v][u] = c;
    }

    memset(ca,true,sizeof ca);
    duyet(1);

    int cur = 1;

    cout << ans << " " << resdem << endl;
    for (int i = 1; i <= resdem; i++) {
        cout << ressl[i]+2 << " ";
        cout << 1 << " ";
        for (int j = cur; j <= cur+ressl[i]-1; j++) cout << res[j] << " ";
        cur = cur+ressl[i];
        cout << 2;
        cout << endl;
    }
}
