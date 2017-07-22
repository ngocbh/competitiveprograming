/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, x, y, p, q, _forward, _behind;
string s;
map <ii,int> M;

int main()
{
    freopen("LINUXIAD.inp","r",stdin);
    //freopen("LINUXIAD.out","w",stdout);

    cin >> n >> x >> y >> p >> q;

    cin >> s;
    s = '0' + s;

    int numbers_of_white = 0, numbers_of_black = 0;
    M[ ii(numbers_of_white % p,numbers_of_black % q) ] = n+1;

    for (int i = n; i > 0; i--)
    {
        if ( s[i] == 'B' )
        {
            ++numbers_of_black;
            if ( !M[ ii(numbers_of_white % p,numbers_of_black % q) ] )
                    M[ ii(numbers_of_white % p,numbers_of_black % q) ] = i;
        }
        else
        {
            ++numbers_of_white;
            if ( !M[ ii(numbers_of_white % p , numbers_of_black % q) ] )
                    M[ ii(numbers_of_white % p , numbers_of_black % q) ] = i;
        }
    }

    int now = 0, nob = 0, w = numbers_of_white, b = numbers_of_black;

    for (int i = 1; i <= n; i++) {
        int o = M[ ii((w-now-y) % p,(b-nob-x) % q)];
        if ( o >= i && o - i > _behind - _forward + 1 && w-now-y >= 0 && b-nob-x  >= 0 ) {
            _behind = o-1;
            _forward = i;
        }

        if ( s[i] == 'B' ) {
            nob++;
        }
        else {
            now++;
        }
    }

    cout << _forward << " " << _behind;
    return 0;

}
