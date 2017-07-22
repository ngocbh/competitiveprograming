#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
LL ans;
int n , k;
int a[N], ca[N], t[N], f[N], cf[N];
int main()
{
    //freopen("CHINSM.inp","r",stdin);
    cin >> n  >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= N - 10; i++) ca[i] = cf[i] = n+1;
    int it = 0;
    for (int i = 1; i <= n; i++) {
        if ( a[i] == k ) it = i;
        if ( a[i] > k && cf[it] == n+1 ) cf[it] = i;
    }
    int mins = n+1, ms = n+1, ci;
    ans = 1LL*n*(n+1)/2; it = n+1;
    for (int i = n; i > 0; i--) {
        ms = n+1; ci = n+1;
        if ( a[i] == k )  ms = cf[i];   else
        for (int j = 1; j <= (int) (sqrt(a[i]-k)); j++ )
            if ( (a[i]-k) % j == 0 ) {
                        if ( ca[j] < ms && a[i] % j == k ) ms = ca[j];
                        if ( ca[(a[i]-k)/j] < ms && a[i] % ((a[i]-k)/j)  == k ) ms = ca[(a[i]-k)/j];
            }
        ca[a[i]] = i;
        if ( ms < it ) {
            ans -= i * (it-ms);
            it = ms;
        }
    }
    cout << ans ;
}












/*#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
int a[N],ca[N*N];
ii b[N*N], bb[N*N];
int n, k, ans;
bool cmp(ii x,ii y)
{
    return x.second - x.first  < y.second - y.first;
}
void solvesub2()
{
    int scs = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if ( a[i] % a[j] == k ) {
                bb[++scs] = ii(i,j);
            }
    memset(ca,true,sizeof ca);
     sort(bb+1,bb+scs+1,cmp);
     int cs  = 0;
    for (int i = 1; i <= scs; i++)
        if ( ca[i] ) {
                b[++cs] = bb[i];
                for (int j = i + 1; j <= scs; j++)
                    if ( bb[j].first <= bb[i].first && bb[j].second >= bb[i].second  )
                        ca[j] = false;
        }
    sort(b+1,b+cs+1);
    int it = 0;
    ans = n*(n+1) / 2;
    for (int i = 1; i <= cs; i++){
        ans -= (b[i].first - it)*(n - b[i].second+1);
        it = b[i].first;
    }
    cout << ans;
}
bool check(int i,int j)
{
    for (int ii = i; ii <= j-1; ii++)
        for (int jj = ii+1; jj<=j; jj++)
                    if ( a[ii] % a[jj] == k ) {
                            return true;
                    }
    return false;
}
void solvesub1()
{
    ans = n*(n+1)/2;
    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
                if ( check(i,j) ) {
                        --ans;
                       // cout << i << " " << j << " " << ans << endl;
                }

        }
    }
    cout << ans;
}
int main()
{   //freopen("CHINSM.inp","r",stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //if (n <= 100 ) solvesub1(); else
    solvesub2();
}
*/
