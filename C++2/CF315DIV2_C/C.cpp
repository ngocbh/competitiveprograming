#include <bits/stdc++.h>

const long N = 2000000 + 100;
using namespace std;
int p, q, f[N], cf[N], ca[N], m10[10], ans = 0;
void ssnt()
{
    int n = N - 100;
    memset(ca,true,sizeof ca);
    for (int i = 2; i <= n; i++)
        if ( ca[i] ) {
                for (int j = 2; j*i <= n; j++)
                    ca[i*j] = false;
        }
    for (int i = 2; i <= n; i++)
        if ( ca[i] )
            f[i] = f[i-1] + 1;
        else
            f[i] = f[i-1];
}
bool check(int x)
{
    int s[10], sl = 0;
    while ( x > 0 ) {
        s[++sl] = x % 10;
        x /= 10;
    }
    int i = 1, j = sl;
    while ( i < j ) {
        if ( s[i] != s[j] ) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}
void rub()
{
    int n =  N - 100;
    for (int i = 1; i <= n; i++)
        if ( check(i) ) {cf[i] = cf[i-1] + 1; }
        else cf[i] = cf[i-1];
}
int gcd(int a,int b)
{
    int tg;
    while ( b != 0 ) {
        tg = a % b;
        a = b;
        b = tg;
    }
    return a;
}
int main()
{   //freopen("C.inp","r",stdin);
    cin >> p >> q;
    ssnt();
    rub();
    int n = N - 100;
    for (int i = 1; i <= n; i++) {
        int x , y, g;
        x = f[i];
        y = cf[i];

        if ( x*q <= y*p ) {
            ans = i;
        }
    }
    if ( ans == 0 || ans == N - 100 ) {
        cout << "Palindromic tree is better than splay tree";
        return 0;
    }
    cout << ans;

}
