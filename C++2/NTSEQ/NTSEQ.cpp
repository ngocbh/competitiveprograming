#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000007;
using namespace std;
typedef long long LL;
int res = 0;
int n, a[N], b[N], t[4*N], cf[4*N], f[N], cs[N],ca[N], id = 0;
bool cmp(int i,int j)
{
    return a[i] < a[j];
}
void discretization() //roi rac
{
    for (int i = 1; i <= n; i++) b[i] = a[i], cs[i] = i;
    sort(cs+1,cs+n+1,cmp);
    sort(b+1,b+n+1);
    int it = 0;
    for (int i = 1; i <= n; i++) {
        if ( b[i] != b[i-1] ) a[cs[i]] = ++it;
        else a[cs[i]] = it;
    }
    for (int  i = 1; i <= n; i++)  b[i] = 0;
}
void update(int k,int l,int r,int u,int v,int cc)
{
    if ( l > v || r < u ) return;
    if ( l >= u && r <= v ) {
        if ( cc == 0 ) {
        f[k] = cc;
        t[k] = cc;
        } else f[k] = (f[k] + cc) % MOD;
        return;
    }
    if ( t[k] != -1 ) {
        f[2*k] = t[k];
        t[2*k] = t[k];
        t[2*k+1] = t[k];
        f[2*k+1] = t[k];
        t[k] = -1;
    }
    int mid;
    mid = (l+r)/2;
    update(k*2,l,mid,u,v,cc);
    update(k*2+1,mid+1,r,u,v,cc);
    f[k] = (f[k*2] + f[k*2+1]) % MOD;
}
void visit(int k,int l,int r,int u,int v)
{
    if ( l > v || r < u ) return;
    if ( l >= u && r <= v ) {
        res = (res + f[k]) % MOD;
        return;
    }
    if ( t[k] != -1 ) {
        f[2*k] = t[k];
        t[2*k] = t[k];
        t[2*k+1] = t[k];
        f[2*k+1] = t[k];
        t[k] = -1;
    }
    int mid;
    mid = (l+r)/2;
    visit(k*2,l,mid,u,v);
    visit(k*2+1,mid+1,r,u,v);
    f[k] = (f[k*2] + f[k*2+1]) % MOD;
}
int binarysearch(int x)
{
    int l = 0, r = id, m, ans;
    while ( l <= r ) {
        m = (l+r) / 2;
        if ( b[m] < x ) {
            ans = m;
            l = m+1;
        }
        else r = m - 1;
    }
    return ans;
}
int main()
{
    //freopen("NTSEQ.inp","r",stdin);
    //freopen("NTSEQ.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    discretization();
    a[n+1] = N - 5;
    for (int i = 1; i <= 4*n; i++) t[i] = -1;
    for (int i = 1; i <= n+1; i++) {
        int x;
        b[id+1] = N - 5;
        x =binarysearch(a[i]);
            if ( ca[a[i]] < x ) update(1,1,n,a[i],a[i],0);
            if ( a[i] + 1 <= b[x+1]-1)
            update(1,1,n,a[i]+1,b[x+1]-1,0);

            b[x+1] = a[i];
            res = 0;
            if ( x == 0 )   res = 1;
            else  visit(1,1,n,b[x],a[i]-1);
            cf[i] = res;
            update(1,1,n,a[i],a[i],cf[i]);

        if ( x == id ) ++id;
        ca[a[i]] = x;
    }
    cout << cf[n+1];
}
