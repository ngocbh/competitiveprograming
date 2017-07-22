#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
typedef pair<int,int> ii;

int n, t;
int ca[N], p[N], f[N];

void init()
{
        for (int i = 2; i < N; i++) {
            if ( p[i] != 0  ) continue;
            p[i] = i;
            for (int j = 2; j*i < N; j++)
                p[j*i] = i;
        }
}

void calc(int n,int a)
{
    for (int i = 2; i <= n; i++) {
        if ( p[i] != i ) continue;
        LL x = i;
        while ( x <= n ) {
            f[i] += a*(n/x);
            x *= i;
        }
    }
}

void solve(int a,int b)
{
    //memset(f,0,sizeof f);
    calc(b,1);
    calc(a-1,-1);
    LL ans = 1;
    for (int i = 2; i <= b; i++) {
        ans = (ans*(2*f[i]+1)) % 111539786;
    }
    cout << ans << endl;
    calc(a-1,1);
    calc(b,-1);
}

int main()
{   freopen("LCM.inp","r",stdin);
    freopen("LCM.out","w",stdout);

    init();

    cin >> t;

    while ( t-- ) {
        int a, b;
        cin >> a >> b;
        solve(a,b);
    }

}
