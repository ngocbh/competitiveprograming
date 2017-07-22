#include <iostream>
#include <stdio.h>
const long N = 500 + 10;
using namespace std;
int x[N], y[N];
char c[N];
int a[N][N];

bool check(int x1,int y1,char c1,int x2,int y2,char c2,int x3,int y3,char c3)
{
    if ( y1 == y2 && y2 == y3 && (x1 + x2 + x3) == y1 ) {
        int n = y1;
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ( j <= x1 ) cout << c1;
                else
                    if ( j <= x1+x2 ) cout << c2;
                    else
                        if ( j <= x1+x2+x3 ) cout << c3;
            }
            cout << endl;
        }
        return true;
    }
    if ( x1 == x2 && x2 == x3 && (y1 + y2 + y3) == x1 ) {
        int n = x1;
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ( i <= y1 ) cout << c1;
                else
                    if ( i <= y1 + y2 ) cout << c2;
                    else
                        if ( i <= n ) cout << c3;
            }
            cout << endl;
        }
    return true;
    }

    if ( y1 == y2 + y3 && x2 == x3 && x1 + x3 == y1 ) {
        int n = y1;
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                    if ( j <= x1 ) cout << c1;
                    else {
                        if ( i <= y2 ) cout << c2;
                        else
                            if ( i <= y2 + y3 ) cout << c3;
                    }
            }
             cout << endl;
        }
        return true;
    }

    if ( y2 == y3 && (y2 + y1) == x1 && x1 == x2 + x3 ) {
        int n = x1;
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) {
                    if ( i <= y1 ) cout << c1;
                    else {
                        if ( j <= x2 ) cout << c2;
                        else
                            if ( j <= n ) cout << c3;
                    }
            }
            cout << endl;
        }
            return true;
    }
    return false;

}

int main()
{
    //freopen("D.inp","r",stdin);
    for (int i = 1; i <= 3; i++) cin >> x[i] >> y[i];
    c[1] = 'A'; c[2] = 'B'; c[3] = 'C';
    ///=== TH1;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                if ( i != j && j != k && k != i ){
                        if ( check(x[i],y[i],c[i], x[j],y[j],c[j], x[k],y[k],c[k]) ) return 0;
                        if ( check(y[i],x[i],c[i], x[j],y[j],c[j], x[k],y[k],c[k]) ) return 0;
                        if ( check(x[i],y[i],c[i], y[j],x[j],c[j], x[k],y[k],c[k]) ) return 0;
                        if ( check(x[i],y[i],c[i], x[j],y[j],c[j], y[k],x[k],c[k]) ) return 0;

                        ///doi2
                        if ( check(y[i],x[i],c[i], y[j],x[j],c[j], x[k],y[k],c[k]) ) return 0;
                        if ( check(y[i],x[i],c[i], x[j],y[j],c[j], y[k],x[k],c[k]) ) return 0;
                        if ( check(x[i],y[i],c[i], y[j],x[j],c[j], y[k],x[k],c[k]) ) return 0;
                        ///doi3
                        if ( check(y[i],x[i],c[i], y[j],x[j],c[j], y[k],x[k],c[k]) ) return 0;
                }
    cout << -1;

}
