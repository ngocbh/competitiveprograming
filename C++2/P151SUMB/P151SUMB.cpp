#include <bits/stdc++.h>

const long N = 5000+10;
using namespace std;
int n,ans;
int main()
{   //freopen("P151SUMB.inp","r",stdin);
    scanf("%d", &n);
    ans = 2*n + 1;
    for (int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++){
                if ( i*5 + j*3 == n ) {
                    ans = min(ans,i+j);
                }
        }
    if (ans != 2*n + 1) printf("%d", ans);
    else printf("-1");
}
