#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

int n;

void solve(int u)
{
    int l = 0, r = 0 ;
    cout << u << endl;
    n = max(n,u);
    cin >> l >> r;
    if ( l != 0 ) solve(l);
    if ( r != 0 ) solve(r);
}

int main()
{
    freopen("Googol.in","r",stdin);
    freopen("Googol.out","w",stdout);
    solve(1);
    cout << "Answer " << n << endl;
}
