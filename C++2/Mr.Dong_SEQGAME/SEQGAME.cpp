#include <bits/stdc++.h>

using namespace std;

const long N = 100 + 10;

int n, m, k;
int a[N];

void solve()
{
    double res = 1000000;
    int csi, csj;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if ( i == j ) continue;
            if ( res > (double) abs(1-(double)a[i]/a[j]) )
            {
                res = (double) abs(1-(double)a[i]/a[j]);
                csi = i;
                csj = j;
            }
        }

    int rem = a[csi] + a[csj];
    a[csi] = a[csj] = rem;
}

void chuanhoa(string &a, string &b)
{
    while ( a.size() < b.size() ) a = "0" + a;
    while ( b.size() < a.size() ) b = "0" + b;
}

string add(string a,string b)
{
    string s = "";
    chuanhoa(a,b);
    int rem = 0 , n = a.size();
    for (int i = n-1; i >= 0; i--)
    {
        int x = a[i] + b[i] - '0' - '0' + rem;
        char c = (char) (x%10 + '0');
        s = c + s;
        rem = (x >= 10);
    }

    if ( rem ) s = "1" + s;

    while ( s[0] == '0' ) s.erase(0,1);
    return s;
}

string mutil(string a,int b)
{
    string s = a;
    for (int i = 1; i < b; i++)
        s = add(s,a);

    return s;
}

int main()
{
    freopen("SEQGAME.inp","r",stdin);
    freopen("SEQGAME.out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    solve();

    string s = "1";

    for (int i = 1; i <= n; i++) s = mutil(s,a[i]);

    for (int i = 1; i < k; i++) s = mutil(s,4);

    cout << s;
}
