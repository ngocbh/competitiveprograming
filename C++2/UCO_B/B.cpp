#include <bits/stdc++.h>

using namespace std;
int64_t t,m,n;
int64_t res;
int main()
{   //freopen("B.inp","r",stdin);
    scanf("%d ",&t);
    while (t--) {
        scanf("%lld %lld", &n,&m);
        if ( m < n ) swap(m,n);
        res = (int64_t) (n*(n-1)) / 2 + (m-n)*n;
        printf("%lld\n", res );
    }

}
