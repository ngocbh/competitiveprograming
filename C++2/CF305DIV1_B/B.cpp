#include <bits/stdc++.h>

const long N = 200000 + 10;
using namespace std;
int n;
int a[N], l[N], r[N], f[N];

void findl()
{
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++) {
            while ( a[s.top()] >= a[i] ) s.pop();
            l[i] = s.top();
            s.push(i);
    }
}

void findr()
{
    stack<int> s;
    s.push(n+1);
    for (int i = n; i >= 1; i--) {
            while ( a[s.top()] >= a[i] ) s.pop();
            r[i] = s.top();
            s.push(i);
    }
}

int main()
{       //freopen("B.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        a[0] = a[n+1] = -1;
        findl();
        findr();

        for (int i = 1; i <= n; i++) {
                f[r[i]-l[i]-1] = max(f[r[i]-l[i]-1] , a[i]);
        }
        for (int i = n; i >= 1; i--) {
                f[i] = max(f[i] , f[i+1]);
        }
        for (int i = 1; i <= n; i++) cout << f[i] << " " ;
}
