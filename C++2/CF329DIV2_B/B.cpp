/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define x first
#define y second

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

int n;
LL x1, x2;
LL k[N], b[N], fa[N], fd[N], la[N], ld[N];
ii a[N];
int main()
{
    //freopen("B.inp","r",stdin);
    //freopen("B.out","w",stdout);

    cin >> n;
    cin >> x1 >> x2;
    for (int i = 1; i <= n; i++)
        cin >> k[i] >> b[i];

    for (int i = 1; i <= n; i++) {
        a[i].first = x1*k[i] + b[i];
        a[i].second = x2*k[i] + b[i];
        //if ( a[i].first > a[i].second ) swap(a[i].first,a[i].second);
    }

    sort(a+1,a+n+1);

    LL cura = oo*oo, curd = oo*oo;
    fa[n+1] = fd[n+1] = oo*oo;
    for (int i = n; i > 0; i--)
        if ( k[i] < 0 ) {
            fa[i] = min(a[i].second,cura);
            cura = fa[i];
            fd[i] = curd;
        }
        else {
            fd[i] = min(a[i].second,curd);
            curd = fd[i];
            fa[i] = cura;
        }

    cura = oo*oo, curd = oo*oo;
    la[n+1] = ld[n+1] = oo*oo;
    for (int i = n; i > 0; i--) {
        if ( k[i] < 0 ) {
            la[i] = min(a[i].first,cura);
            cura = la[i];
            ld[i] = curd;
        }
        else {
            ld[i] = min(a[i].first,curd);
            curd = la[i];
            la[i] = cura;
        }
    }

    for (int i = 1; i <= n-1; i++) {
        if ( k[i] < 0 ) {
            if ( ld[i+1] < a[i].second ) {
                cout << "YES";
                return 0;
            }
            if ( fa[i+1] < a[i].second && a[i+1].first != a[i].first ) {
                cout << "YES";
                return 0;
            }
        }
        else {
            if ( la[i+1] < a[i].second ) {
                cout << "YES";
                return 0;
            }
            if ( fd[i+1] < a[i].second && a[i+1].first != a[i].first ) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

}
