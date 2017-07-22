#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
string s;
string x[10], y[10];
int a[10];

int main()
{   //freopen("VIETCHU.inp","r",stdin);
    cin >> s;
    int n;
    n = s.size();
    for (int i = 1; i <= n; i++) a[i] = s[i-1] - '0';

    x[1] = ""; x[2] = "muoi"; x[3] = "tram"; x[4] = "nghin";
    y[0] = "khong"; y[1] = "mot"; y[2] = "hai"; y[3] = "ba"; y[4] = "bon"; y[5] = "nam"; y[6] = "sau"; y[7] = "bay"; y[8] = "tam"; y[9] = "chin";

    if ( n == 1 && a[1] == 0 ) {
        cout << "khong ";
        return 0;
    }


    if ( n <= 4 ) {
    for (int i = 1; i <= n; i++) {
        if ( i == n-1 && a[i] == 0 && a[i+1] != 0 ) { cout << "le "; continue; }
        if ( i == n && a[i-1] == 0 && a[i] == 5 ) { cout << "nam "; continue;}
        if ( i == n && a[i] == 0 ) { continue; }
        if ( (i == n-1 ) && a[i] == 0 ) continue;
        if ( i == n && a[i] == 5 && n != 1 ) { cout << "lam "; continue; }
        if ( a[i] == 1 && i == n-1 ) { cout << "muoi "; continue; }
        if ( a[i] == 0 && a[i+1] == 0 && a[i+2] == 0 ) return 0;
        if ( i == 1 && n == 5 && a[i] == 1 ) cout << x[n+1-i] << " ";
        else
            cout << y[a[i]] << " " << x[n+1-i] << " ";

    }
    return 0;
    }

    for (int i = 1; i <= n-3; i++) {
        if ( i == 2 && a[i] == 0 && a[i+1] != 0 ) { cout << "le "; continue; }
        if ( i == n-3 && a[i-1] == 0 && a[i] == 5 ) { cout << "nam "; continue;}
        if ( i == n-3 && a[i] == 0 ) { continue; }
        if ( (i == n-3 || i == n-4 ) && a[i] == 0 ) continue;
        if ( i == n-3 && a[i] == 5 && n != 1 && a[i-1] != 0 ) { cout << "lam "; continue; }
        if ( a[i] == 1 && i == n-4 ) { cout << "muoi "; continue; }
        if ( i == 1 && n == 5 && a[i] == 1 ) cout << x[n-3+1-i] << " ";
        else
            if ( i == n-3 ) cout << y[a[i]] << " ";
        else
            cout << y[a[i]] << " " << x[n-3+1-i] << " ";

    }
    cout << "nghin ";
    for (int i = n-2; i <= n; i++) {
        if ( i == n-1 && a[i] == 0 && a[i+1] != 0 ) { cout << "le "; continue; }
        if ( i == n && a[i-1] == 0 && a[i] == 5 ) { cout << "nam "; continue;}
        if ( i == n && a[i] == 0 ) { continue; }
        if ( (i == n-1 ) && a[i] == 0 ) continue;
        if ( i == n-2 && a[i] == 0 && a[i+1] == 0 && a[i+2] == 0 ) return 0;
        if ( i == n && a[i] == 5 && n != 1 ) { cout << "lam "; continue; }
        if ( a[i] == 1 && i == n-1 ) { cout << "muoi "; continue; }
        if ( i == 1 && n == 5 && a[i] == 1 ) cout << x[n+1-i] << " ";
        else
            cout << y[a[i]] << " " << x[n+1-i] << " ";

    }


}
