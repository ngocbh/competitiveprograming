#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef pair<int,int> ii;

int n, ans, m;
int a[N][N], h[N], c[N];
int M[N*N];
vector<ii> b;

bool cmp(ii A,ii B)
{
    return A.second < B.second;
}

bool check(int x)
{
    b.clear();
    memset(h,0,sizeof h);
    memset(c,0,sizeof c);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( a[i][j] >= x )
                b.push_back(ii(i,j));

    sort(b.begin(),b.end());

}

int main()
{   freopen("NANGSUAT.inp","r",stdin);
    //freopen("NANGSUAT.out","w".stdout);
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j],M[++m] = a[i][j];

    sort(M+1,M+m+1);

    int l = 1, r = m, mid, ans = 0;
    while ( l <= r ) {
        int mid = (l+r)/2;
        if ( check(M[mid]) ) {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }

    cout << ans;
}
