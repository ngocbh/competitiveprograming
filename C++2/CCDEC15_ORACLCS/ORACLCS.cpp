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
string s;

int main()
{
    //freopen("ORACLCS.inp","r",stdin);
    //freopen("ORACLCS.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    cin >> t;
    while ( t-- ) {
        cin >> n;
        int _mina = oo, _minb = oo;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            int sa = 0, sb = 0;
            for (int j = 0; j < s.size(); j++)
                if ( s[j] == 'a' ) ++sa;
                else ++sb;
            _mina = min(_mina,sa);
            _minb = min(_minb,sb);
        }
        cout << min(_mina,_minb) << endl;
    }

}
