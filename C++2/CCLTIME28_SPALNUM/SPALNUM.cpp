#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int n, a , b, ca[N];
LL ans = 0;

bool check(int x)
{
    int b[20], ci = 0;
    while ( x > 0 ) {
        b[++ci] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= ci/2; i++) {
        if ( b[i] != b[ci-i+1] ) return false;
    }
    return true;
}

int main()
{   //freopen("SPALNUM.inp","r",stdin);

for (int i = 1; i <= N - 10; i++)
    ca[i] = check(i);
int t;
cin >> t;
while ( t-- ) {
    cin >> a >> b;
    ans = 0;
    for (int i = a; i <= b; i++)
        if ( ca[i] )
                ans += i;
    cout << ans << endl;
}
}
