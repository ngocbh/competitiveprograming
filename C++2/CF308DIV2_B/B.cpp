#include <bits/stdc++.h>

using namespace std;
int64_t n,nn,ii;
int64_t res;
int64_t pow1(int64_t x)
{   int64_t rr = 1;
    for (int i = 1; i <= x; i++)
        rr *= 10;
    return rr;
}
int main()
{   //freopen("B.inp","r",stdin);
    scanf("%d",&n); nn = n; ii = -1;
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    while ( nn > 0 ){
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        ++ii;
        nn = nn / 10;
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    }
    for (int i = 1; i <= ii; i++)
        res += i * 9 * pow1(i-1);
    res += (n - pow1(ii) + 1) * (ii+1);
    cout<<res;
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
}
