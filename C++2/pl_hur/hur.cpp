/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 250000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n;
int ca[N], a[N], b[N];
LL sum = 0;

int main()
{
    //freopen("hur.inp","r",stdin);
    //freopen("hur.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    priority_queue <ii> qu;
    qu.push(ii(-1,0));

    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if ( sum >= b[i] ) {
            qu.push(ii(b[i],i));
            sum -= b[i];
            ca[i] = true;
        }
        else {
            if ( b[i] < qu.top().first ) {
                sum += qu.top().first - b[i];
                ca[qu.top().second] = false;
                ca[i] = true;
                qu.pop();
                qu.push(ii(b[i],i));
            }
        }
    }

    cout << qu.size() - 1 << endl;
    for (int i = 1; i <= n; i++)
        if ( ca[i] )
            cout << i << " ";

}
