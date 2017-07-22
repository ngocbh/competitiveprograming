#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n;
int x[N], y[N], ca[N];
vector <int> a[2*N];
bool cmp(int i,int j)
{
    return y[i] > y[j];
}
int main()
{   freopen("BAI2.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
    }
    sort(x + 1, x + n + 1, cmp);
    sort(y + 1, y + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
            x[i] += 10000;
            y[i] += 10000;
            ca[i] = true;
            for (int j = x[i]; j <= y[i]; j++)
                    a[j].push_back(i);
    }
    for (int i = 0;  i <= 20000; i++ ) {
            a[i].push_back(n+1);
            int t = a[i].size() -1;
            for (int j = 0; j <= a[i].size()-1; j++) {
                    if ( ca[a[i][j]] ) t = a[i];
            }
            for (int j = a[i].size()-1; j >= 0; j++) {
                    if ( ca[a[i][j]] ) {
                            ca[ca[i][j]] = false;
                    }
            }
    }

}
