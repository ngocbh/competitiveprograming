#include <fstream>
#include <memory.h>
#define maxn 20+10
using namespace std;
ifstream fi("escape.inp");
ofstream fo("escape.out");

int n,a[maxn],x[maxn],res=0;
void xulykq()
{   int b[maxn],k=0;
    memset(b,0,sizeof(b));
    for (int i=1; i<=n; i++)
        if (x[i]==1) b[++k]=a[i];
    if (k<=res) return;

    for (int o=1; o<=8; o++) {
        int sum=0;
        for (int i=1; i<=k; i++){
            sum+=b[i]%10;
            b[i]=b[i]/10;
        }
        if (sum>9) return ;
        if (sum==0) break;

    }
    res=k;

}
void xulykq1()
{
    for (int i=1; i<=n; i++) fo<<x[i]<< " ";
    fo<<endl;
}
void try1(int i)
{   if (i>n) {xulykq();return; }
    for (int j=0; j<=1; j++){
        x[i]=j;
        try1(i+1);
    }
}
int main()
{
        fi>>n;
        for (int i=1; i<=n; i++) fi>>a[i];
        try1(1);
        fo<<res;

}
