#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;

int n, k;
int a[N], ca[N];

int main()
{
    freopen("MUTATION.inp","r",stdin);
    freopen("MUTATION.out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= k; i++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) ca[a[i]]++;
        for (int i = 1; i <= n; i++) a[i] = ca[i], sum += a[i], ca[i] = 0;
        if ( sum == 1 && a[1] == 1 ) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";

}
