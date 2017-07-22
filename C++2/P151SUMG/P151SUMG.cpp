#include <bits/stdc++.h>
///Bai H
const long N = 70;
using namespace std;

int64_t n, t, x, y, ans;
int64_t d1[N], d2[N],d[N],ca[N];

void init()
{       ca[0] = 1;
        for (int i = 1; i <= 64; i++) ca[i] = ca[i-1]*2;
        memset(d1,0,sizeof d1);
        memset(d2,0,sizeof d2);
        memset(d,0,sizeof d);
}

void count_d(int64_t d[], int64_t a)
{   int i = 0;
    while ( a > 0 ) {
        d[i++] = a % 2;
        a /= 2;
    }
}

void solve()
{
    int i = 64,ak47=0;
    while ( d1[i] == d2[i] ) {
        d[i] = d1[i];
        --i;
    }
    for (int j = i; j >= 0; j--) {
        if ( d2[j] == 0 )
            ++ak47;
    }

    if ( ak47 == 0 ) {
        for (int j = i; j >= 0; j--) {
                d[j] = 1;
        }
    } else {
        d[i] = 0;
        for (int j = i-1; j >= 0; j--) {
                d[j] = 1;
        }
    }
}

void count_ans()
{   ans = 0;
    for (int i = 0; i <= 65; i++){
            ans += d[i] * ca[i];
    }
    printf("%lld\n", ans);
}

int main()
{   freopen("P151SUMG.inp","r",stdin);
    scanf("%d", &t);
    while (t--){
        scanf("%lld %lld ", &x, &y);
        init();
        count_d(d1,x);
        count_d(d2,y);
        solve();
        count_ans();
    }

}
