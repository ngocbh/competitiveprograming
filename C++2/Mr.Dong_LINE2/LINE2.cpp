#include <bits/stdc++.h>

using namespace std;

const long N = 50 + 10;
const long long MOD = 1000000000 + 7;

struct data{
    char a[N][N];
    int val;
    long long get(int n,int m)
    {
        long long res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                res = (res*7 + (a[i][j] == '.') + 2*(a[i][j] == 'M' + 3*(a[i][j] == '#'))) % MOD;
            }
        return res;
    }
};

int n, m;
map<int,int> M;
data A;

bool check(data A)
{
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        for (int  j = 1; j <= m; j++)
            if ( A.a[i][j] == 'M' ) {
                if ( ok ) {
                    if ( A.a[i][j-1] != 'M' ) return false;
                }
                ok = true;
            }
    }
    cout << A.val;
    return true;
}

int h[9] = {0,-2,-2,-1,1,2,2,1,-1};
int c[9] = {0,-1,1,2,2,1,-1,-2,-2};

int main()
{
        freopen("LINE2.inp","r",stdin);
        freopen("LINE2.out","w",stdout);

        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", A.a[i]+1);

        queue <data> qu;
        qu.push(A);
        data B, U;
        int Hash;

        while ( !qu.empty() )
        {
            U = qu.front();
            Hash = U.get(n,m);
            qu.pop();
            if ( M[Hash] ) continue;
            M[Hash] = 1;

            if ( check(U) ) return 0;

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                {
                        if ( U.a[i][j] != 'M' ) continue;
                        for (int o = 1; o <= 8; o++)
                        {
                            if ( i+h[o] < 1 || i + h[o] > n || j + c[o] < 1 || j + c[o] > m || A.a[i+h[o]][j+c[o]] != '.' ) continue;
                            B = U;
                            B.a[i][j] = '.';
                            B.a[i+h[o]][j+c[o]] = 'M';
                            B.val = U.val+1;
                            qu.push(B);
                        }
                }
        }
}
