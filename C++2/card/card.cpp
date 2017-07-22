#include <bits/stdc++.h>
#define fi cin
#define fo cout
using namespace std;
//ifstream fi("card.inp");
//ofstream fo("card.out");
const long maxn=100+10;
int n,a[maxn],b[maxn],c[2*maxn],resa=0,resb=0,t,a1[maxn],b1[maxn];
int tim(int x,int aa[maxn],int laa)
{
    int l=1,r=laa+1,res=0;
    aa[laa+1]=1000;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if (aa[mid]<=x) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res+1;
}
void xuly()
{   memset(c,true,sizeof(c));
    fi>>n;
    for (int i=1; i<=n; i++) {fi>>a[i]; resa+=a[i]; c[a[i]]=false; }
    sort(a+1,a+n+1);
    int l=1;
    for (int i=1; i<=2*n; i++)
        if (c[i]) {b[l++]=i; resb+=i; }
  //  for (int i=1; i<=n; i++) fo<<a[i]<<" "; fo<<endl;
 //   for (int i=1; i<=n; i++) fo<<b[i]<<" "; fo<<endl;
 // fo<<resa<<" "<<resb<<endl;
  ///===============================
  //int m;
 // m=tim(6,b,n); fo<<m<<"^"<<endl;
  ///===============================
  int la=n,lb=n;
  int k=0,luot=0;
  while (1==1){
         if (la==0 || lb==0) break;
        if (luot==0){
            int m;
            m=tim(k,a,la);
            if (m == (la+1)) {luot=1;k=0;}
            else {
                luot=1;
                k=a[m]; int ll=1;
                for (int i=1; i<=la; i++)
                   if (i!=m)
                    a1[ll++]=a[i];
                --la;
                for (int i=1; i<=la; i++) a[i]=a1[i];
            }

        }
        else {
            int m;
            m=tim(k,b,lb);
            if (m == (lb+1)) {luot=0;k=0;}
            else {
                luot=0;
                k=b[m]; int ll=1;
                for (int i=1; i<=lb; i++)
                   if (i!=m)
                    b1[ll++]=b[i];
                --lb;
                for (int i=1; i<=lb; i++) b[i]=b1[i];
            }
        }
  }
  fo<<lb<<endl<<la<<endl;

}
int main()
{ fi>>t;
   for (int oo=1; oo<=t; oo++) xuly();

}
