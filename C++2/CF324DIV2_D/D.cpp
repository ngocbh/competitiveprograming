#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;

int n;

bool check(int x)
{
    for (int i = 2; i*i <= x; i++) {
        if ( x % i == 0 ) return false;
    }
    return true;
}

int main()
{   //freopen("D.inp","r",stdin);
    cin >> n;

    if ( check(n) ) {
        cout << 1 << endl;
        cout << n;
        return 0;
    }

    if ( n == 4 || n == 6 ) {
        cout << 2 << endl;
        cout << n/2 << " " << n/2 ;
        return 0;
    }

    int a = 0,b,c;
    while ( !check(n) ) --n,++a;
    if ( check(a) ) {
        cout << 2 << endl;
        cout << n << " " << a;
        return 0;
    }

    for (int i = 2; i <= a; i++) {
        if ( check(i) && check(a-i) ) {
            cout << 3 << endl;
            cout << n << " " << i << " " << a-i;
            return 0;
        }
    }

}
