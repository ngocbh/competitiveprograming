#include <bits/stdc++.h>
const long N = 5 * 100000 + 10;
const long oo = 100000000 + 7;
using namespace std;
typedef pair<int64_t,int64_t> ii;
int64_t n,t[N],p[N];
int64_t f[N],res;
priority_queue <ii,vector<ii>,greater<ii> > qu;
int64_t min1(int64_t x,int64_t y)
{
    if ( x > y ) return y;
    else return x;
}
int main()
{  // freopen("HIREHP.inp","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &t[i], &p[i]);
    if ( n == 0 ) { cout<<0; return 0;}
    qu.push(ii(0,0)); res = (long long) oo * oo;
    for (int i = 1; i <= n; i++) {
        f[i] = qu.top().first + p[i];
        if (t[i] == n || i == n) res = min1(res,f[i]);
        qu.push(ii(f[i],t[i]));
        while ( qu.top().second < i ) qu.pop();
    }
    cout<<res;
}
