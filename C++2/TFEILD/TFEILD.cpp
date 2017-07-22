#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;

typedef long long LL;
typedef pair <LL,int> ii;
struct point{
    int x,y;
};

int n, m , k;
point P[N];
ii a[N];
int c[N][N], cf[N];

LL _abs(LL x )
{
    if ( x < 0 ) return -x;
    else return x;
}

LL area(int m)
{
    LL c = 0;
    for (int i = 1; i <= m; i++)
        c += 1LL * (P[i].x - P[i+1].x ) * (P[i].y + P[i+1].y);

    return _abs(c);
}

int main()
{
    //freopen("TFEILD.inp","r",stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &m, &a[i].second);

                for (int i = 1; i <= m; i++) {
                        scanf("%d %d" , &P[i].x, &P[i].y);
                }
                P[m+1] = P[1];
                a[i].first = area(m);
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                c[i][j] = c[i-1][j] + ( a[i].second == j );
            }

    int inci = 1, incj = 0, j = 0;
    LL ans = -1;

    for (int i = 1; i <= n; ++i)
    {
            int _max = 0;
            for (int j = i; j <= n; j++) {
                cf[a[i].second]++;
                _max = max(_max , cf[a[i].second]++);
                if ( i - j + 1 - _max <= k )
                    ans = max(ans , a[j].first - a[i-1].first);
            }
            for (int j = i; j <= n; j++)
                --cf[a[i].second];
    }
    if ( ans % 2 == 1 ) cout << ans / 2 << ".5";
    else cout << ans / 2 << ".0";

}
