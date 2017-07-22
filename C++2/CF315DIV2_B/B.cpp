#include <bits/stdc++.h>
const long N = 100000 + 10;
using namespace std;
int n , a[N], ca[N], cf[N];
int main()
{
    //freopen("B.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i],ca[i] = 1, cf[a[i]] = 1;
    int it = 1;
    for (int i = 1; i <= n; i++) {
        if ( a[i] > n ) {
            while ( ca[it] == false || cf[it] == true ) ++it;
            a[i] = it;
            ca[it] = false;
            continue;
        }
        if ( ca[a[i]] ) {
            ca[a[i]] = false;
            continue;
        }
        while ( ca[it] == false || cf[it]== true ) ++it;
        a[i] = it;
        ca[it] = false;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
