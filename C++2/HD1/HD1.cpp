#include <bits/stdc++.h>

const long N = 200 + 10;
using namespace std;

string a, b;
int n, k1, k2;
bool f[N][N][N];
char s[N];

void print_ans()
{
    for (int i = 1; i <= n; i++)
        cout << s[i];
}

void duyet(int i,int x,int y)
{
    if ( f[i][x][y] ) return;
    f[i][x][y] = 1;

    if ( i > n && x == k1 && y == k2 ) {
        print_ans();
        exit(0);
    }
    if ( i > n ) return;

    s[i] = '0';
    duyet(i+1,x+(a[i-1] == '0'), y+(b[i-1] == '0'));
    s[i] = '1';
    duyet(i+1,x+(a[i-1] == '1'), y+(b[i-1] == '1'));
}

int main()
{   freopen("HD1.inp","r",stdin);
    freopen("HD1.out","w",stdout);
    cin >> k1 >> k2;
    cin >> a >> b;
    n = a.size();

    duyet(1,0,0);
}
