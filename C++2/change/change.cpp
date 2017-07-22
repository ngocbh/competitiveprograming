#include <bits/stdc++.h>

using namespace std;
int n,t,a[7]={1,5,10,50,100,500,1000};
void xuly()
{  int res=0;
    scanf("%d",&n);
    int r;
    r=1000-n;
    //printf("%d ",r);
    while (r!=0) {
        int nho=7;
       for (int i=0; i<=6; i++)
        if (a[i]>r) {nho=i; break; }
      //  printf("%d ",nho);
        --nho;
        r=r-a[nho];
        res+=1;
    }
    printf("%d\n",res);
}
int main()
{
   //freopen("change.inp","r",stdin);
   //freopen("change.out","w",stdout);
   scanf("%d",&t);
   for (int i=1; i<=t; i++) xuly();
}
