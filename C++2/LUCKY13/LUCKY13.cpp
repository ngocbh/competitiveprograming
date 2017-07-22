/*
 -Creat by NgocJr7
 -24/9/2015
*/
#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int na, nb;
LL pow10[20];
string a , b;

LL xss(string s)
{
    if ( s == "" ) return 0;
    LL c = 0;
    for (int i = 0; i < s.size(); i++)
        c = c*10 + s[i] - '0';
    return c;
}

void metvai()
{

}

int main()
{   freopen("LUCKY13.inp","r",stdin);

    cin >> a >> b;

    na = a.size(); a = '0' + a;
    nb = b.size(); b = '0' + b;

    LL ansa = 0; pow10[0] = 1;
    for (int i = 1; i <= 15; i++) pow10[i] = pow10[i-1] * 10;
    ///CALC___a;
    string s1 = "", s2 = "", s;
    int x,y;
    for (int i = 0; i <= na-2; i++) {
            s1 += a[i];
            s2 = a.substr(i+3,na-i-2);
            s = s1 + "13" + s2;
            x = i;
            y = na - i - 2;

            ansa += (pow10[x] - xss(s1) - 1) * pow10[y];

            if ( xss(s) == xss(a) ) ansa += pow10[y] - xss(s2);
            if ( xss(s) > xss(a) ) ansa += pow10[y];
    }
    LL res = ansa;
    ///CALC___b;
    LL ansb = 0;
    s1 = "";
    for (int i = 0; i <= nb-2; i++) {
            s1 += b[i];
            s2 = b.substr(i+3,nb-i-2);
            s = s1 + "13" + s2;
            x = i;
            y = nb - i - 2;

            ansb += (pow10[x] - xss(s1) - 1) * pow10[y];
            cout << x << " " << y << endl;
            cout << s1 << " " << s2 << endl;
            cout << ansb << endl;
            if ( xss(s) == xss(b) ) ansb += pow10[y] - xss(s2);
            if ( xss(s) > xss(b) && xss(s2) != 0 ) ansb += pow10[y];
            cout << ansb << endl << endl;
    }
    LL ans = 0;
    if ( na == nb ) {
        ans = ansa -ansb;
        cout << xss(b) - xss(a) + 1 - ans;
        return 0;
    }
    cout << ansb << endl;
    ans = ansa + pow10[nb+1] - ansb;
    cout << ans << endl;
    for (int i = na+1; i <= nb-1; i++) {
        for (int j = 1; j <= i; j++)
            ans += (pow10[j] - pow10[j-1]) * pow10[i-j-2];
        ans += pow10[i-2];
    }
    cout << ans;
}
