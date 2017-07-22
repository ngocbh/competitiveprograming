/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, x0, y0;
int x[N], y[N];
map <ii,int> M;

int main()
{
    //freopen("B.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    cin >> x0 >> y0;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        x[i] -= x0;
        y[i] -= y0;
        int g = __gcd(x[i],y[i]);
        if ( !M[ii(x[i]/g,y[i]/g)] ) {
            ++ans;
            M[ii(x[i]/g,y[i]/g)] = 1;
        }
    }

    cout << ans;
}
