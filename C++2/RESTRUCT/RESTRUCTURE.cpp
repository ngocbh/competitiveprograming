/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define cin fi
#define cout fo
const long N = 200000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
ifstream fi("RESTRUCTURE.inp");
ofstream fo("RESTRUCTURE.out");

typedef long long LL;
typedef pair <int,int> ii;

int n, q, m;
int lad[N], _forward[N], _behind[N], f[N];
ii M[N];
vector <int> a[N];

void _union(int x,int y)
{
    if ( lad[x] == lad[y] ) return;
    int lx = lad[x];
    int ly = lad[y];
    if ( a[ly].size() < a[lx].size() ) {
        for (int i = a[ly].size()-1; i >= 0; i--) {
            int v = a[ly][i];
            a[lx].push_back(v);
            lad[v] = lad[x];
        }
        a[ly].clear();
    }
    else {
        for (int i = a[lx].size()-1; i >= 0; i--) {
            int v = a[lx][i];
            a[ly].push_back(v);
            lad[v] = lad[y];
        }
        a[lx].clear();
    }
}

void solve1()
{
    int x, y;
    cin >> x >> y;
    _union(x,y);
}

void solve2()
{
    int x, y;
    cin >> x >> y;
    int inc =  x;
    for (int i = x; i <= y; i = x+1)
        _union(x,i), x = f[i] , f[i] = y;
}

void solve3()
{
    int x, y;
    cin >> x >> y;

    if ( lad[x] == lad[y] ) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main()
{
    //freopen("RESTRUCT.inp","r",stdin);
    //freopen("RESTRUCT.out","w",stdout);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) lad[i] = i, _behind[i] = i, a[i].push_back(i), f[i] = i;
    m = n;

    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if ( type == 1 ) solve1();
        if ( type == 2 ) solve2();
        if ( type == 3 ) solve3();
    }
}
