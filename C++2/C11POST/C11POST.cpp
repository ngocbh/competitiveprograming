#include <bits/stdc++.h>

const long N = 100 + 10;
const long oo = 1000 + 7;
using namespace std;
typedef pair <int,int> ii;

int n, m, k, sum = 0, _max = -1, _min = oo*oo*oo, ans = oo*oo*oo;
int a[N][N],ca[N][N];
char b[N][N];
ii root;
int sl = 0;

int main()
{   freopen("C11POST.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
            if ( b[i][j] == 'K' ) sum += oo, ++k;
            if ( b[i][j] == 'P' ) root = ii(i,j);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];



    cout << ans;
}
