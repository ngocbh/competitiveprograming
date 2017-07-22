#include <bits/stdc++.h>

const long N = 1000 + 10;
const long base =  1000000000;
using namespace std;

int t,m,n,f[N][N],c[N][N],ca[2][N];

void init()
{
    for (int i = 0; i <= 1000; i++) c[i][0] = 1;
    for (int i = 0; i <= 1000; i++) c[0][i] = 1;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            c[i][j] = (c[i-1][j] + c[i][j-1]) % base;
}
void solve(int n,int m)
{   int im,ic;
    memset(f,0,sizeof(f));
    for (int i = 1; i <= m; i++) ca[0][i] = 1;
    im = 1; ic = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
                f[i][j] = (c[m][j] * ca[ic][j]) % base;
                cout<<ca[ic][j]<<" ";
                ca[im][j] = (ca[im][j-1] + f[i][j]) % base;
        }
        im = 1 - im; ic = 1 - ic;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) cout<<f[i][j]<<" "; cout<<endl; }
    printf("%d\n",f[n][m]);

}
int main()
{   freopen("STDYTAB.inp","r",stdin);
    scanf("%d", &t);
    init();
    while (t--){
        scanf("%d %d", &n, &m);
        solve(n,m);
    }
   // for (int i = 0; i <= 5; i++) {
    //    for (int j = 0; j <= 5; j++) cout<<c[i][j]<<" "; cout<<endl; }

}
