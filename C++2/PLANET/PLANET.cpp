/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,int> ii;

struct data{
    int x,y,z;
};
struct edge{
    int u,v,c;
};

int n;
int lad[N];
data a[N];
edge M[N*N];

int calc(data A,data B)
{
    int res = min(abs(A.x - B.x),min(abs(A.z - B.z),abs(A.y - B.y)));
    return res;
}

bool cmp(edge A,edge B)
{
    return A.c < B.c;
}

int findroot(int u)
{
    if ( lad[u] < 0 ) return u;
    int r = findroot(lad[u]);
    lad[u] = r;
    return r;
}

void _union(int r,int s)
{
    int x = lad[r] + lad[s];
    if ( lad[r] < lad[s] ) {
        lad[r] = x;
        lad[s] = r;
    }
    else {
        lad[s] = x;
        lad[r] = s;
    }
}

int main()
{
    freopen("PLANET.inp","r",stdin);
    freopen("PLANET.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        lad[i] = -1;
    }

    int m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++) {
                M[++m].u = i;
                M[m].v = j;
                M[m].c = calc(a[i],a[j]);
        }

    sort(M+1,M+m+1,cmp);
    LL ans = 0;

    for (int i = 1; i <= m; i++) {
        int u = M[i].u;
        int v = M[i].v;
        int c = M[i].c;
        int r = findroot(u);
        int s = findroot(v);
        if ( r != s ) {
            ans += c;
            _union(r,s);
        }
    }

    cout << ans;
}
