#include <bits/stdc++.h>

using namespace std;

const long N = 50 + 10;
typedef pair <int,int> ii;

int n, m, ans;
int a[N][N], b[N][N], ca[N][3];
ii M[N];

void inkq()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( a[i][j] != b[i][j] ) return;
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) cout << M[i].first << " " << M[i].second << endl;
    exit(0);
}

void _swap(int u,int v,int x)
{
    if ( x == 1 )
        for (int i = 1; i <= n; i++) a[u][i] = 0 - a[u][i];
    else
        for (int i = 1; i <= n; i++) a[i][v] = 0 - a[i][v];
}

void duyet(int u,int v)
{
    //cout << u << " " << v << " " << a[u][v] << " " << b[u][v] << endl;
    if ( u > n )
    {
        inkq();
        return;
    }
    if ( a[u][v] == b[u][v] )
    {
        if ( v < n ) duyet(u,v+1);
        else duyet(u+1,1);
    }
    else
    {
        for (int i = 1; i <= 2; i++)
        {
            //if ( v != 1 && i == 1 ) continue;
            if ( ca[(i==1)*u + v*(i==2)][i] ) continue;

            _swap(u,v,i);
            ca[(i==1)*u + v*(i==2)][i] = true;
            M[++ans] = ii(i,(i==1)*u + v*(i==2));

            if ( v < n ) duyet(u,v+1);
            else duyet(u+1,1);

            _swap(u,v,i);
            ca[(i==1)*u + v*(i==2)][i] = false;
            --ans;
        }
    }

}

int main()
{
    freopen("CNTab1.inp","r",stdin);
    freopen("CNTab1.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];

    duyet(1,1);
    cout << -1 << endl;
}
