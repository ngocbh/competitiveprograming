/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

void standardized(string &a,string &b)
{
    while ( a.size() < b.size() ) a = '0' + a;
    while ( b.size() < a.size() ) b = '0' + b;
    a = '0' + a;
    b = '0' + b;
}

string sub(string a,string b)
{
    string s = "";
    standardized(a,b);
    int n  = a.size();

    int rem = 0;
    for (int i = n-1; i >= 0; i--) {
        char c;
        if ( a[i] - b[i] - rem + '0' < '0' )
            c = a[i] - b[i] - rem + 10 + '0', rem = 1;
        else
            c = a[i] - b[i] - rem + '0', rem = 0;
        s = c + s;
    }

    while ( s[0] == '0' && s.size() > 1 ) s.erase(0,1);
    return s;
}

string add(string a,string b)
{
    string s = "";
    standardized(a,b);

    int n  = a.size();
    int rem = 0;
    for (int i = n-1; i >= 0; i--) {
        char c;
        if ( a[i] + b[i] + rem - '0' > '9' )
            c = a[i] + b[i] + rem - 10 - '0', rem = 1;
        else
            c = a[i] + b[i] + rem - '0', rem = 0;
        s = c + s;
    }

    while ( s[0] == '0' && s.size() > 1 ) s.erase(0,1);
    return s;
}

string s;

int main()
{
    //freopen("GEOPROB.inp","r",stdin);
    //freopen("GEOPROB.out","w",stdout);
    int t;
    cin >> t;
    while ( t-- ) {
        string sb,sc,sd;
        cin >> sb >> sc >> sd;
        cout << add(sub(sc,sb), sub(sc,sd)) << endl;
    }

}
