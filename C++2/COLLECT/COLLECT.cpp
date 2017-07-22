/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

const long N = 10000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

struct data{
    int x, y, z, k;
};

int k, X , Y , Z , x0 , y0 , z0, ans;
int x[N], y[N], z[N], xx[N], yy[N], zz[N], d[N];
vector <data> res;
map <int,int> MAP;

bool cmp(data A,data B)
{
    if ( A.x != B.x ) return A.x < B.x;
    if ( A.y != B.y ) return A.y < B.y;
    return A.z < B.z;
}

int main()
{
    freopen("COLLECT.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> k;
    cin >> X >> Y >> Z >> x0 >> y0 >> z0;

    int n = 1;
    while ( scanf("%d %d %d %d %d %d", &x[n], &y[n], &z[n], &xx[n], &yy[n], &zz[n]) != EOF ) {
            //if ( x[n] < xx[n] || y[n] < yy[n] || z[n] < zz[n] ) {
                    ++n;
            //}
    }

    --n;

    queue <ii> qu;
    fill(d,d+N,N);
    qu.push(ii(X*5+Y*25+Z*125,0));
    int aa, bb, cc, A;
    while ( !qu.empty() ) {
        int B = qu.front().first;
        int c = B / 125; B -= c*125;
        int b = B / 25; B -= b*25;
        int a = B / 5; B -= a*5;

        int ki = qu.front().second;
        qu.pop();

        if ( ki == k ) continue;
        if ( a >= x0 && b >= y0 && c >= z0 ) continue;

        for (int i = 1; i <= n; i++) {
            if ( a >= x[i] && b >= y[i] && c >= z[i] ) {
                aa = a - x[i] + xx[i];
                bb = b - y[i] + yy[i];
                cc = c - z[i] + zz[i];
                A = aa*5 + bb*25 + cc*125;

                if ( aa > 4 || bb > 4 || cc > 4 ) continue;

                if ( d[A] > ki+1 ) {
                        d[A] = ki+1;
                        qu.push(ii(A,ki+1));
                }
            }
        }
    }

    int a,b,c;
    data Q;
    for (int i = 1; i <= N; i++) {
        if ( d[i] == N ) continue;
         int B = i;
         c = B / 125; B -= c*125;
         b = B / 25; B -= b*25;
         a = B / 5; B -= a*5;
         Q.x = a; Q.y = b; Q.z = c; Q.k = d[i];
         if ( a >= x0 && b >= y0 && c >= z0 ) res.push_back(Q);
    }

    sort(res.begin(),res.end(),cmp);
    if ( res.size() == 0 ) {
        cout << -1;
        return 0;
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i].x << " " << res[i].y << " " << res[i].z << " " << res[i].k << endl;
}

