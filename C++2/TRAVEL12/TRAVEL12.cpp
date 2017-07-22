#include <bits/stdc++.h>

const long N = 10000 + 10;
const long long MOD = 1000000000 + 7;
using namespace std;
typedef long long LL;

struct data {
    int d[5];
    int s;
    void sort1() {
        sort(d+1,d+4+1);
    }
};
int n, m;
bool b[N][N];
vector <int> a[N];
map <int,int> M;

LL get(data A)
{
    A.sort1();
    LL c = 0;
    for (int i = 0; i <= 4; i++)
        c = ( 1LL*c * 10013 + A.d[i]) % MOD;

    return c;
}

int main()
{   freopen("TRAVEL12.inp","r",stdin);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        b[u][v] = true;
        b[v][u] = true;
        a[v].push_back(u);
    }

    queue <data> qu;

    for (int i = 1; i <= n; i++) {
        data A;
        for (int j = 1; j <= 4; j++) A.d[j] = 0;
        A.d[1] = i;
        A.s = 1;
        qu.push(A);
        M[get(A)] = 1;
    }

    while ( !qu.empty() ) {
        data A;
        A = qu.front();
        qu.pop();

        if ( A.s == 4 ) {
            if ( b[A.d[4]][A.d[1]] ) {
                for (int i = 1; i <= 4; i++) {
                    cout << A.d[i] << " ";
                }
                return 0;
            }
        }

        data B;
            int u = A.d[A.s];
            for (int j = 0; j < a[u].size(); j++) {
                int v = a[u][j];

                bool ok = false;
                for (int o = 1; o <= A.s; o++)
                    if ( v == A.d[o] ) ok = true;
                if ( ok ) continue;

                B = A;
                B.d[A.s+1] = v;
                B.s = A.s + 1;
                if ( M[get(B)] == 0 ) {
                    qu.push(B);
                    M[get(B)] = 1;
                }
            }
    }
    cout << -1;
}
