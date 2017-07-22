#include <bits/stdc++.h>

using namespace std;

const long N = 300 + 10;
const long long oo = 1000000000 + 10;
typedef long long LL;

int n, k;
LL c[N];
LL f[N][N];

LL calc(LL c,LL k)
{
    LL x = (c-1) / k;
    return ( x*(c*c - c) - c*k*(x+1)*x + k*k*x*(x+1)*(2*x+1) / 6 + k*x*(x+1)/2 ) / 2 ;
}


int main()
{
        freopen("TRAFFIC.inp","r",stdin);
        freopen("TRAFFIC.out","w",stdout);

        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> c[i];

        for (int i = 1; i <= n; i++)
            for (int j = i; j <= k; j++)
            {
                f[i][j] = oo*oo;
                for (int jj = i-1; jj < j; jj++)
                    f[i][j] = min(f[i][j],f[i-1][jj] + calc(c[i],j-jj));
            }

        cout << f[n][k];
}
