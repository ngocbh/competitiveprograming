#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
int n;
int ans[N][52];
string s;
int main()
{   //freopen("KARTE.inp","r",stdin);
    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i+=3) {
        int c = (s[i+1]-'0')*10 + s[i+2]-'0';
        if ( ans[s[i]][c] ) {
            cout << "GRESKA";
            return 0;
        }
        ans[s[i]][c] = 1;
        ++ans[s[i]][0];
    }
    cout << 13 - ans['P'][0] << " " << 13-ans['K'][0] << " " << 13-ans['H'][0] << " " << 13-ans['T'][0];
}
