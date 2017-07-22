#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, res = 0, m;
int a[8*N], f[8*N], t[8*N];

void update(int k,int l,int r,int u,int v,int c)
{
    f[k] += t[k];
    t[2*k] += t[k];
    t[2*k+1] += t[k];
    t[k] = 0;
    if ( u > r || v < l ) return;
    if ( u >= l && v <= r ) {
        t[k] += c;
        return;
    }
    int mid;
    mid = (l + r) / 2;
    update(k*2,l,mid,u,v,c);
    update(k*2+1,mid+1,r,u,v,c);
    f[k] = f[2*k] + f[2*k+1];
}

void visit(int k,int l,int r,int u,int v)
{
    f[k] += t[k];
    t[2*k] += t[k];
    t[2*k+1] += t[k];
    t[k] = 0;
    if ( u > r || v < l ) return;
    if ( u == l && v == r ) {
        res = f[k];
        return;
    }
    int mid;
    mid = (l + r) / 2;
    visit(k*2,l,mid,u,v);
    visit(k*2+1,mid+1,r,u,v);
    f[k] = f[2*k] + f[2*k+1];
}

int main()
{   freopen("UDTSEQ.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        update(1,1,n,u,v,c);
    }
    for (int i = 1; i <= n; i++) {
        visit(1,1,n,i,i);
        cout << res << " ";
    }
}
