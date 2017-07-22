#include <fstream>

using namespace std;
ifstream fi("coltri.inp");
ofstream fo("coltri.out");
const long maxn=1000000+17;
int64_t t,n;
int a[2*maxn],f[2*maxn];
void ssnt()
{  int64_t m;
    m=2*maxn;
    a[0]=a[1]=true;
    for (int i=2; i<=m; i++)
        if (!a[i])
           for (int j=i+i; j<=m; j+=i) a[j]=true; /// sang so nguyen to
   // a[2]=true;
    for (int i=1; i<=m; i++)
        if (!a[i]) f[i]=f[i-1]+1;
        else f[i]=f[i-1]; ///=== dem so nguyen to <= i;

}
void xuly(int64_t n)
{  int64_t kq,t1=0,t2;
   /// tinh so luong tam giac khac mau
   t1=(f[n+1]-f[1]-1)*(n-(f[n+1]-f[1]-1)-1); /// dinh 1 co cong thuc khac

   for (int i=2; i<=n; i++){
       int64_t m,v;
       if (!a[i+1]) m=f[i+n]-f[i+1]+1;else /// voi moi so i . tinh so luong so nguyen to tu i --> i+n
       m=f[i+n]-f[i+1];
       v=((n-1-m)*m); ///=== so
       t1+=v;
   }
   t1/=2;
   //fo<<t1<<endl;
   t2=(n*(n-1)*(n-2) )/6; ///=== tong so tam giac duoc tao thanh
   kq=(t2-t1);///==== so tam giac khac mau
   fo<<kq<<endl;
}
int main()
{  fi>>t;
 ssnt();
 //for (int i=1; i<=10; i++) fo<<f[i]<<"#"<<endl;
 for (int i=1; i<=t; i++){
    fi>>n;
    xuly(n);
 }
 return 0;
}
