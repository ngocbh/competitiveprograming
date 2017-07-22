/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, a[N];

int main()
{
    //freopen("MINDROP.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int cur = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if ( a[i] != a[i-1] ) {
            ans = max(ans,cur);
            cur = 1;
        }
        else ++ cur;
    }

    cout << n-ans;

}
