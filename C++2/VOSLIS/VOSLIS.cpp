#include <bits/stdc++.h>

const long N = 5000 + 10;
using namespace std;

typedef long long LL;
typedef pair <LL,LL> ii;
struct data{
    LL val, ind;
};
int n,m;
LL a[N], b[N];
data fa[N], fb[N];

int main()
{
   // freopen("VOSLIS.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
            fa[i].ind = -1;
            fa[i].val = 0;
    }
    for (int i = 1; i <= m; i++) {
            cin >> b[i];
            fb[i].ind = -1;
            fb[i].val = 0;
    }

    for (int i = 1; i <= m; i++) {
            int u = 0, v = 0;
            for (int j = n; j >= 1; j--)
                if ( a[j] == b[i] ) {
                        u = j;
                        break;
                }
            //cout << i << " " << u << endl;
            for (int j = 1; j <= u; j++){
                if ( fa[j].ind >= 0 ) {
                       // cout << j << " " << fa[j].ind << endl;
                        fb[i].val = max(fa[j].val + abs(a[j] - b[i]) , fb[i].val );
                }
                if ( a[j] == b[i] ) {
                        fa[j].ind = i;
                        fa[j].val = fb[i].val;
                }
            }
           // cout << endl;
            fa[u].ind = i;
            fa[u].val = fb[i].val;
    }
    LL ans = 0;
    for (int i = 1; i <= m; i++) ans = max(ans , fb[i].val);
    cout << ans << endl;
}
