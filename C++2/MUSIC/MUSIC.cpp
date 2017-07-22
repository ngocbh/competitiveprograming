#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef pair <int,int> ii;
int n,k,d[N],f[N],ta[N],t[N],res=0,rres,u,cs[N];
ii a[N],b[N];
bool cmp(int i,int j)
{
    if ( a[i].first != a[j].first )
        return a[i].first < a[j].first;
    else
        return a[i].second < a[j].second;
}
int main()
{   freopen("MUSIC.inp","r",stdin);
    //freopen("MUSIC.out","w",stdout);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i].first);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i].second);
    for (int i = 1; i <= n; i++) b[i] = a[i],cs[i]=i;
    sort(cs+1 , cs+n+1, cmp);
    for (int i = 1; i <= n; i++) a[i] = b[cs[i]];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i ; j++)
            if ( f[i] < f[j] + a[i].second && d[j] + k <= a[i].first ) {
                f[i] = f[j] + a[i].second;
                d[i] = d[j] +  k;
                ta[i] = j;
            }
        res = max(res, f[i]);
        if ( res == f[i] ) u = i;
    }
    printf("%d\n", res);
    while ( u != 0 ) {
        t[++rres] = u;
        u = ta[u];
    }
    for (int i = rres; i>=1; i--) printf("%d ", cs[t[i]]);

}
