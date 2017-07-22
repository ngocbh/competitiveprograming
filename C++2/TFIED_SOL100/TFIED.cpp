#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef long long LL;
typedef pair <double,int> ii;
struct point{
    int x,y;
};
int n, m, K;
int c[N], ca[N][N];
point P[N];
ii a[N];

double area(int m)
{
    double c = 0;
    for (int i = 1; i <= m; i++) {
         c += (double) (P[i].x - P[i+1].x) * (P[i].y + P[i+1].y);
    }
    return (abs(c)/2);
}

bool cmp(ii A,ii B)
{
    return A.first < B.first;
}

int main()
{
   // freopen("TFIED.inp","r",stdin);
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &m, &a[i].second);
        for (int j = 1; j <= m; j++) {
            scanf("%d%d", &P[j].x, &P[j].y);
        }
        P[m+1] = P[1];
        a[i].first = area(m);
    }
    sort(a+1,a+n+1,cmp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
                if ( a[i].second == j ) ca[i][j] = ca[i-1][j] + 1;
                else ca[i][j] = ca[i-1][j];
        }
    int ci = 1, inci = 1, incj = 0;
    double ans = 0;
    //for (int i = 1; i <= n; i++) cout << a[i].first << " " << a[i].second << endl;
    for (int i = 1; i <= n; i+= inci,ci+= incj )
    {
            LL MAX = -1, cj;
            for (int j = 1; j <= n; j++) {
                if ( ca[i][j] - ca[ci-1][j] > MAX ) {
                    MAX = ca[i][j] - ca[ci-1][j];
                    cj = j;
                }
            }
            if ( i - ci + 1 - MAX <= K ) {
                    ans = max(ans , a[i].first - a[ci-1].first);
                    inci = 1, incj = 0;
            } else {
                    inci = 0, incj = 1;
            }
    }
    printf("%0.1f", ans);
}
