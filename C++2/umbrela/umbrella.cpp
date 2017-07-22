#include <fstream>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define maxn 5100
#define maxm 100000+1000
#define oo 100000000
using namespace std;
ifstream fi("umbrella.inp");
ofstream fo("umbrella.out");
int64_t n,m,c[maxm],a[maxn],f[maxn];
int main()
{
    fi>>n>>m;
    for (int i=1; i<=n; i++) fi>>a[i];
    for (int i=1; i<=m; i++) fi>>c[i];
    ///===docx
    sort(a+1,a+n+1);
    for (int i=1; i<=n;i++) f[i]=oo*oo;
    f[0]=0;
    ///===khoitao
    for (int i=1; i<=n; i++){
        for (int j=i-1; j>=0; j--)
            f[i]=min(f[i],f[j]+c[a[i]-a[j+1]+1]);
            fo<<f[i]<<" ";
    }
    ///===qhd
    fo<<f[n];
    ///===ghi kq

}
