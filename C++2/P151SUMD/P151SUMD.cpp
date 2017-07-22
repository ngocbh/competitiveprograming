#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;

int n;
long long ans = 0, res ;
int ca[N], ta[11], f[N][11], met[N];
long long a[N];
bool check(int64_t x, int y)
{
    while( x > 0 ) {
            if ( x % 10 == y ) return true;
            x /= 10;
    }
    return false;
}

int main()
{       freopen("P151SUMD.inp","r",stdin);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)    {
                scanf("%lld", &a[i]);
        }
        memset(ca, 0 , sizeof ca);
        memset(f, 0 , sizeof f);
        for (int i = 0; i <= 9; i++)
                for (int j = 1; j <= n; j++)
                        if ( check(a[j],i) ) f[j][i] = 1;


        for (int o = 0; o <= 9; o++){
                res = 0;
                int ii;
                memset(ta,0,sizeof ta);
                for (int i = 1; i <= n; i++) {
                        if ( f[i][o] && ca[i] == 0 ) {
                                ++res;
                                ca[i] = 1;
                        }
                }
                cout<<o<<" "<<res<<" "<<ans<<endl;
                if ( res == 1 ) {
                    for (int i = 1; i <= n; i++) {
                            if ( ca[i] == 1 ) { ca[i] = 3; ii = i; }
                            met[i] = true;
                    }
                   // cout<<ii<<" "<<o<<endl;
                    for (int k = o; k <= 9; k++)
                      for (int i = 1; i <= n; i++)
                            if ( ca[i] != 3 && f[i][k] && f[ii][k] && met[i] && i != ii ) { ++ans; met[i] = false; }
                      for (int i = 1; i <= n; i++)
                            if ( ca[i] == 1 ) ca[i] = 3;
                      continue;
                }
                ans += res*(res-1) / 2;
                for (int k = o+1; k <= 9; k++) {
                    for (int i = 1; i <= n; i++) {
                            if ( ca[i] == 1 && f[i][k] ) {
                                        ++ta[k];
                            }
                    }
                    for (int i = 1; i <= n; i++) {
                            if ( ca[i] == 2 && f[i][k] ) {
                                        ans += ta[k];
                                        cout<<ans<<" ";
                            }
                    }
                    cout<<"**";
                }
                for (int i = 1; i <= n; i++) {
                            if ( ca[i] == 1 ) {
                                        ca[i] = 2;
                            }
                }
                for (int i = 0; i <= 9; i++) cout<<ta[i]<<" "; cout<<endl;
        }
        printf("%lld", ans);
}
