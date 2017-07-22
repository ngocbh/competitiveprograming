#include <bits/stdc++.h>

const long N = 4000 + 10;
using namespace std;
typedef long long LL;

int n;
LL v[N], p[N], d[N], f[N], ca[N];
int main()
{   //freopen("C.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> d[i] >> p[i];
    }

    vector <int> ans;
    for (int i = 1; i <= n; i++) {

        if ( p[i] >= 0 ) {
            ans.push_back(i);
            LL t = v[i], j = i+1;
            while ( t > 0 && j <= n ) {
                if ( p[j] < 0 ) {
                    ++j;
                    continue;
                }

                p[j] -= t;
                if ( p[j] < 0 ) f[j] = i;
                --t;
                ++j;
            }

            LL sum = 0;
            for (int j = i; j <= n; j++)
            {
                p[j] -= sum;
                if ( f[j] == i || p[j] < 0 && p[j] + sum >= 0 ) sum += d[j];
            }
        }

    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

}
