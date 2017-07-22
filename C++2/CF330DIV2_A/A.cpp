/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m;
int a[N][N];
int ans = 0;

int main()
{
    //freopen("A.inp","r",stdin);
    //freopen("A.out","w",stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 2*m; j++) {
            cin >> a[i][j];
            if ( j % 2 == 0 && a[i][j] + a[i][j-1] >= 1 ) {
                ++ans;
            }
        }

    cout << ans;


}
