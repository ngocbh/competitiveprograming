#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
int n, t;
bool ca[N];
vector <int> a;
int main()
{   //freopen("C.inp","r",stdin);

    ca[1] = true;
    for (int i = 2; i < N; i++)
        if ( !ca[i] ) {
            a.push_back(i);
            for (int j = 2; j*i < N; j++) ca[i*j] = true;
        }

    cin >> t;

    while ( t-- ) {
        cin >> n;
        vector <int> ::iterator it;
        it = lower_bound(a.begin(),a.end(),n);
        int ans = N;
        ans = min(ans,abs(n-*it));
        it--;
        ans = min(ans,abs(n-*it));
        it += 2;
        ans = min(ans,abs(n-*it));
        cout << ans << endl;
    }

}
