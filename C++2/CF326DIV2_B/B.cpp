#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
LL n;
int ca[N];
vector <LL> a;

bool check(LL x)
{
    for (LL i = 0; i < a.size(); i++) {
        if ( x % a[i] == 0 )
            return false;
        if ( a[i] > x ) break;
    }

    return true;
}

int main()
{   //freopen("B.inp","r",stdin);
    cin >> n;

    ca[1] = 1;

    for (int i = 2; i < N; i++)
        if ( ca[i] == 0 ) {
                for (int j = 2; j*i < N; j++) ca[i*j] = 1;
                a.push_back(1LL*i*i);
        }

    LL ans = 0;
    vector <LL> b;

    for (int i = 1; 1LL*i*i <= n; i++) {
        if ( n % i == 0 ) {
        b.push_back(i);
        b.push_back(n/i);
        }
    }

    sort(b.begin(),b.end());
    for (int i = b.size()-1; i > 0; i--) {
    if ( check(b[i]) ) {
        cout << b[i];
        return 0;
    }
    }
}
