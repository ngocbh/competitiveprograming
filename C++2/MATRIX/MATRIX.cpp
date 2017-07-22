#include <bits/stdc++.h>

const long N = 500 + 10;
using namespace std;
typedef long long LL;
int n, m;
LL ans;
LL a[N][N], sum[N][N], cmax[N][N], cmin[N][N];
int main()
{       freopen("MATRIX.inp","r",stdin);
        freopen("MATRIX.out","w",stdout);
        scanf("%d %d", &n , &m );
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++) {
                        cin >> a[i][j];
                }
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                        sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
                }
        }
        ans = (- 1e9 - 7);
        for (int i = 1; i <= m; i++)
                for (int j = i; j <= m; j++) {
                        LL min1 = (1e9 + 7), max1 = -1e9 - 7;
                        for (int k = 0; k <= n; k++) {
                                ans = max(- sum[k][i-1] + sum[k][j] - min1, ans);
                                min1 = min(min1, - sum[k][i-1] + sum[k][j]);
                                //cout << i <<" "<< j << " "<< k <<" "<<min1<<" "<<ans<<endl;
                        }

                }
        cout << ans;

}
