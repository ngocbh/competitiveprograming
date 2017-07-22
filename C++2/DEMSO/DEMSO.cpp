/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

LL n, x;
int a[N], p[N];

int main()
{
    //freopen("DEMSO.inp","r",stdin);
    //freopen("DEMSO.out","w",stdout);
    ios::sync_with_stdio(0);

    for (int i = 2; i < N; i++) {
        if ( p[i] != 0 ) continue;
        p[i] = i;
        for (int j = i; j < N; j+=i) {
            if ( !p[j] ) p[j] = i;
        }
    }

    for (int i = 2; i <= N-10; i++) {
        ++a[p[i]];
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if ( x > N - 10 ) { cout << 0 << endl; continue;}
        cout << a[x] << endl;
    }

}
