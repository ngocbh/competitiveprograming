#include <iostream>
#include <memory.h>
#include <stdio.h>
const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

LL m, h1, a1, x1, y1, h2, a2, x2, y2;
LL a[N], b[N];

ii solve(LL m,LL h1,LL x1, LL y1,LL a1)
{
    LL ck0 = 0, ck = 0, cs = 0;
    // tim ck0;
    memset(a,0,sizeof a);
    while (true){
            h1 = (h1*x1 + y1) % m;
            ++cs;
            if ( !a[a1] && h1 == a1 ) {
                    a[a1] = 1;
                    ck0 = cs;
                    cs = 0;
                    memset(a,0,sizeof a);
            }
            if ( a[a1] && h1 == a1 ) {
                    ck = cs;
                    break;
            }
            if (a[h1]) {
                    break;
            }
            a[h1] = 1;
    }
    return ii(ck0,ck);
}

int main()
{   //freopen("A.inp","r",stdin);
    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;
    ii A,B;
    A = solve(m,h1,x1,y1,a1);
    B = solve(m,h2,x2,y2,a2);
    //cout << A.first << " " << A.second << endl << B.first << " " << B.second << endl;
    if ( A.second == 0 && B.second == 0 ) { cout << -1; return 0; }

    if ( B.second == 0 ) {
        if (( B.first - A.first ) % A.second == 0 && B.first >= A.first ) cout <<B.first;
        else cout <<-1;
        return 0;
    }
    if ( A.second == 0 ) {
        if ( (A.first - B.first ) % B.second == 0 && A.first >= B.first ) cout << A.first;
        else cout << -1;
        return 0;
    }
    if ( A.first > B.first ) swap(A,B);
    for (int i = 0; i <= N; i++) {
        if (i*A.second + A.first >= B.first )
        if ( ((A.second*i) % B.second) == ((B.first - A.first) % B.second) ) {
                cout << i*A.second + A.first;
                return 0;
        }
    }
    cout <<-1;
    return 0;

}
