#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;

int n, m;
int a[N], b[N], ca[N], f[N], h[N];

bool cmp(int A,int B)
{
    return A > B;
}

int main()
{   freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i], f[b[i]] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < N; i++) h[i] = 1, ca[i] = 0;

    for (int i = 1; i <= n; i++) {
        int cj = 1;
        for (int j = 1; j <= a[i]; j+=cj) {
            if ( h[a[i]]*a[i] < N ) {
                if ( !ca[h[a[i]]*a[i]] )
                    ca[h[a[i]]*a[i]] = 1, cj = 1;
                else
                    cj = 0;
                ++h[a[i]];
            }
            else break;
        }
    }

    int ans = 0;
    for (int i = 1; i < N; i++)
        if ( ca[i] && f[i] ) ++ans;

    cout << ans;
}
