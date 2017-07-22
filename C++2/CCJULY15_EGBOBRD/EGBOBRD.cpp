#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;

int n, t;
long long k, sk, c, ans;
int a[N];
int main()
{   //freopen("EGBOBRD.inp","r",stdin);
    scanf("%d", &t);
    while ( t-- ) {
            scanf("%d %lld ", &n, &k);
            for (int i = 1; i <= n; i++)  scanf("%d", &a[i]);
            sk = 0;
            ans = 0;
            for (int i = 1; i <= n; i++) {
                    c = ( a[i] - sk + k - 1 ) / k;
                    ans += c;
                    sk = c * k - ( a[i] - sk ) - 1;
                    if ( sk < 0 ) sk = 0;
            }
            printf("%lld\n", ans);

    }
}
