#include <bits/stdc++.h>

const long N = 100000;
using namespace std;

int n, a[N];
string s;

int main()
{   //freopen("ROMAN.inp","r",stdin);
    cin >> s; n = s.size();

    a['I'] = 1;         a['I'*'V' + 'V'] = 4;
    a['V'] = 5;         a['I'*'X' + 'X'] = 9;
    a['X'] = 10;        a['X'*'L' + 'L'] = 40;
    a['L'] = 50;        a['X'*'C' + 'C'] = 90;
    a['C'] = 100;       a['C'*'D' + 'D'] = 400;
    a['D'] = 500;       a['C'*'M' + 'M'] = 900;
    a['M'] = 1000;


    int ans = 0, inci = 1;
    for (int i = 0; i < n; i += inci) {
        if ( a[s[i]*s[i+1]+s[i+1]] ) ans += a[s[i]*s[i+1]+s[i+1]] , inci = 2;
        else ans += a[s[i]];
    }
    cout << ans ;
}
