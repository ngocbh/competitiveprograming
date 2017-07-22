#include <bits/stdc++.h>

using namespace std;

const long N = 20 + 5;
const long long MOD1 = 1000000000 + 7;
const long long MOD2 = 10000000 + 3;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, ans;
LL a[N], x[N];
set <ii> M;

void ktkq()
{
    long long tuso = a[1], mauso = a[1];
    for (int i = 3; i <= n; i++)
        if ( x[i] == 1 ) tuso = (tuso*a[i]) % MOD1, mauso = (mauso*a[i]) % MOD2;

    if ( M.insert(ii(tuso,mauso)).second )
        ++ans,M.insert(ii(tuso,mauso));
}

void duyet(int i)
{
    if ( i > n )
    {
        ktkq();
        return ;
    }
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        duyet(i+1);
    }
}

int main()
{
        freopen("EXP3.inp","r",stdin);
        freopen("EXP3.out","w",stdout);

        while ( scanf("%d", &n) > 0 )
        {
            M.clear();
            for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
            x[1] = 1; x[2] = 0; ans = 0;
            duyet(3);
            printf("%d\n", ans);

        }

}
