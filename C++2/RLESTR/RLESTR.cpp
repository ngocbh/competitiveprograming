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

int n, t, k, p, q, na, nb;
char s[N], X[N], Y[N];
ii a[N], b[N];
string type;

void solve1()
{
    cout << type << ": ";
    scanf("%s", s+1);
    int nn = strlen(s+1);

    na = nb = 0;

    a[++na].first = s[1];
    LL rem = 0;
    for (int i = 2; i <= nn; i++) {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            a[na].second = rem, a[++na].first = s[i], rem = 0;
        else
            rem = rem*10 + s[i] - '0';
    }

    a[na].second = rem;

    scanf("%s", s+1);
    nn = strlen(s+1);

    b[++nb].first = s[1];
    rem = 0;
    for (int i = 2; i <= nn; i++) {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            b[nb].second = rem, b[++nb].first = s[i], rem = 0;
        else
            rem = rem*10 + s[i] - '0';
    }

    b[nb].second = rem;

    if ( a[na].first == b[1].first ) {
        for (int i = 1; i <= na-1; i++) cout << a[i].first << a[i].second;
        cout << a[na].first << a[na].second + b[1].second;
        for (int i = 2; i <= nb; i++) cout << b[i].first << b[i].second;
        cout << endl;
        return;
    }

    for (int i = 1; i <= na; i++) cout << a[i].first << a[i].second;
    for (int i = 1; i <= nb; i++) cout << b[i].first << b[i].second;
    cout << endl;

}

void solve2()
{
    cout << type << ": ";
    scanf("%s", s+1);
    int c, p;
    cin >> p >> c;
    int nn = strlen(s+1);

    na = 0;
    a[++na].first = s[1];
    LL rem = 0;
    for (int i = 2; i <= nn; i++) {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            a[na].second = rem, a[++na].first = s[i], rem = 0;
        else
            rem = rem*10 + s[i] - '0';
    }

    a[na].second = rem;

    LL cur = 0;
    for (int i = 1; i <= na; i++) {
        cur += a[i].second;
        if ( cur < p ) {
            cout << a[i].first << a[i].second;
            continue;
        }
        if ( c <= 0 ) {
            cout << a[i].first << a[i].second;
            continue;
        }
        if ( cur >= p && cur - a[i].second < p ) {
            if ( p + c - 1 <= cur ) {
                if ( a[i].second - c > 0 )
                    cout << a[i].first << a[i].second - c;
                c = 0;
            }
            else {
                if (p - cur + a[i].second - 1 > 0 )
                cout << a[i].first << p - cur + a[i].second - 1;
                c -= a[i].second - (p - cur + a[i].second - 1);
            }
            continue;
        }
        if ( cur >= p + c ) {
            if ( cur - p - c - 1> 0 )
            cout << a[i].first << cur - p - c - 1;
            c = 0;
            continue;
        }
        c -= a[i].second;
    }
    cout << endl;
}

void solve3()
{
    cout << type << ": ";
    scanf("%s", s+1);
    int c, p;
    cin >> p >> c;
    int nn = strlen(s+1);

    na = 0;
    a[++na].first = s[1];
    LL rem = 0;
    for (int i = 2; i <= nn; i++) {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            a[na].second = rem, a[++na].first = s[i], rem = 0;
        else
            rem = rem*10 + s[i] - '0';
    }

    a[na].second = rem;

    LL cur = 0;
    for (int i = 1; i <= na; i++) {
        cur += a[i].second;
        if ( cur < p ) {
            continue;
        }
        if ( c <= 0 ) {
            continue;
        }
        if ( cur >= p && cur - a[i].second < p ) {
            if ( p + c - 1 < cur ) {
                if ( a[i].second - c > 0 )
                    cout << a[i].first << c;
                c = 0;
            }
            else {
                if (cur - p + 1 > 0)
                cout << a[i].first << cur - p + 1;
                c -= p - cur + a[i].second;
            }
            continue;
        }
        if ( cur >= p + c ) {
            if ( p+c - cur + a[i].second + 1 > 0 )
            cout << a[i].first << p+c - cur + a[i].second + 1;
            c = 0;
            continue;
        }
        c -= a[i].second;
    }
    cout << endl;
}

void solve4()
{
    cout << type << ": ";
    scanf("%s", s+1);
    int nn = strlen(s+1);

    na = nb = 0;

    a[++na].first = s[1];
    LL rem = 0;
    for (int i = 2; i <= nn; i++) {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            a[na].second = rem, a[++na].first = s[i], rem = 0;
        else
            rem = rem*10 + s[i] - '0';
    }

    a[na].second = rem;

    scanf("%s", s+1);
    nn = strlen(s+1);

    b[++nb].first = s[1];
    rem = 0;
    for (int i = 2; i <= nn; i++) {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            b[nb].second = rem, b[++nb].first = s[i], rem = 0;
        else
            rem = rem*10 + s[i] - '0';
    }

    b[nb].second = rem;
    int p;
    cin >> p;

    LL cur = 0, x1 = 0, x2 = 0, I = 0;
    for (int i = 1; i <= na; i++) {
        if ( cur + a[i].second < p-1 ) {
            cout << a[i].first << a[i].second;
            continue;
        }
        if ( cur + a[i].second == p-1 ) {
            if ( b[1].first == a[i].first )
                cout << a[i].first << a[i].second + b[1].second;
            else
                cout << a[i].first << a[i].second << b[i].first << b[i].second;
            x2 = a[i+1].second;
            I = i + 1;
            break;
        }

        x1 = p - 1 - cur;
        x2 = cur + a[i].second - p + 1;
        I = i;
        if ( a[i].first != b[1].first )
            cout << b[1].first << x1 + b[1].second;
    }

    for (int i = 2; i <= nb-1; i++)
            cout << b[i].first << b[i].second;

    if ( a[I].first == b[nb].first ) {
        cout << b[nb].first << x2 + b[nb].second;
    }

    else cout << b[nb].first << b[nb].second << a[I].first << x2;

    for (int i = I+1; i <= na; i++)
        cout << a[i].first << a[i].second;
    cout << endl;

}

int main()
{
    freopen("RLESTR.inp","r",stdin);
    //freopen("RLESTR.out","w",stdout);

    cin >> type;
    while ( type != "" ) {
        if ( type[1] == '1' )   solve1();
        if ( type[1] == '2' )   solve2();
        if ( type[1] == '3' )   solve3();
        if ( type[1] == '4' )   solve4();
        type = "";
        cin >> type;
    }
}
