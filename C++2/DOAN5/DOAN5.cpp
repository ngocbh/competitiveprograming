#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
struct data{
    int a, b, id;
};

int n, ans;
int ta[N], f[N];
data a[N];

bool cmp(data A,data B)
{
    return A.b - A.a < B.b - B.a;
}

int main()
{   freopen("DOAN5.inp","r",stdin);
    freopen("DOAN5.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
        a[i].id = i;
    }

    sort(a+1,a+n+1,cmp);

    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if ( ( a[i].a <= a[j].a && a[j].b < a[i].b ) || j == 0 ) {
                if ( f[i] < f[j] + 1 ) {
                    f[i] = f[j] + 1;
                    ta[i] = j;
                }
            }
        }

        if ( ans < f[i] ) {
            ans = f[i];
            cur = i;
        }
    }

    cout << ans ;

}
