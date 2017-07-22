#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
ifstream fi("CAU6.inp");
ofstream fo("CAU6.out");
typedef long long LL;
typedef pair <LL,LL> ii;

LL s,k,n;
ii a[N];

int main()
{
    fi >> s >> k >> n;
    for (int i = 1; i <= n; i++) fi >> a[i].first >> a[i].second;

    int m = n;
    priority_queue <LL> qu;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) {
        if ( a[i].first > s ) {
            m = i;
            break;
        }
        qu.push(a[i].second);
    }
    LL d = 0;
    while ( k > 0 ) {

        for (int &i = m; i <= n; i++) {
            if ( a[i].first - s > d ) break;
            qu.push(a[i].second);
        }
        k--;
        if ( !qu.empty() ) {
            d += qu.top();
            qu.pop();
        }
        else break;
    }
    fo << s + d ;

}
