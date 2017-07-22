#include <bits/stdc++.h>

const long N = 2*100000 + 10;
using namespace std;

int n, m, k, ta;
int c[N], a[N], f[8*N], t[8*N], ca[N];
long long dy[3][510];
long long ans;

void init()
{
    for (int i = 1; i <= 8*n; i++) {
            f[i] =  t[i] = 501;
    }
    for (int i = 1; i <= n; i++) {
            c[i] = 501;
            ca[i] = 0;
    }
    memset(dy, 0 ,sizeof dy);
}

void update(int k, int l, int r, int u, int v, int c)
{
        f[k] = min(f[k],t[k]);
        t[2*k] = min(t[2*k],t[k]);
        t[2*k+1] = min(t[2*k+1],t[k]);
        if ( u > r || v < l ) return;
        if ( u <= l && v >= r ) {
                t[k] = min(t[k],c);
                return;
        }
        int mid;
        mid = (l+r)/2;
        update(k*2,l,mid,u,v,c);
        update(k*2+1,mid+1,r,u,v,c);
        f[k] = min(f[2*k] , f[2*k+1] );
}

void visit(int k,int l,int r,int x)
{
    f[k] = min(f[k], t[k] );
    t[2*k] = min( t[2*k] , t[k] );
    t[2*k+1] = min( t[2*k+1] , t[k] );
    if ( x < l || x > r ) return;
    if ( x == l && x == r  ) {
            c[x] = min(c[x] , f[k] );
            return;
    }
    int mid;
    mid = (l+r) / 2;
    visit(k*2, l, mid, x);
    visit(k*2+1, mid+1, r, x);
}

void solve()
{       ans  = 0;
        for (int i = 1; i <= n; i++) {
                visit(1,1,n,i);
                ca[i] = -a[i];
        }
        int ic,im;
        ic = 0; im = 1;
        for (int i = 1; i <= n; i++) {
                ic = 1 - ic;
                im = 1 - im;
                for (int j = 0; j <= k; j++) {
                            dy[im][j] = dy[ic][j];
                            if ( j - c[i] >= 0 )
                            dy[im][j] = max(dy[im][j] , dy[ic][j - c[i]] + ca[i]);
                }

        }
        for (int i = 1; i <= n; i++) ans += a[i];
        printf("%lld\n", ans + dy[im][k] );
}

int main()
{      // freopen("MCHEF.inp" , "r" , stdin);
        scanf("%d", &ta);
        while ( ta -- ) {
                scanf("%d %d %d ", &n, &k, &m);
                for (int i = 1; i <= n; i++) {
                        scanf("%d", &a[i]);
                }
                int l, r, c;
                init();
                for (int i = 1; i <= m; i++) {
                        scanf("%d %d %d", &l, &r, &c);
                        update(1,1,n,l,r,c);
                }
                solve();
        }

}
