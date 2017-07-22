#include <bits/stdc++.h>

const long N = 5000 + 10;
using namespace std;
typedef long long LL;
struct data{
    LL S,V;
};

int n;
LL f[N][N/2], ca[N], cs[N];
data a[N];

bool cmp(data A,data B)
{
    return A.V > B.V;
}
bool cmp_1(int i,int j)
{
    return a[i].V > a[j].V;
}
int main()
{       //freopen("VODIVIDE.inp","r",stdin);
        //freopen("VODIVIDE.out","w",stdout);
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].V, cs[i] = i;
        for (int i = 1; i <= n; i++) cin >> a[i].S;

        sort(cs+1,cs+n+1,cmp_1);
        sort(a+1, a+n+1, cmp);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j*2 <= i; j++) {

                if ( f[i-1][j-1]+a[i].S >= f[i-1][j-1] && f[i-1][j-1]+a[i].S > f[i][j] ) {
                    Ta[i][j].S = i-1;
                    Ta[i][j].V = j-1;
                }
                f[i][j] = max(f[i][j] , max(f[i-1][j],f[i-1][j-1]+a[i].S) ) ;
            }

        memset(ca,true,sizeof(ca));
        int u = n,v = n/2, xu,xv;

        for (int i = 1; i <= n; i++) {
            if ( f[u][v] == f[u-1][v-1] + a[u].S ) {
                ca[u] = false;
                u = u-1;
                v = v-1;
            }   else {
                u = u-1;
                v = v;
            }
        }
        cout << f[n][n/2] << endl;
        int ci = 0;
        for (int i = 1; i <= n; i++)
                if ( ca[i] == false ) {
                        ++ci;
                        while ( !ca[ci] ) ++ci;
                        cout << cs[i] << " " << cs[ci] << endl;
                }
}
