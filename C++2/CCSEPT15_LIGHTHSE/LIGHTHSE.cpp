#include <bits/stdc++.h>

const long N = 5 * 100000 + 10;
const long oo = 1000000000 + 10;
using namespace std;
typedef long long LL;
struct data{
    int x,y;
};
int n, t;
data P[N];

int main()
{       //freopen("LIGHTHSE.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin >> t;
        while ( t-- ) {
                cin >> n;
                for (int i = 1; i <= n; i++) cin >> P[i].x >> P[i].y;
                int ans = 3;
                ///====ans = 1;
                int minx = oo , maxx = -oo, miny = oo , maxy = -oo;
                for (int i = 1; i <= n; i++) {
                    minx = min(minx , P[i].x);
                    maxx = max(maxx , P[i].x);
                    miny = min(miny , P[i].y);
                    maxy = max(maxy , P[i].y);
                }
                for (int i = 1; i <= n; i++) {
                    if ( P[i].x == minx && P[i].y == miny ) {
                        cout << 1 << endl;
                        cout << i << " NE" << endl;
                        ans = 1;
                        break;
                    }
                    if ( P[i].x == minx && P[i].y == maxy ) {
                        cout << 1 << endl;
                        cout << i << " SE" << endl;
                        ans = 1;
                        break;
                    }
                    if ( P[i].x == maxx && P[i].y == miny ) {
                        cout << 1 << endl;
                        cout << i << " NW" << endl;
                        ans = 1;
                        break;
                    }
                    if ( P[i].x == maxx && P[i].y == maxy ) {
                        cout << 1 << endl;
                        cout << i << " SW" << endl;
                        ans = 1;
                        break;
                    }
                }

                if ( ans == 1 ) continue;

                ///======ans = 2;

                int min1 = oo, min2 = oo, cs1, cs2;
                for (int i = 1; i <= n; i++) {
                    if ( P[i].y < min1 ) min2 = min1, cs2 = cs1, min1 = P[i].y, cs1 = i;
                    else
                        if ( P[i].y < min2 ) min2 = P[i].y, cs2 = i;
                }

                if ( P[cs1].x > P[cs2].x ) {
                    cout << 2 << endl;
                    cout << cs1 << " NW" << endl;
                    cout << cs2 << " NE" << endl;
                }   else {
                    cout << 2 << endl;
                    cout << cs1 << " NE" << endl;
                    cout << cs2 << " NW" << endl;
                }
        }

}
