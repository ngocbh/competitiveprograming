#include <bits/stdc++.h>

const long N = 10000;

using namespace std;
int n;

bool check(int n)
{
    for (int i = 1; i < n; i++) {
        int x = n*n - i*i;
        double tt = (double) sqrt(x);
        if ( tt == trunc(tt) && x != i*i ) {
            cout << i << " " << tt << " ";
            return true;
        }
    }
    return false;
}

int main()
{   freopen("CANTIM.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if ( check(i) ) cout << "= " << i << endl;
    }

}
