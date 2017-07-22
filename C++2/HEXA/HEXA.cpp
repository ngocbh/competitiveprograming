/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 30000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

LL n;
char c[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
LL pow16[16];
string s;

string calc(LL n)
{
    string s1 = "";
    while ( n > 0 ) {
        s1 = c[n%16] + s1;
        n /= 16;
    }
    return s1;
}

void solve_sub1()
{
    s = "0";

    int i = 1;

    while ( true ) {
        if ( s.size() - 1 >= n ) {
            cout << s[n];
            return;
        }
        s += calc(i);
        ++i;
    }
}

void solve_sub2()
{
    pow16[0] = 1;
    for (int i = 1; i <= 10; i++) pow16[i] = pow16[i-1]*16;

    LL res = n - 1;
    int l = 1;
    while ( res - pow16[l-1]*l*15 > 0  ) res -= pow16[l-1]*l*15, ++l;

    //cout << res << endl;

    LL x = res / l;
    int y = res % l;
    //cout << res << " " << l << " " << x << " " << y << " " << pow16[l-1] + x << endl;
    string s = calc(pow16[l-1] + x );
    cout << s[y];
}

int main()
{
    freopen("HEXA.inp","r",stdin);
    //freopen("HEXA.out","w",stdout);

    cin >> n;

    if ( n <= 30000 ) {
        solve_sub1();
        //cout << s << endl;
        return 0;
    }

    solve_sub2();
}
