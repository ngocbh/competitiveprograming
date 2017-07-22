#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{      // freopen("P156SUMH.inp","r",stdin);
        cin >> n;
        int dem = 1;
        for (int i = 1; i <= n; i++) {
            for  (int j = 1; j <= ( n - dem ) / 2; j++) cout<<"*";
            for (int j = 1; j <= dem; j++) cout << "D";
            for (int j = 1; j <= (n - dem) / 2; j++) cout << "*";
            if ( i < (n+1)/2 ) dem += 2;
                else dem -= 2;
            cout << endl;
        }

}
