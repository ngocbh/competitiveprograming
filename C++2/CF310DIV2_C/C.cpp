#include <bits/stdc++.h>

using namespace std;
int res,n,sl,k,m,a,a1,sc;
int main()
{
    freopen("C.inp","r",stdin);
    scanf("%d %d",&n,&k);
    for (int o = 1; o <= k; o++) {
        scanf("%d",&m); sc = 0; ++sl;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            if ( j != 1 && a != a1 + 1 )  {++sl; ++sc;}
            a1 = a;
        }
        res += sc;
        //cout<<sl<<" "<<sc<<endl;
    }
    res += sl - 1;
    if ( res == -1  ) cout<<0;
    else cout<<res;
}
