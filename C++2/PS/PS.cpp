#include <bits/stdc++.h>
#define x first
#define y second
#define cin fi
#define cout fo
const long N = 1000000 + 10;
const long long oo = 1000000000 + 7;
const double Eps = 1e-5;

using namespace std;
ifstream fi("PS.inp");
ofstream fo("PS.out");

typedef long long LL;
typedef pair <LL,LL> ii;

LL n, p, q;
double pp;

double chia(LL a,LL b)
{
    if ( b == 0 ) return oo;
    else return (double)a/b;
}

void calc(ii a, ii b, ii cur)
{
    LL d1 = cur.x*q;
    LL d2 = cur.y*p;
    if ( cur.x == p && cur.y == q ) return;

    if ( d1 > d2 ) {
        cout << "L";
        calc(a,cur,ii(a.x+cur.x,a.y+cur.y));
        return;
    }
    if ( d2 > d1 ) {
        cout << "R";
        calc(cur,b,ii(cur.x+b.x,cur.y+b.y));
    }
}

int main()
{   //freopen("PS.inp","r",stdin);
    //freopen("PS.out","w",stdout);

    while ( true ) {
        cin >> p >> q;
        if ( p == 1 && q == 1 ) break;
        pp = (double) p/q;
        calc(ii(0,1),ii(1,0),ii(1,1));
        cout << endl;

    }
}
