#include <bits/stdc++.h>
const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
int n, h, tq;
int cam[N], cad[N];
LL f[N], ans;
int main()
{
   // freopen("WOUT.inp","r",stdin);
    scanf("%d", &tq);
    while ( tq -- ) {
        scanf("%d %d ", &n, &h);
        for (int i = 1; i <= n; i++) {
            cam[i] = cad[i] = 0;
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int u, v;
            scanf("%d%d", &u,&v);
            ++u,++v;
            cam[u]++;
            cad[v]++;
        }
        int ept = 0;
        for (int i = 1; i <= n; i++) {
                ept += cam[i];
                f[i] = ept;
                ept -= cad[i];
        }
        ans = 1ll*n*n;
        for (int i = 1; i <= n; i++)
            f[i] = f[i-1] + f[i];
        for (int i = 1; i <= n; i++)
            if ( i - h + 1 > 0 ) {
                    LL res;
                    res = f[i] - f[i-h];
                    res = 1LL*n*h - res;
                    ans = min(ans,res);
            }
        printf("%lld\n", ans);
    }
}














/*#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
int n, h, q;
LL ans, res;
LL f[4*N];
int t[4*N];
void update(int k,int l,int r,int u,int v)
{
    if ( l > v || r < u ) return;
    if ( l >= u && r <= v ) {
        f[k] += r - l + 1;
        ++t[k];
        return;
    }

    int mid;
    mid = (l + r) / 2;
    if( t[k] ) {
        t[2*k] += t[k];
		f[2*k] += t[k]*(mid - l + 1);
		t[2*k+1] += t[k];
		f[2*k+1] += t[k]*(r - mid);
		t[k] = 0;
    }
    update(k*2,l,mid,u,v);
    update(k*2+1,mid+1,r,u,v);
    f[k] = f[2*k] + f[2*k+1];
}
void visit(int k,int l,int r,int u,int v)
{
    if ( l > v || r < u ) return;
    if ( l >= u && r <= v ) {
        res += f[k];
        return;
    }
    int mid;
    mid = (l+r) / 2;
    if( t[k] ) {
        t[2*k] += t[k];
		f[2*k] += t[k]*(mid - l + 1);
		t[2*k+1] += t[k];
		f[2*k+1] += t[k]*(r - mid);
		t[k] = 0;
    }
    visit(k*2,l,mid,u,v);
    visit(k*2+1,mid+1,r,u,v);
    f[k] = f[2*k] + f[2*k+1];
}
int main()
{
   // freopen("WOUT.inp","r",stdin);
    cin >> q;
    while ( q-- ) {
        scanf("%d %d", &n,&h);
        for (int i = 1; i <= 4*n; i++) f[i] = 0,t[i] = 0;
        for (int i = 1; i <= n; i++) {
                int u,v;
                scanf("%d%d", &u, &v);
                update(1,0,n-1,u,v);
        }
        ans = 1LL*n*n;
        for (int i = 0; i < n - h + 1; i++) {
            res = 0;
            visit(1,0,n-1,i,i+h-1);
            res = 1LL*n*h - res;
            ans = min(ans , res);
        }
        printf("%lld\n", ans);
    }
}
*/
