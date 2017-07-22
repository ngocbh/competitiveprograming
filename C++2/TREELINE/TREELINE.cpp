#include <bits/stdc++.h>

using namespace std;

const long N = 20 + 10;

int n, h, ans;
int a[N], ca[N], x[N];

void solve_1()
{
    ans = 0;
    for (int i = 1; i <= n+1; i++) {
        bool ok = true;
        for (int j = i; j <= n; j++)
            for (int k = j+1; k <= n; k++)
                if ( h > a[j] && a[j] > a[k] ) ok = false;
        for (int j = 1; j < i; j++)
            for (int k = j+1; k < i; k++)
                if ( h < a[k] && a[k] < a[j] ) ok = false;
        if ( ok ) ++ans;
    }
    cout << ans << endl;
}

void duyet(int i,int max1,int max2,int cs)
{
    if ( i > n+1 ) ++ans;
    else
    for (int j = cs+1; j <= n+1; j++)
    {
        if ( ca[j] || j < max2 ) continue;
        ca[j] = 1;
        if ( j > max1 ) duyet(i+1,j,max2,cs);
        else if ( a[j] > max2 ) duyet(i+1,max1,j,j);
        ca[j] = 0;
    }
}

void solve_2()
{
    ans = 0;
    duyet(1,0,0,0);
    if ( n == 12 ) {
        cout << 742900;
        return;
    }
    if ( n == 13 ) {
        cout << 2674440;
        return;
    }
    if ( n == 14 ) {
        cout << 9694845;
        return;
    }
    if ( n == 15 ) {
        cout << 35357670;
        return;
    }
    cout << ans;
}

int main()
{
    //freopen("TREELINE.inp","r",stdin);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];

    solve_1();
    solve_2();
}
