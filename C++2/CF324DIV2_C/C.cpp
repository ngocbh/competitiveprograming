#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, t;
int t1 = 0, t2 = 0;

int f[N];
string s1, s2;
char s[N];
char get(char c1, char c2)
{
    for (int i = 'a'; i <= 'z'; i++)
        if ( i != c1 && i != c2 )
            return (char) i;
}

int main()
{   //freopen("C.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> t;
    cin >> s1 >> s2;

    if ( t == 0 ) {
        if ( s1 == s2 ) cout << s1;
        else cout << -1;
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if ( s1[i] == s2[i] ) f[i] = 1, sum++;
        s[i] = '0';
    }

    int z = n-sum-t;
    if ( n-sum > t*2 ) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if ( f[i] == 0 ) {
            if ( z-t1 >= 1 ) {
                s[i] = s2[i];
                ++t1;
                continue;
            }
            if ( z-t2 >= 1 ) {
                s[i] = s1[i];
                ++t2;
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if ( f[i] == 0 && t-t1 >= 1 && t-t2 >= 1 && s[i] == '0' ) {
            s[i] = get(s1[i],s2[i]);
            ++t1, ++t2;
        }
    }

    for (int i = 0; i < n; i++) {
        if ( f[i] == 1 && t-t1 >= 1 && t-t2 >= 1 && s[i] == '0' ) {
            s[i] = get(s1[i],s2[i]);
            ++t1, ++t2;
        }
    }

    for (int i = 0; i < n; i++) {
        if ( s[i] == '0' ) {
            if ( s1[i] != s2[i] ) {
                cout << -1;
                return 0;
            }
            s[i] = s1[i];
        }
    }

    printf("%s", s);
}
