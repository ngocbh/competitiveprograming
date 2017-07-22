#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef long long LL;

int n;
LL x[N], y[N];
LL f[N];
int MAX[N], MIN[N], cs[N];

bool cmp(int i,int j)
{
    return f[i] > f[j];
}

int main()
{   freopen("RANKING.inp","r",stdin);
    freopen("RANKING.out","w",stdout);

    cin >> n;
    LL _maxx = 0;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i], _maxx = max(_maxx,max(x[i],y[i])), MIN[i] = N;

    ++_maxx;
    for (int i = 1; i <= _maxx; i++) {
        for (int j = 1; j <= n; j++)
            f[j] = x[j]*i - y[j],cs[j] = j;
        sort(cs+1,cs+n+1,cmp);
        int t;

        for (int j = 1; j <= n; j++) {
            if ( f[cs[j]] != f[cs[j-1]] ) t = j;
            MAX[cs[j]] = max(MAX[cs[j]],t);
            MIN[cs[j]] = min(MIN[cs[j]],t);
        }
    }

    for (int i = 1; i <= _maxx; i++) {
        for (int j = 1; j <= n; j++)
            f[j] = x[j] - y[j]*i,cs[j] = j;
        sort(cs+1,cs+n+1,cmp);
        int t;
        for (int j = 1; j <= n; j++) {
            if ( f[cs[j]] != f[cs[j-1]] ) t = j;
            MAX[cs[j]] = max(MAX[cs[j]],t);
            MIN[cs[j]] = min(MIN[cs[j]],t);
        }
    }

    for (int i = 1; i <= n; i++) cout << MIN[i] << " " << MAX[i] << endl;

}
