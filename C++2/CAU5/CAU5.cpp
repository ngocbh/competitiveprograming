#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <algorithm>

const long N = 100000 + 10;
using namespace std;
ifstream fi("CAU5.inp");
ofstream fo("CAU5.out");
typedef long long LL;
typedef pair <int,int> ii;

LL c1, c2 , n, m;
LL ca[N];
ii a[N], p[2*N];

int main()
{
    fi >> c1 >> c2;
    fi >> n;
    for (int i = 1; i <= n; i++) fi >> a[i].second >> a[i].first;
    fi >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        fi >> u >> v;
        p[i*2-1].first = u;
        p[i*2-1].second = -i;
        p[i*2].first = v;
        p[i*2].second = i;
    }

    sort(a+1,a+n+1);
    sort(p+1,p+2*m+1);
    memset(ca,0,sizeof ca);
    int k = 1, ans = 0;
    LL sum = 0;
    for (int i = 1; i <= 2*m; i++) {
        while ( k <= n && a[k].first <= p[i].first ) sum+=a[k].second,++k;

        if ( p[i].second < 0 && sum >= c1 ) sum-=c1,++ans,ca[-p[i].second] = 1;;
        if ( p[i].second > 0 && sum >= c2 && ca[p[i].second] == 0 ) ++ans, sum-=c2;
    }
    fo << ans;
}
