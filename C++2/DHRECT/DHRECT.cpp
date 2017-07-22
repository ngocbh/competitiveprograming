/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 300000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef unsigned long long LL;
typedef pair <int,int> ii;

int t, n;
int a[N];
int main()
{
    //freopen("DHRECT.inp","r",stdin);
    //freopen(".out","w",stdout);

    ios::sync_with_stdio(0);

    cin >> t;
    while ( t-- ) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        sort(a+1,a+n+1);
        LL cur = 1, A = 0, B = 0;
        for (int i = n-1; i >= 0; i--) {
            if ( a[i] != a[i+1] ) {
                if ( cur > 1 ) {
                    if ( !A ) A = a[i+1];
                    else if ( !B ) B = a[i+1];
                }
                if ( cur > 3 ) {
                    if ( !A ) A = a[i+1];
                    if ( !B ) B = a[i+1];
                }
                cur = 1;
            }
            else ++cur;
        }

        if ( A == 0 || B == 0 )
            cout << -1 << endl;
        else
            cout << A*B << endl;
    }



}
