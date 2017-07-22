/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define cin fi
#define cout fo

const long N = 1000000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
//ifstream fi("US.inp");
//ofstream fo("US.out");

typedef long long LL;
typedef pair <int,int> ii;

LL n, t;
LL a, b;
LL ca[N], p[N], sm[N], pos[N];
LL num[N], sum[N], total_sum[N], total_num[N];
LL _pow[N/10][20], pp[N/10][20];

void init()
{
    memset(ca,true,sizeof ca);

    for (int i = 2; i < N; i++) {
        if ( !ca[i] ) continue;
        p[i] = i;
        for (int j = 2; i*j < N; j++) {
            p[i*j] = i;
            ca[i*j] = false;
        }
    }

    int m = 0;
    for (int i = 2; i <= N; i++) {
        if ( ca[i] ) {
            _pow[++m][0] = pp[m][0] = 1;
            pos[i] = m;
            int x = i;
            for (int j = 1; j <= 20; j++) {
                pp[m][j] = x;
                _pow[m][j] = _pow[m][j-1] + x, x *= i;
                if ( x > N ) break;
            }
        }
    }

    for (int i = 2; i < N; i++) {
        int x = i;
        while ( x % p[i] == 0 ) {
            ++sm[i];
            x /= p[i];
        }
    }

    num[1] = sum[1] = 1;
    for (int i = 2; i < N; i++) {
        int x = i / pp[pos[p[i]]][sm[i]];
        num[i] = num[x]*(sm[i]+1);
        sum[i] = sum[x]*_pow[pos[p[i]]][sm[i]];
    }
    for (int i = 1; i <= N; i++) {
        total_num[i] = total_num[i-1] + num[i];
        total_sum[i] = total_sum[i-1] + sum[i];
    }
}

int main()
{
    freopen("US.inp","r",stdin);
    freopen("US.out","w",stdout);


    init();
    int t;
    //cin >> t;
    scanf("%lld", &t);

    while ( t-- ) {
        scanf("%lld %lld", &a, &b);
        //printf("%lld %lld\n" , a, b);
        //cout << total_num[b] - total_num[a-1] << " " << total_sum[b] - total_sum[a-1] << endl;
        printf("%lld %lld\n",total_num[b] - total_num[a-1], total_sum[b] - total_sum[a-1]  );
    }
}
