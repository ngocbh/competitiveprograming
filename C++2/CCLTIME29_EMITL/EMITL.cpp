#include <bits/stdc++.h>

const long N = 1000;
using namespace std;
int n, t;
int a[N];
string s;
int main()
{   //freopen("EMITL.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        cin >> s;
        n = s.size();
        memset(a,0,sizeof a);
        for (int i = 0; i < s.size(); i++) a[s[i]]++;
        if ( n < 9 ) { cout << "NO" << endl; continue;}
        if ( n == 9 && a['L'] >= 2 && a['T'] >= 2 && a['I'] >= 2 && a['M'] >= 2 && a['E'] >= 1 ) { cout << "YES" << endl; continue; }
        if ( a['L'] >= 2 && a['T'] >= 2 && a['I'] >= 2 && a['M'] >= 2 && a['E'] >= 2 ) { cout << "YES" << endl; continue; }
        cout << "NO" << endl;
    }

}
