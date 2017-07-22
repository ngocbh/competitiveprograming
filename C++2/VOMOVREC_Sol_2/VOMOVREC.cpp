#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const long N = 100000 + 10;
const long oo = 2000000000 + 7;

typedef long long LL;
typedef pair <LL,LL> ii;

struct data {
    LL co[5];
    void init()
    {
        co[1] = -oo; co[2] = -oo; co[3] = oo; co[4] = oo;
    }

    bool check()
    {
        if ( co[1] > co[3] ) return true;
        if ( co[2] > co[4] ) return true;
        return false;
    }

};

int n;
data a[N], b[N];

data intersection(data A, data B)
{
    data C;
    C.co[1] = max(A.co[1],B.co[1]);
    C.co[2] = max(A.co[2],B.co[2]);
    C.co[3] = min(A.co[3],B.co[3]);
    C.co[4] = min(A.co[4],B.co[4]);
    return C;
}

bool check(LL val)
{
    for (int i = 1; i <= n; i++) {
        b[i].co[1] = a[i].co[1] - val;
        b[i].co[2] = a[i].co[2] - val;
        b[i].co[3] = a[i].co[3] + val;
        b[i].co[4] = a[i].co[4] + val;
    }

    data A; A.init();

    for (int i = 1; i <= n; i++) {
        A = intersection(A,b[i]);
        if ( A.check() ) return false;
    }
    return true;
}

int main()
{
    //freopen("VOMOVREC.inp","r",stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        LL A, B, C, D;
        cin >> A >> B >> C >> D;
        ++A, ++B;
        a[i].co[1] = A; a[i].co[2] = B; a[i].co[3] = C; a[i].co[4] = D;
    }

    LL l = -1, r = oo, mid;
    while ( l + 1 < r )
    {
        mid = ( l + r ) / 2;
        if ( !check(mid) ) l = mid;
        else r = mid;
    }

    cout << r;
}
