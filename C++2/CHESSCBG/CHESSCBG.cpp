#include <bits/stdc++.h>

const long N = 17;
using namespace std;

int n ,x[N], f[N], cf, ans = 1000, ca[N];
string a = "0", b = "0";

void ktkq()
{
    int res = 0;
    for (int i = 1; i <= cf/2; i++) {
        int u1,v1,u2,v2;
        u1 = (f[i]-1) / 4 + 1;
        v1 = (f[i] % 4) + 4 * ( f[i] % 4 == 0 );
        u2 = (f[x[i]]-1) / 4 + 1;
        v2 = (f[x[i]] % 4) + (f[x[i]] % 4 == 0 ) * 4;
        res += abs(u1-u2) + abs(v1-v2);
    }
    ans = min(ans,res);

}

void dfs(int i)
{
    if ( i > cf / 2 ) {
        ktkq();
        return;
    }
    for (int j = cf/2+1; j <= cf; j++)
        if ( ca[j] ) {
            x[i] = j;
            ca[j] = false;
            dfs(i+1);
            ca[j] = true;
        }
}

int main()
{   //freopen("CHESSCBG.inp","r",stdin);
    for (int i = 1; i <= 4; i++)
    {
        string s;
        cin >> s;
        a += s;
    }

    for (int i = 1; i <= 4; i++) {
        string s;
        cin >> s;
        b += s;
    }

    cf = 0;
    for (int i = 1; i <= 16; i++)
        if ( a[i] != b[i] ) ++cf;

    int id = 1, ic = cf/2+1;
    for (int i = 1; i <= 16; i++)
        if ( a[i] != b[i] )
            if ( a[i] == '1' )
                f[id++] = i;
            else f[ic++] = i;

    //for (int i = 1; i <= cf; i++) cout << f[i] << " ";
    memset(ca,true,sizeof ca);
    dfs(1);
    cout << ans ;
}
