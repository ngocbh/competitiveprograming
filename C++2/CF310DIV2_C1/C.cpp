#include <bits/stdc++.h>

using namespace std;
int64_t res,n,sl,k,m,a,a1,sc;
bool ok = false;
int main()
{
    //freopen("C.inp","r",stdin);
    scanf("%d %d",&n,&k);
    for (int o = 1; o <= k; o++) {
        scanf("%d",&m); sc = 0; ++sl; a1 = 0;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            if ( ok == true && a == a1 + 1 ) { a1 = a; continue; }
            else ok = false;
            if ( a == 1 ) {ok = true;  }

            if ( j != 1 ) { ++sl; ++sc; }
            a1 = a;
        }
        res += sc;
    }
    res += sl - 1;
    cout<<res;
}
