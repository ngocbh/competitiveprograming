/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 667;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n;
string s;
string res;
int ans = 0;

int calc(int a,int b)
{

    if ( s[a] != '(' || s[b] != ')' )  return -1;
    if ( a + 2 == b ) return -1;
    if ( a == b-1 ) return 1;
    if ( a >= b ) return 0;

    int x = -1;
    for (int i = a+1; i < b-1; i++) {
        if ( s[i] == ')' && s[i+1] == '(' ) {
            int a1 = calc(a,i);
            int a2 = calc(i+1,b);

            if ( a1 != -1 && a2 != -1 )
                x = max(x,max(a1,a2));
        }
    }

    x = max(x,calc(a+1,b-1)+1);
    return x+1;
}

void ktkq()
{
    int x = calc(1,n);
    if ( ans <= x ) {
        ans = x;
        res = s;
    }
}

void duyet(int i)
{
    if ( i > n ) {
        ktkq();
        return;
    }
    if ( s[i] != '?' ) {
            duyet(i+1);
            return;
    }

    for (int j = 0; j <= 1; j++) {
        if ( j == 0 ) {
            s[i] = '(';
            duyet(i+1);
        }
        else {
            s[i] = ')';
            duyet(i+1);
        }
    }
}
int main()
{
    freopen("BTN.inp","r",stdin);
    //freopen("BTN.out","w",stdout);

    cin >> s;

    s = '0' + s;
    n = s.size();

    if ( s[1] == '?' ) s[1] = '(';
    if ( s[n] == '?' ) s[n] = ')';

    duyet(1);

    res = res.substr(1,n);
    cout << res;


}
