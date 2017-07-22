#include <bits/stdc++.h>

const long N = 100 + 10;
const long MOD = 1000000000 + 7;
using namespace std;

typedef long long LL;
typedef pair <int,int> ii;

struct data{
    ii d[6];
    int s;
    void sort1() {
        sort(d,d+5+1);
    }
};
int n, m , k, ans;
int a[N][N], ca[N][N];
string s;
map <int,int> M;

int get(data A)
{
    A.sort1();
    int c = 0;
    for (int i = 0; i <= 5; i++)
    {
        c = (1LL*c*100 + A.d[i].first ) % MOD;
        c = (1LL*c*100 + A.d[i].second ) % MOD;
    }
    return c;
}

int main()
{
    freopen("COLOR9.inp","r",stdin);
    //freopen("COLOR9.out","w",stdout);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j-1] - '0';
    }

    queue <data> qu;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if ( a[i][j] ) continue;
            data A;
            A.d[1] = ii(i,j);
            A.s = 1;
            qu.push(A);
            M[get(A)] = 1;
        }

    memset(ca,true,sizeof ca);

    while ( !qu.empty() ) {
        data A;
        int s;
        A = qu.front();
        qu.pop();
        if ( A.s == k ) {
            ++ans;
            continue;
        }

        for (int i = 1; i <= A.s; i++)
        {
            int u = A.d[i].first, v = A.d[i].second;
            ca[u][v] = false;
        }

        data B = A;
        for (int i = 1; i <= A.s; i++)
        {
            int u = A.d[i].first, v = A.d[i].second;
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++) {
                    if ( i == 0 && j == 0 ) continue;
                    if ( i != 0 && j != 0 ) continue;
                    if ( u + i > 0 && u + i <= n && v + j > 0 && v + j <= m ) {
                        if ( a[u+i][v+j] ) continue;
                        if ( !ca[u+i][v+j] ) continue;
                        B.d[A.s+1] = ii(u+i,v+j);
                        B.s = A.s + 1;
                        int tt = get(B);
                        if ( M[tt] == 0 ) {
                            qu.push(B);
                            M[tt] = 1;
                        }
                    }
            }
        }

        for (int i = 1; i <= A.s; i++)
        {
            int u = A.d[i].first, v = A.d[i].second;
            ca[u][v] = true;
        }
    }

    cout << ans;
}
