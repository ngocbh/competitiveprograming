#include <bits/stdc++.h>

const long N = 2000 + 10;
using namespace std;

int n,a[N],cs[N],res=0,kq[N];
bool cmp(int i,int j)
{
    return a[i] > a[j];
}
int main()
{   //freopen("A.inp","r",stdin);
    //afjshognvsofds
    //afmopxcbafjo
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        { scanf("%d", &a[i]); cs[i] = i; }
        //asfafdfgd
    sort(cs + 1, cs + n +1 , cmp); kq[cs[1]] = 1;
    for (int i = 2; i <= n; i++) {
        if ( a[cs[i]] < a[cs[i-1]] )  kq[cs[i]] = i;
        else kq[cs[i]] = kq[cs[i-1]];
        ///aasdasdasdfopjsddf
    }
    for (int i = 1; i <= n; i++) printf("%d ", kq[i]);

}
