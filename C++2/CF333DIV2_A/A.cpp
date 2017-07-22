/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 500;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int x, y, n, b1, b2;

int main()
{
    //freopen("A.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n >> b1;
    for (int i = 1; i <= n; i++) {
        LL a;
        cin >> a;
        x = x*b1 + a;
    }

    cin >> n >> b2;
    for (int i = 1; i <= n; i++) {
        LL a;
        cin >> a;
        y = y*b2 + a;
    }
    cout << x << " " << y << endl;
    if ( x == y ) {
        cout << "=";
        return 0;
    }
    if ( x < y ) {
        cout << "<";
        return 0;
    }
    cout << ">";
    return 0;

}
