#include <bits/stdc++.h>
#define cin fi
#define cout fo

const long long N = 1000000 + 10;
using namespace std;
ifstream fi("DIV.inp");
ofstream fo("DIV.out");

typedef long long LL;
typedef pair <int,int> ii;

int n;
int ca[N], p[N];
map <int,int> M;

void init()
{
    for (int i = 2; i < N; i++) {
        if ( p[i] != 0 ) continue;
        p[i] = i;
        for (int j = 2; j*i < N; j++)
            p[j*i] = i;
    }
}

void calc(int m)
{
    if ( m == 1 ) return;
    ++M[p[m]];
    calc(m/p[m]);
}

void solve(int m)
{
    M.clear();
    calc(m);
    calc(m+1);
    calc(m+2);
    LL un = 1, un2 = 1;
    for (map<int,int> :: iterator it = M.begin(); it != M.end(); it++) {
        un = un*(it->second+1);
        un2 = un2*(2*it->second + 1);
    }

    cout << (un2+1)/2 - un << endl;


}


int main()
{   //freopen("DIV.inp","r",stdin);
    //freopen("DIV.out","w",stdout);
    init();

    int t;
    cin >> t;
    while ( t-- ) {
        int m;
        cin >> m;
        solve(m);
    }
}
