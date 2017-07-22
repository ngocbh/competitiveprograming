#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
typedef pair <LL,int> ii;
int n, m;
map <int,LL> M;
map <ii,int> S;

void solve1()
{
    int x;
    cin >> x;

    if ( M[x] == 0 ) {
            M[x] = 1;
            S[ii(0,x)] = 1;
    }
}

void solve2()
{
    int x;
    cin >> x;

    int t = M[x] - 1;
    M.erase(x);
    S.erase(ii(t,x));

}

void solve3()
{
    int x, c;
    cin >> x >> c;
    if ( M[x] > 0 ) {
            int t;
            t = M[x]-1;
            S.erase(ii(t,x));
            M[x] += c;
            t += c;
            S[ii(t,x)] = 1;
    } else {
        M.erase(x);
    }
}

void solve4()
{
    if ( M.size() == 1 ) {
        cout << "EMPTY" << endl;
        return;
    }

    int i = 3;

    for (map<ii,int> ::iterator it = S.end(); it != S.begin(); it--) {
        if ( it == S.end() ) continue;
        cout << it->first.first << " ";
        --i;
        if ( i == 0 ) {
                cout << endl;
                return;
        }
    }
    cout << endl;

}

int main()
{   freopen("JUDGER.inp","r",stdin);
    //freopen("JUDGER.out","w",stdout);
    cin >> n >> m;

    for (int i = 1; i <= n+1; i++) {
        M[i] = 1;
        S[ii(0,i)] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if ( type == 1 ) solve1();
        if ( type == 2 ) solve2();
        if ( type == 3 ) solve3();
        if ( type == 4 ) solve4();
    }
}
