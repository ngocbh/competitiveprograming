/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <char,LL> ii;

LL n, K;
int ca[N];
char s[N];
ii b[N], a[N];

void solve_max()
{
    int I = 0;
    memset(ca,true,sizeof ca);
    LL k = K;
    stack <int> S;
    S.push(1);
    a[n+1].first = '{';
    for (int i = 2; i <= n+1; i++) {
        if ( k == 0 ) break;
        while ( !S.empty() ) {
            int prev = S.top();
            if ( a[prev].first < a[i].first ) {
                if ( k >= a[prev].second ) {
                    k -= a[prev].second;
                    a[prev].second = 0;
                    ca[prev] = false;
                    S.pop();
                }
                else {
                    a[prev].second -= k;
                    k = 0;
                    break;
                }
            }
            else    break;
        }
        S.push(i);
    }

    int rem = 0;
    for (int i = 1; i <= n; i++) if ( ca[i]) {
        rem = i;
        break;
    }

    for (int i = rem+1; i <= n; i++) {
        if ( !ca[i] ) continue;
        if ( a[i].first == a[rem].first )
            a[rem].second += a[i].second,ca[i] = false;
        else
            rem = i;
    }

    for (int i = 1; i <= n; i++)
        if ( ca[i] )
            cout << a[i].first << a[i].second;
    cout << endl;
}

void solve_min()
{

    int I = 0;
    memset(ca,true,sizeof ca);
    LL k = K;
    stack <int> S;
    S.push(1);
    a[n+1].first = '`';

    for (int i = 2; i <= n+1; i++) {
        if ( k == 0 ) break;
        while ( !S.empty() ) {
            int prev = S.top();
            if ( a[prev].first > a[i].first ) {
                if ( k >= a[prev].second ) {
                    k -= a[prev].second;
                    a[prev].second = 0;
                    ca[prev] = false;
                    S.pop();
                }
                else {
                    a[prev].second -= k;
                    k = 0;
                    break;
                }
            }
            else    break;
        }
        S.push(i);
    }

    int rem = 0;
    for (int i = 1; i <= n; i++) if ( ca[i]) {
        rem = i;
        break;
    }

    for (int i = rem+1; i <= n; i++) {
        if ( !ca[i] ) continue;
        if ( a[i].first == a[rem].first )
            a[rem].second += a[i].second,ca[i] = false;
        else
            rem = i;
    }

    for (int i = 1; i <= n; i++)
        if ( ca[i] )
            cout << a[i].first << a[i].second;
    cout << endl;
}

int main()
{
    freopen("RLESTR3.inp","r",stdin);
    freopen("RLESTR3.out","w",stdout);

    cin >> K;

    scanf("%s", s+1);
    int nn = strlen(s+1);

    b[++n].first = s[1];
    LL rem = 0;
    for (int i = 2; i <= nn; i++) {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            b[n].second = rem, b[++n].first = s[i], rem = 0;
        else
            rem = rem*10 + s[i] - '0';
    }

    b[n].second = rem;

    for (int i = 1; i <= n; i++) a[i] = b[i];
    solve_max();
    for (int i = 1; i <= n; i++) a[i] = b[i];
    solve_min();

}
