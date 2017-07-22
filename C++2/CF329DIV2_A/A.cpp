/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n;
int f[N][100];
string a[N];

int main()
{
    //freopen("A.inp","r",stdin);
    //freopen("A.out","w",stdout);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i].size(); j++)
            f[i][a[i][j]]++;
    }

    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++)
        for (int j = 'a'; j <= 'z'; j++) {
            int res = 0;
            for (int o = 1; o <= n; o++)
                if ( f[o][i] + f[o][j] == a[o].size() )
                    res += a[o].size();
            ans = max(ans,res);
        }

    cout << ans;


}
