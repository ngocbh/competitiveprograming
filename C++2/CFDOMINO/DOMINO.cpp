/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, k;
int a[N][N];

int main()
{
    freopen("DOMINO.inp","r",stdin);
    //freopen("DOMINO.out","w",stdout);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int mi = ((m+1)/2);
    int mask = (1 << mi) - 1;
    for (int i = 1; i <= n; i++) {
        for (int ki = 0; ki <= m*(i+1)/2; ki++)
            for (int x = 1; x <= mask; x++) {
                for (int j = j+1)
            }
    }
}
