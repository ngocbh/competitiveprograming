#include <bits/stdc++.h>

const long N = 1000000;
using namespace std;
int n;
int a[N];
int main()
{   freopen("POWER.inp","r",stdin);
    cin >> n;

    int m = (int)(sqrt(n)), nn = n;
    for (int i = 2; i <= m; i++) {
        if ( a[i] == 0 && nn % i == 0 ) {
            for (int j = 2; j*i <= m; j++) a[i*j] = -1;
            while (nn%i == 0 ) ++a[i],nn/=i;
        }
    }

    int ans = 1;

    for (int i = 2; i <= m; i++) {
        if ( ca[i] > 0 ) {

        }
    }

}
