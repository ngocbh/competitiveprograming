#include <bits/stdc++.h>

using namespace std;

const long N = 1000000 + 10;
const long long oo = 1000000000 + 7;

typedef pair <int,int> ii;

int n, k;
ii a[N];
vector <ii> f;

int main()
{
    //freopen("D.inp","r",stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);
    f.push_back(ii(-oo,-oo));

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, f.push_back(ii(a[i].first,1)), f.push_back(ii(a[i].second,2));

    vector <ii> res;

    sort(f.begin(), f.end());


    int open = 1;

    for (int i = 2; i <= 2*n; i++) {
        if ( open >= k )
            res.push_back(ii(f[i-1].first,f[i].first));
        if ( f[i].second == 1 )
            ++open;
        else --open;
    }

    if ( res.empty() ) { cout << 0; return 0; }
    vector <ii> ans;

    int prev = res[0].first, cur = res[0].second;
    for (int i = 1; i < res.size(); i++)
    {
        if ( res[i].first != cur ) ans.push_back(ii(prev,cur)), prev = res[i].first;
        cur = res[i].second;
    }

    ans.push_back(ii(prev,cur));

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;

}
