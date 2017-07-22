#include <bits/stdc++.h>
using namespace std;
ifstream fi("frac.inp");
ofstream fo("frac.out");
int64_t a,b,k,p,q,s,t,n;

int64_t mpl(int64_t c,int64_t d,int64_t p)
{ int64_t t;
  if (d==1) return (c%p);
  t=(mpl(c,d/2,p)*2)%p;
  if (d%2==0) return t;
  return ((t+c)%p);


}
int64_t tinhmu(int64_t x,int64_t y, int64_t p)
{  int64_t r,t,tg;
    r=1; t=x; tg=y;
   while (tg>0)
   { if (tg%2==1) r=(r*t)%p;
     t=(t*t)%p;
     tg=tg/2;
   }
   return r;

}

void xuly1()
{   int64_t d[100],res=0,kq,i=1,i1=0,i2=1,ca[1000],l,cs=0;
 int64_t kt;
     memset(d,0,sizeof(d));
     memset(ca,0,sizeof(ca));
      p=p%q; //cout<<p<<q;
     while (1==1){
        if (d[p]>0)  {
            i2=i;
            i1=d[p];
            l=i-d[p];
            // cout<<i<<" "<<d[p]<<endl;
           break;
        }
        d[p]=i;
        p=p*10;
        ca[i]=p/q;
        p=p%q;
        i++;

      }
   for (int i=1; i<=i1-1; i++) cs+=ca[i];
   for (int i=i1; i<=i2; i++) res+=ca[i];
   // ///=========================tinh 1>>s;
    int64_t ls,ress=0,lt,rest=0;
    if (s<i1) {
    for (int i=1; i<=s; i++) ress+=ca[i];
    } else {
    ls=(s-i1)/l;

    kt=(s-i1)%l;//cout<<kt<<" ";
   // if (kt==0) kt=l;
    if (s>1)
    for (int i=kt; i>=1; i--)
   {
        ress+=ca[i+i1-1];
    }  //cout<<ca[i]<<" "; cout<<"^"<<ress<<endl;
    ress+=ls*res; ress+=cs;
    }
    ///=========================
    lt=(t-i1+1)/l;
    kt=(t-i1+1)%l;
    //if (kt==0) kt=l;
   for (int i=kt; i>=1; i--)
        {
        rest+=ca[i+i1-1];
    } rest+=lt*res; rest+=cs; //cout<<rest<<" "<<ress<<endl;
    fo<<(rest-ress)%q<<endl;
}
void xuly()
{  int64_t res=0;
    fi>>p>>q>>s>>t;
if (t>100 && s!=t)
    {xuly1(); return;}
for (int i=s; i<=t; i++){
   int64_t m,t;
    m=tinhmu(10,i-1,q);
    t=((((p%q)*m)%q) *10 ) /q;
    //fo<<t;
    res=(res+t)%q;
}
fo<<res<<endl;
}
int main()
{
      fi>>n;
      for (int i=1; i<=n; i++) { xuly();}
}
