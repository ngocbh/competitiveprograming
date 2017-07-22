#include <bits/stdc++.h>

using namespace std;
int t,n,a,m;
int64_t res;
int main()
{   scanf("%d" ,&t);
    while (t--){
        scanf("%d", &n); m = 0; res=0;
        for (int i=1; i<=n; i++) {
            scanf("%d", &a);
            if ( m < a ) res+= a-m;
            m = a;
        }
        printf("%lld\n",res);
    }

}
