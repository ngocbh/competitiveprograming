#include <bits/stdc++.h>

using namespace std;

const long N = 1000 + 10;
vector <int> cur, prev;
int n, k;

int main()
{
    freopen("apple.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    prev.push_back(n*2);
    for (int i = 1;  i <= k; i++) {
        for (int j = 0; j < prev.size(); j++) {
            if ( prev[j] % 2 == 0 )
                cur.push_back(prev[j]/2);
            if ( prev[j] > 0 ) cur.push_back(prev[j] - 1);
        }

        prev = cur;
        sort(prev.begin(),prev.end());
        vector <int> ::iterator it = unique(prev.begin(),prev.end());
        prev.resize( std::distance(prev.begin(),it) );
        cur.clear();
    }

    cout << prev.size() << endl;
    for (int i = 0; i < prev.size(); i++)
            cout << fixed << setprecision(1) << (double)prev[i]/2 << " ";
}
