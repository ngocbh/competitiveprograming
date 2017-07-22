#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n ,A , B;

bool check(int l,int r,int t,int m)
{
    LL al, ar, sum;
    al = A + 1LL*(l-1) * B;
    ar = A + 1LL*(r-1) * B;
    if ( ar > t ) return false;
    sum = 1LL * ((al + ar) * (r-l+1) / 2 );
    if ( sum > 1LL*t*m ) return false;
    return true;
}

int main()
{   //freopen("A.inp","r",stdin);
    cin >> A >> B >> n;
    while ( n-- ) {
            int l, t, m, ans = -1;
            cin >> l >> t >> m;
            int low = l, high = 2*N;
            while ( low <= high ) {
                    int mid = ( low + high ) / 2;
                    if ( check(l,mid,t,m) )
                            low = mid + 1,ans = mid;
                    else
                            high = mid - 1;
            }
            cout << ans << endl;
    }

}
