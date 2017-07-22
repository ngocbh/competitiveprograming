#include <bits/stdc++.h>

const long N =  4 * 100000 + 10;
using namespace std;
typedef long long LL;
int n;
int a[N], b[N];

bool check(int x)
{
    LL sum = 0;

    for (int i = 1; i <= n-1; i++) {
        sum += b[i] - x;
        if ( sum < 0 ) {
            sum -= a[i+1] - a[i];
        }
        else {
            if ( sum - (a[i+1] - a[i]) < 0 ) {
                sum = 0;
            }
            else {
                sum -= a[i+1] - a[i];
            }
        }
    }

    sum += b[n] - x;

    if ( sum >= 0 ) return true;
    else return false;
}

int main()
{   //freopen("HP09ANTS.inp","r",stdin);
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], sum += b[i];

    int l = 1, r = sum / n, m, ans = 0;
    //cout << r << endl;
    while ( l <= r ) {
        m = ( l + r ) / 2;
        if ( check(m) ) {
            l = m + 1;
            ans = m;
        }
        else r = m - 1;
    }
    cout << ans;

}

