#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

typedef long long LL;
typedef pair <int,int> ii;

int n, k;
LL ans = 0;
ii a[N];

bool cmp(ii A,ii B)
{
    if ( A.first != B.first ) return A.first < B.first;
    return A.second > B.second;
}

int main()
{
    //freopen("job.inp","r",stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    sort(a+1,a+n+1,cmp);

    int exc = 0,_max = 0;
    priority_queue <int,vector<int>,greater<int> > qu;

    for (int i = 1; i <= n; i++)
    {
        if ( a[i].first > _max ) {
            exc += a[i].first - _max - 1;
            _max = a[i].first;
            qu.push(a[i].second);
            ans += a[i].second;
        }
        else
        {
            if ( exc > 0 )
            {
                qu.push(a[i].second);
                ans += a[i].second;
                --exc;
            }
            else
            {
                int k = qu.top();
                if ( a[i].second > k ) {
                    ans -= k;
                    ans += a[i].second;
                    qu.pop();
                    qu.push(a[i].second);
                }
            }
        }
    }
    cout << ans;
}
