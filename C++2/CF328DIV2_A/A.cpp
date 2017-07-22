#include <bits/stdc++.h>

const long N = 100;

using namespace std;

char a[N][N];
string s;

int main()
{   //freopen("A.inp","r",stdin);
    for (int i = 1; i <= 8; i++)
    {
        cin >> s;
        for (int j = 1; j <= 8; j++)
            a[i][j] = s[j-1];
    }

    int ansa = 100, ansb = 100;

    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            if ( a[j][i] != '.' ) {
                if ( a[j][i] == 'W' ) ansa = min(ansa,j);
                else break;
            }

    for (int i = 1; i <= 8; i++)
        for (int j = 8; j >= 1; j--) {
            if ( a[j][i] != '.' ) {
                if ( a[j][i] == 'B' ) ansb = min(ansb,9-j);
                else break;
            }
        }

    //cout << ansa << " " << ansb << endl;
    if ( ansa <= ansb ) cout << "A";
    else cout << "B";

}
