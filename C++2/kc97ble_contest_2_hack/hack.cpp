#include <bits/stdc++.h>

using namespace std;

const long N = 1000000 + 10;

typedef long long LL;
typedef pair<LL,int> ii;

long long n, m, k;
long long ans = 0;
long long a[N], sum[N];
map <ii,int> M;

int main()
{
    //freopen("hack.inp","r",stdin);
    //freopen("hack.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[n+i] = a[i];

    for (int i = 1; i <= 2*n; i++) sum[i] = sum[i-1] + a[i];

    int len = n/2;
    deque <ii> qu;
    for (int i = 2; i <= n - len + 1; i++) {
        int k = i + len - 1;
        qu.push_back(ii(sum[k]-sum[i-1],i));
        M[ii(sum[k]-sum[i-1],i)] = 1;
    }

    int k = n+1;

   // for (int i = 1; i <= 2*n-len+1; i++) cout << i+len-1 << " " << sum[i+len-1] - sum[i-1] << endl;
    for (int i = 1; i <= n; i++) {
        long long _max = 0;

        map <ii,int> ::iterator it = M.end(); --it;
        _max = it->first.first;

        qu.push_back(ii(sum[k] - sum[k-len],k-len+1));
        M[ii(sum[k] - sum[k-len],k-len+1)] = 1;
        ++k;

        //cout << M.size() << endl;

        ii A;
        A = qu.front();
        qu.pop_front();
        M.erase(A);

        ans = max(ans,sum[n] - _max);
    }
    cout << ans;
}
