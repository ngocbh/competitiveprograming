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

int n;
int a[N];
map <ii,int> M;

int main()
{
    //freopen("B.inp","r",stdin);
    //freopen("B.out","w",stdout);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int prev = 1;

    int ans = 0;

    map <ii,int> ::iterator ic, id;
    int ax, ay;

    for (int i = 1; i <= n; i++) {
        M[ii(a[i],i)] = 1;
        id = M.begin();
        ic = M.end();
        --ic;

        ax = id->first.first;
        ay = ic->first.first;
        if ( abs(ay - ax) < 2 ) {
            ans = max(ans,i-prev+1);
            continue;
        }

        while ( true ) {
            M.erase(ii(a[prev],prev));

            ++prev;
            id = M.begin();
            ic = M.end();
            --ic;

            ax = id->first.first;
            ay = ic->first.first;

            if ( abs(ay - ax) < 2 ) {
                ans = max(ans,i-prev+1);
                break;
            }
        }
    }

    cout << ans;
}
