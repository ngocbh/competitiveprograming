#include <bits/stdc++.h>

using namespace std;
int kq,k,p,a[1000100],t[1000100];
int tim(int i)
{
    int l=1,r=k,res=0;
    while (l<=r){
        int m;
        m=(l+r)/2;
        if (a[m]<x) res=m,l=m+1;
        else r=m-1;
    }
    return res;
}

int main()
{ freopen("rowan.inp","r",stdin);
  freopen("rowan.out","w",stdout);
  scanf("%d%d",&k,&p);
  for (int i=1; i<=k; i++)
    scanf("%d",&a[i]);
 // sort(a+1,a+n,greater<int>());
 memset(t,true,sizeof(t));
 int mp;
  while (1==1){
    int nho,maxn=0;
    for (int i=1; i<=k; i++)
       if (maxn<a[i]&&t[i]) {maxn=a[i]; nho=i;}
  }
}
