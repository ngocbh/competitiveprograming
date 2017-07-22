#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
int n, t, k;
string s1, s2;
int main()
{   //freopen("E.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        cin >> k >> s1 >> s2;
        map<char,int> m;
        m.clear();
        int x = 0;
        for (int i = 0; i < s1.size(); i++) {
            if ( !m[s1[i]] )
                m[s1[i]] = 1, ++x;
        }

        for (int i = 0; i < s2.size(); i++) {
            if ( x == 0 ) break;
            if ( m[s2[i]] != 0 ) m[s2[i]] = 0,--x;
            else --k;
        }

        if ( k <= 0 || x != 0 ) cout << "Wrong" << endl;
        else cout << "Correct" << endl;
    }

}
