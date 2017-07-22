/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
struct data {
    ii p[6];
};

int n;
data rect[N];

bool in(data A,int x,int y)
{
    A.p[5] = A.p[1];

    int areac = kc(A.p[1],A.p[2])*kc(A.p[2],A.p[3]);
    for (int i = )
}

bool check(int x,int y)
{
    for (int i =  1; i <= n; i++)
        if ( !in(rect[i],x,y) ) return false;
    return true;
}

int main()
{
    freopen("PVOI14_1.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) cin >> p[i].x >> p[i].y;
    }

    int ans = 0;

    for (int i = -100; i <= 100; i++)
        for (int j = -100; j <= 100; j++) {
            if ( check(i,j) ) ++ans;
        }

    cout << ans;
}
