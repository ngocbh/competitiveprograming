#include <bits/stdc++.h>

const long N = 5000 + 10;
using namespace std;
typedef long long LL;

struct data{
        int x,y;
};

int n;
int a[N], b[N];
LL ans = 0;
data res[N];

void compare(int i,int j)
{
    int u,v,c,d;
    int res1 = 0, res2 = 0;
    u = res[i].x;
    v = res[i].y;
    c = res[j].x;
    d = res[j].y;
    //u,c -- v,d
    res1 =  b[u]*(a[u] < a[c]) + b[c]*(a[u] > a[c]);
    res1 += b[v]*(a[v] < a[d]) + b[d]*(a[v] > a[d]);
    //u,d -- v,c
    res2 =  b[u]*(a[u] < a[d]) + b[d]*(a[u] > a[d]);
    res2 += b[v]*(a[v] < a[c]) + b[c]*(a[v] > a[c]);
    //kt
    if ( max(res1,res2) - b[u] - b[c] < 0 ) return;
    if ( res1 > res2 ) {
            res[i].x = u;   res[i].y = c;
            if ( a[u] > a[c] ) swap(res[i].x , res[i].y);
            res[j].x = v;   res[j].y = d;
            if ( a[v] > a[d] ) swap(res[j].x , res[j].y);
            ans += res1 - b[u] - b[c];
            return;
    }
            res[i].x = u;   res[i].y = d;
            if ( a[u] > a[d] ) swap(res[i].x , res[i].y);
            res[j].x = v;   res[j].y = c;
            if ( a[v] > a[c] ) swap(res[j].x , res[j].y);
            ans += res2 - b[u] - b[c];
}

int main()
{
       //freopen("VODIVIDE.inp","r",stdin);
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        for (int i = 1,ii = 1; i <= n; i++,ii+=2) {
                res[i].x = ii;
                res[i].y = ii+1;

                if ( a[ii] > a[ii+1] ) swap(res[i].x , res[i].y);
                ans += b[res[i].x];
        }
        for (int o = 1; o <= 2; o++)
        for (int i = 1; i <= n/2; i++)
                for (int j = 1; j <= n/2; j++) {
                        compare(i,j);
                }
        cout << ans << endl;
        for (int i = 1; i <= n/2; i++) cout << res[i].x << " " << res[i].y << endl;
}
