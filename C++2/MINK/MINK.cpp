/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 20000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int t, n, k;
int a[N], res[N];

int main()
{
    //freopen("MINK.inp","r",stdin);
    //freopen("MINK.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while ( t-- ) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];

        deque <ii> s;

        for (int i = 1; i <= n; i++) {
            while ( !s.empty() && s.back().first > a[i] )
                s.pop_back();
            s.push_back(ii(a[i],i));
            if ( s.front().second < i-k+1 )
                s.pop_front();
            res[i] = s.front().first;
        }

        for (int i = k; i <= n; i++) cout << res[i] << " ";
        cout << endl;

    }

}
