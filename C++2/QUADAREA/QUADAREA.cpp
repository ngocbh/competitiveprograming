/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int t, ca[5];
double ans;
double x[6], a[6], b[6];

double area()
{
    double c = 0;

    for (int i = 1; i <= 4; i++) {
        c += a[i];
    }
    c/=2;

    return sqrt( (c-a[1])*(c-a[2])*(c-a[3])*(c-a[4]) );
}


int main()
{
    //freopen("QUADAREA.inp","r",stdin);
    //freopen("QUADAREA.out","w",stdout);

    int t;
    cin >> t;

    while ( t-- ) {
        cin >> a[1] >>  a[2] >> a[3] >> a[4];
        ans = area();
        cout << fixed << setprecision(2) << ans << endl;
    }
}
