#include <bits/stdc++.h>

const long N = 2000 + 10;
using namespace std;
typedef long long LL;
struct ii{
    int pos,stt,id;
};
int t, n, k;
int x[N], l[N], r[N];
ii a[N];

bool cmp(ii A, ii B)
{
    return A.pos < B.pos;
}

void solve(int l,int r)
{
    int cs = 0;
    for (int i = l; i <= r; i++) {
        if ( x[i] != -1 ) continue;
        x[i] = cs % 2;
        ++cs;
    }
}

int main()
{
    //freopen("CLOST.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
            cin >> n >> k;
            bool ok = true;
            if ( n  % 2 == 1 ) ok = false;
            for (int i = 1; i <= k; i++) {
                    cin >> l[i] >> r[i];
                    ++l[i], ++r[i];
                    a[i*2-1] = {l[i],0,i};
                    a[i*2] = {r[i],1,i};
                    if ( (r[i] - l[i] + 1 ) % 2 == 1 ) ok = false;
             }
            sort(a+1,a+2*k+1,cmp);
            for (int i = 1; i <= n; i++) x[i] = -1;
            for (int i = 1; i <= k*2; i++) {
                if (a[i].stt == 1) {
                    solve(l[a[i].id] , r[a[i].id]);
                }
            }
            solve(1,n);

            /*int dc[3];
            for (int i = 1; i <= k; i++) {
                    dc[1] = 0;
                    dc[0] = 0;
                    for (int j = l[i]; j <= r[i]; j++) {
                            ++dc[x[j]];
                            if ( dc[0] < dc[1]  ) continue;
                    }
                    if ( dc[0] != dc[1] ) continue;
            }*/

            //if (ok) {
            for (int i = 1; i <= n; i++)
                if ( x[i] == 0 ) cout << "(";
                else cout << ")";
            cout << endl;
           // }
    }
}
