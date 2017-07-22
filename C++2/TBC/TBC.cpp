/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, ans ;
int a[N];
map <int,int> M1;
map <ii,int> M2;

int main()
{   freopen("TBC.inp","r",stdin);
    //freopen("TBC.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            M1[a[i]+a[j]]++;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if ( i == j ) continue;
            ++M2[ii(i,a[i]+a[j])];
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            {
                 int d = 3*a[i] - a[j];
                 if ( M1[d] - M2[ii(j,d)] > 0 ) {
                        ++ans;
                        break;
                 }
            }
    }

    cout << ans;
}
