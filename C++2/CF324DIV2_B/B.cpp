#include <bits/stdc++.h>

const long oo = 1000000000 + 7;
using namespace std;
int n;
int main()
{   //freopen("B.inp","r",stdin);
    cin >> n;
    long long ans3 = 1;
    for (int i = 1; i <= 3*n; i++) ans3 = (ans3*3) % oo;

    long long ans7 = 1;
    for (int i = 1; i <= n; i++) ans7 = (ans7*7) % oo;
    long long ans;
    ans = (ans3 - ans7 + oo) % oo;
    cout << ans;
}
