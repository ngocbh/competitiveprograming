#include <bits/stdc++.h>

using namespace std;
long long k, n;
int main()
{
    freopen("MICROWAVE.inp","r",stdin);
    //freopen("MICROWAVE.out","w",stdout);
    cin >> k;
    n = k / 5;
    cout << (5*30) * (n*(n+1))/2 + (k%5) * (30*(n+1));
}
