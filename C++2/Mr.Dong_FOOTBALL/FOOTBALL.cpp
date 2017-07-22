#include <bits/stdc++.h>

using namespace std;

const long N = 100 +10;
typedef pair <int,int> ii;

int n, m, ans, sum;
int a[N], b[N], c[N], x[N], ca[N], cb[25];
ii M[N*N];
int cf[N][N];

bool ok;

void ktkq()
{
    if ( ok ) return;
    memset(cf,0,sizeof cf);

    for (int i = 1; i <= n; i++)
    {
         a[i] = (c[i] + x[i]) / 2;
         b[i] = (c[i] - x[i]) / 2;
    }
     memset(cb,0,sizeof cb);


     int ans = 0;
     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= n; j++)
         {
             if ( i == j ) continue;
             if ( a[i] > 0 && cb[j] < b[j] && !cf[i][j] ) --a[i],++cb[j], M[++ans] = ii(i,j), cf[i][j] = cf[j][i] = 1;
         }
         if ( a[i] > 0 ) return;
     }

     for (int i = 1; i <= n; i++) if ( cb[i] != b[i] ) return;

     ok = true;
     for (int i = 1; i <= sum; i++) {
        cout << M[i].first << " " << M[i].second << " ";
     }
     cout << endl;
}

void duyet(int i)
{
    if ( i > n )
    {
        ktkq();
        return;
    }
    for (int j = 1; j >= -1; j--)
    {
        x[i] = j;
        duyet(i+1);
    }
}

int main()
{
    freopen("FOOTBALL.inp","r",stdin);
    freopen("FOOTBALL.out","w",stdout);

    int t = 0;
    cin >> t;

    while ( t-- ) {
        cin >> n; sum = 0;
        for (int i = 1; i <= n; i++) cin >> c[i], sum += c[i];
        sum/=2;
        ok = false;
        duyet(1);
        if ( !ok ) cout << -1 << endl;
    }
}
