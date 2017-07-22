#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;

typedef long long LL;
typedef pair <int,int> ii;
struct data{
    LL time, index, pos;
};

int T, n, k, t;
LL s[N], p[N], res[N], cs[N];
data a[N], la[N];
data b[N];

bool cmp(data A, data B)
{
    return A.time < B.time;
}

bool cmp_2(data A, data B)
{
    return (A.pos < B.pos || ( A.pos == B.pos && A.index < B.index ) );
}

int main()
{   //freopen("CW004.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> T;
    while ( T-- ) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                    cin >> a[i].time >> a[i].pos;
                    a[i].index = i;
                    cs[i] = i;
            }
            int C;
            cin >> C;
            for (int i = 1; i <= C; i++) {
                    cin >> b[i].time >> b[i].index;
                    b[i].pos = i;
            }

            sort(b+1,b+C+1,cmp);

            LL t = 0;
            int l = 0,lc;
            for (int i = 1; i <= C; i++) {
                    lc = 0;
                    for (int j = l+1; j <= n; j++)
                        if ( a[j].pos > 0 ){
                            a[j].pos -= 1LL*(b[i].time - t)*a[j].time ;
                            if ( a[j].pos < 0 ) {
                                    a[j].pos += 1LL*(b[i].time - t)*a[j].time;
                                    la[++lc].pos = (a[j].pos + a[j].time -1 ) / a[j].time;
                                    la[lc].index = a[j].index;
                                    a[j].pos = 0;
                            }
                        }
                    sort(la+1,la+lc+1,cmp_2);
                    sort(a+1,a+n+1,cmp_2);

                    for (int j = 1; j <= lc; j++) {
                            ++l;
                            p[la[j].index] = l;
                    }

                    if ( !res[b[i].pos] ) {
                    if ( p[b[i].index] ) res[b[i].pos] = p[b[i].index];
                    else
                    for (int j = 1; j <= n; j++)
                        if ( a[j].index == b[i].index ) {
                                res[b[i].pos] = j;
                                break;
                        }
                    }
                    t = b[i].time;

            }

            for (int i = 1; i <= C; i++) {
                    cout << res[i] << endl;
            }

    }

}
