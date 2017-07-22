/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <iostream>
#include <stdio.h>

#define x first
#define y second

const long N = 100000 + 10;
const long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef pair <int,int> ii;
typedef long long LL;

int n, t;
int x1,x2,x3,y1,y2,y3;

bool solve(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if ( x1 == x2 && x2 == x3 && y1 + y2 + y3 == x1 ) {
        cout << x1 << endl;
        return true;
    }

    if ( y1 == y2 && y2 == y3 && x1 + x2 + x3 == y1 ) {
        cout << y1 << endl;
        return true;
    }

    if ( x1 == x2+x3 && y2 == y3 && y1+y2 == x1 ) {
        cout << x1 << endl;
        return true;
    }

    if ( x2 == x3+x1 && y1 == y3 && y2+y1 == x2 ) {
        cout << x2 << endl;
        return true;
    }

    if ( x3 == x1+x2 && y1 == y2 && y1+y3 == x3 ) {
        cout << x3 << endl;
        return true;
    }

    return false;
}

int main()
{   freopen("GH.inp","r",stdin);
    //freopen("GH.out","w",stdout);
    cin >> t;
    while ( t-- ) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if ( solve(x1,y1,x2,y2,x3,y3) ) continue;

        if ( solve(y1,x1,x2,y2,x3,y3) ) continue;
        if ( solve(x1,y1,y2,x2,x3,y3) ) continue;
        if ( solve(x1,y1,x2,y2,y3,x3) ) continue;

        if ( solve(y1,x1,y2,x2,x3,y3) ) continue;
        if ( solve(y1,x1,x2,y2,y3,x3) ) continue;
        if ( solve(x1,y1,y2,x2,y3,x3) ) continue;

        if ( solve(y1,x1,y2,x2,y3,x3) ) continue;

        cout << 0 << endl;
    }
}
