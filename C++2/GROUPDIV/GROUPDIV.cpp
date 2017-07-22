#include <bits/stdc++.h>
    #define cin fi
    #define cout fo

const long N = 3*100000 + 10;
using namespace std;
typedef pair <int,int> ii;
    ifstream fi("GROUPDIV.inp");
    ofstream fo("GROUPDIV.out");

int n, m;
int ca[N], num[N];

vector <int> a[N];


int main()
{   //freopen("GROUPDIV.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int u;
            cin >> u;
            a[i].push_back(u);
        }
    }

    memset(ca,0,sizeof ca);
    while ( true ) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int d = 0;
            for (int j = 0; j < a[i].size(); j++) {
                int v = a[i][j];
                if ( ca[v] == ca[i] ) ++d;
            }

            if ( d >= 2 ) {
                    ca[i] = 1 - ca[i], ok = false;
            }
        }
        if ( ok ) break;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        if ( !ca[i] ) cout << i << " " ; cout << endl;
    for (int i = 1; i <= n; i++)
        if ( ca[i] ) cout << i <<  " "; cout << endl;
}
