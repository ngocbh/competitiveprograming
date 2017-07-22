#include <bits/stdc++.h>

using namespace std;

const long N = 10000 + 10;

int n, m;
int ca[N];
int a, b, ans;

int main()
{
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);

    cin >> n >> m;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        for (int j = cur; j < cur + a; j++) ca[j] = b;
        cur = cur + a;
    }

    cur = 1;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        for (int j = cur; j < cur + a; j++)
            if ( ca[j] < b ) ans = max(ans,- ca[j] + b);
        cur = cur + a;
    }

    cout << ans;
}
