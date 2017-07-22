/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef pair <int,int> ii;
typedef long long LL;

int n, t , m, k;
int ca[N], cut[N], a[N], kt[N];

bool check(int R)
{
   // cout << R << "&&&" << endl;

    memset(cut,0,sizeof cut);
    memset(kt,0,sizeof kt);

    map<ii,int> M;
    int ans = 0;
    int ncut = 0;

    for (int i = 1; i <= k; i++) {
        M[ii(a[i],-i)]++;
    }

    stack <int> s;
    s.push(0);

    for (int i = n; i > k; i--)
        s.push(a[i]);

    map<ii,int> :: iterator it;
    int I = k;
    int mcut = 0;

    while ( !s.empty() ) {
        if ( ans == R ) break;

        it = M.begin();
        int x = it->first.first;
        int e = M.size();

        // cout << I << " " << x << " " << e << " " << ncut << " " << mcut << endl;

        if ( x < ans + 1 && e > 0 && x != 0 ) {
            M.erase(it);
            ++mcut;
            continue;
        }

        if ( x == ans + 1 && e + mcut > ncut && e > 0 ) {
            ++ans;
            //cout << x << " " << it->first.second << "^^^" << endl;
            M.erase(it);
            continue;
        }

         if ( e - ncut + mcut >= k ) {
            cut[++ncut] = I;
            continue;
        }

        x = s.top();
        s.pop();
        //if ( x > ans )
            M[ii(x,(-(++I)))]++;
    }

    int m = 0;
    for (it = M.begin(); it != M.end(); it++) {
        kt[++m] = - it->first.second;
    }
    sort(kt+1,kt+m+1);
/*
    cout << R << " " << ans << endl;

    for (int i = 1; i <= m; i++) cout << kt[i] << " ";
    cout << endl;

    for (int i = 1; i <= ncut; i++) cout << cut[i] << " " ;
    cout << endl;
    cout << endl;
*/
    if ( ans < R ) return false;

    int j = 1;
    for (int i = 1; i <= ncut; i++) {
        if ( kt[j] <= cut[i] ) {
            ++j;
            continue;
        }
        return false;
    }

    return true;

}

void solve()
{

    int l = 1, r = 10, m, ans = 0;
    while ( l <= r ) {
        m = (l + r) / 2;
        if ( check(m) ) {
            l = m+1;
            ans = m;
        }
        else r = m-1;
    }
    cout << ans << endl;
}


int main()
{   freopen("CARDS.inp","r",stdin);
    freopen("CARDS.out","w",stdout);
    cin >> t;
    while ( t-- ) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        solve();
    }
}
