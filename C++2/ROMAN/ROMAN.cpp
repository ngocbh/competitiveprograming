#include <bits/stdc++.h>

const long N = 30000;
using namespace std;
int a[N];
int ans;
string s;
int main()
{  // freopen("ROMAN.inp","r",stdin);
    cin >> s;
    a['I'] = 1;         a['I'*'V'+'I'] = 4;
    a['V'] = 5;         a['I'*'X'+'I'] = 9;
    a['X'] = 10;        a['X'*'L'+'X'] = 40;
    a['L'] = 50;        a['X'*'C'+'X'] = 90;
    a['C'] = 100;       a['C'*'D'+'C'] = 400;
    a['D'] = 500;       a['C'*'M'+'C'] = 900;
    a['M'] = 1000;
    ans = 0;
    int ii = 1;
    for (int i = 0; i < s.size(); i += ii) {

            if ( i < s.size() - 1 )
            if ( a[s[i]*s[i+1]+s[i]] != 0 ) {
                    ii = 2;
                    ans += a[s[i]*s[i+1]+s[i]];
                    continue;
            }

            ans += a[s[i]];
            ii = 1;

    }
    cout << ans ;
}
