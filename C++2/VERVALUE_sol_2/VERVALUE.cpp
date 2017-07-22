#include <bits/stdc++.h>

using namespace std;
const long N = 100000 + 10;

int n, q;
int ca[N], L[N], R[N], num = 0;
vector <int> a[N];

struct SegmentTree{
    int val[4*N], lazy[4*N];

    void init()
    {
        memset(val,0,sizeof val);
        memset(lazy,0,sizeof lazy);
    }
    void push_down(int k,int l,int r)
    {
        if ( l == r || !lazy[k] ) return;
        lazy[2*k] = val[2*k] = lazy[2*k + 1] = val[2*k + 1] = lazy[k];
        lazy[k] = 0;
    }
    void update(int k,int l,int r,int u,int v,int NewVal)
    {
        if ( l > v || r < u ) return;
        if ( l >= u && r <= v ) lazy[k] = val[k] = NewVal;
        else
        {
            push_down(k,l,r);
            int mid = (l + r)/2;
            update(k * 2 , l , mid , u , v , NewVal);
            update(k * 2 + 1 , mid + 1, r , u, v, NewVal);
            val[k] = max(val[2*k],val[2*k+1]);
        }
    }
    int get(int k,int l,int r,int u,int v)
    {
        if ( l > v || r < u ) return 0;
        if ( l >= u && r <= v ) return val[k];
        else
        {
            push_down(k,l,r);
            int mid = (l + r)/2;
            return max(get(k*2, l, mid, u, v), get(k*2 + 1, mid + 1, r, u, v));
        }
    }
} IT[2];

void dfs(int u)
{
    L[u] = ++num;
    ca[u] = true;
    for (int v, i = 0; i < a[u].size(); i++) {
        v = a[u][i];
        if ( ca[v] ) continue;
        dfs(v);
    }
    R[u] = num;
}

int main()
{
    //freopen("VERVALUE.inp","r",stdin);

    ios::sync_with_stdio(false);
    cin.tie(false);

    cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);
    IT[0].init(); IT[1].init();

    cin >> q;
    for (int type, x, i = 1; i <= q; i++) {
        cin >> type >> x;

        if ( type == 1 )
            IT[0].update(1,1,n,L[x],R[x],i);
        else if ( type == 2 )
            IT[1].update(1,1,n,L[x],L[x],i);
        else
        {
            cout << ( ( IT[0].get(1,1,n,L[x],L[x]) > IT[1].get(1,1,n,L[x],R[x]) ) ? 1 : 0 ) << endl;
            //cout <<  IT[0].get(1,1,n,L[x],L[x]) << " " << IT[1].get(1,1,n,L[x],R[x]) << endl;
        }
    }
}
