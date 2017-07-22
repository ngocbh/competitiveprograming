/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 3000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n;
LL a[N];
LL f[N][N];
bool ca[N][N];

LL calc(int i,int j)
{
    if ( i >= j ) return 0;
    if ( ca[i][j]) return f[i][j];
    ca[i][j] = 1;

    LL c = 0;
    c = max(c,calc(i+1,j-1) + a[i]*a[j]);

    f[i][j] = c;
    return c;
}

int main()
{
    //freopen("DAYSO10.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if ( n == 2 ) {
        cout << a[1]*a[2] ;
        return 0;
    }

    LL ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            ans = max(ans,calc(i,j));

    cout << ans;
}
