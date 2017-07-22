#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
int n, sz;
int res[N];
char s[N];
int main()
{   //freopen("D.inp","r",stdin);
    scanf("%s", s+1);
    n = strlen(s+1);

    int prev = n;
    s[0] = s[1] + 1;
    for (int i = n-1; i >= 0; i--) {
        if ( s[i] > s[i+1] ) res[++sz] = prev - i, prev = i;
    }

    cout << sz << " ";
    for (int i = sz; i > 0; i--)
        cout << res[i] << " ";

}
