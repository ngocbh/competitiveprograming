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

LL n, A, B, a[N], lad[N];
vector <int> res;
map <int,int> M, M2;

int main()
{
    //freopen("AGAR.inp","r",stdin);
    //freopen(".out","w",stdout);

    int x;
    ios::sync_with_stdio(0);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) cin >> a[i], M[a[i]]++, lad[i] = M2[a[i]], M2[a[i]] = i;

    int ans = 0;
    while ( true ) {

        if ( A > B ) {
            cout << ans << endl;
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << " ";
            return 0;
        }

        map<int,int> ::iterator it;
        it = M.lower_bound(A);
        if ( it == M.begin() ) break;
        --it;
        int  x =  it->first;
        ++ans;
        A += x;
        --M[x];
        if ( M[x] == 0 ) M.erase(x);
        int ci = M2[x];
        res.push_back(ci);
        M2[x] = lad[ci];
    }

    cout << -1;
    return 0;

}
