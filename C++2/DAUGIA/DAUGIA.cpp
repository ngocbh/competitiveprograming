#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, f[N];
int A, B;
bool check(int x)
{
        int b[10], len = 0;
        while ( x > 0 ) {
            b[++len] = x % 10;
            x /= 10;
        }

        for (int i = 1; i <= len/2; i++)
            if ( b[i] != b[len-i+1] ) return false;
    return true;
}
int main()
{   //freopen("DAUGIA.inp","r",stdin);
    cin >> A >> B;

    memset(f,true,sizeof(f));
    f[1] = false;
    for (int i = 2; i <= N-10; i++)
            if ( f[i] ) {
                    for (int j = 2; j*i <= N-10; j++) f[i*j] = false;
            }

    int ans = 0;

    for (int i = A; i <= B; i++)
        if ( f[i] && check(i) ) ++ans;
    cout << ans;
}
