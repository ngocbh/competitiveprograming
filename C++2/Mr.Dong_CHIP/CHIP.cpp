#include <bits/stdc++.h>
#define mp(a,b,c) iii(ii(a,b),c)
using namespace std;

const long N = 35;
typedef pair <int,int> ii;
typedef pair <ii,int> iii;

int n, m, k, ans;
iii M[N*N];
char a[N][N];

bool check(int r,int x,int y)
{
    for (int i = x; i <= x+r-1; i++)
        for (int j = y; j <= y+r-1; j++)
            if ( a[i][j] == '#' ) return false;
    return true;
}

void repair(int r,int x,int y)
{
    for (int i = x; i <= x+r-1; i++)
        for (int j = y; j <= y+r-1; j++)
            a[i][j] = '#' + '.' - a[i][j];
}

void inkq()
{
    for (int i = 1; i <= k; i++)
        cout << M[i].first.first << " " << M[i].first.second << " " << M[i].second << endl;
    exit(0);

}

void duyet(int o)
{
    if ( o > k )
    {
        inkq();
        return;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if ( a[i][j] == '#' ) continue;
            if ( a[i][j+1] == '.' )
            {
                M[o] = mp(i,j,1);
                a[i][j] = a[i][j+1] = '#';
                duyet(o+1);
                a[i][j] = a[i][j+1] = '.';
            }
            if ( a[i+1][j] == '.' )
            {
                M[o] = mp(i,j,2);
                a[i][j] = a[i+1][j] = '#';
                duyet(o+1);
                a[i][j] = a[i+1][j] = '.';
            }
        }
}

int main()
{
        freopen("CHIP.inp","r",stdin);
        freopen("CHIP.out","w",stdout);

        scanf("%d %d %d", &n, &m, &k);

        for (int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);

        for (int i = 0; i <= n+1; i++) a[i][0] = a[i][m+1] = '#';
        for (int i = 0; i <= m+1; i++) a[0][i] = a[n+1][i] = '#';
        int EdgeMax = min(m,n);

    for (int o = EdgeMax; o > 0; o--)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                    if ( check(o,i,j) == false ) continue;
                    repair(o,i,j);
                    duyet(1);
                    repair(o,i,j);
            }
}
