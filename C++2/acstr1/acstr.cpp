#include <bits/stdc++.h>

using namespace std;
ifstream fi("acstr.inp");
ofstream fo("acstr.out");
const long maxm=1000+10;
const long maxn=10000+100;
const long maxk=1000+10;

int m,k,c[maxk][1000],t[maxk],nn,n,ma[maxn],nho=0;
string s,w;
void xuly1()
{   memset(ma,0,sizeof(ma));
   nho=0;
    for (int i=0; i<=nn-1; i++)
            nho+=t[i]-c[i][w[i]]; ///=== tinh so loi voi k==0;
    for (int i=0; i<=nn-1; i++)
       for (int j='a'; j<='z'; j++)
           ma[i]=max(ma[i],c[i][j]); ///==== tai moi vi tri tim vi tri co nhieu loi nhat;
    ///==========================
    for (int i=0; i<=nn-1; i++) ma[i]=ma[i]-c[i][w[i]]; /// tinh so loi tai moi vi tri
    sort(ma,ma+nn,greater<int>() ); ///==== sap xep lai va chon k phan tu nhieu loi nhat de sua;
    int res=0;
    for (int i=0; i<=k-1; i++) res+=ma[i];
    fo<<nho-res<<endl;
}
void xuly()
{   nn=w.size();
    memset(c,0,sizeof(c));
    memset(t,0,sizeof(t));
    for (int i=0; i<=nn-1; i++){ /// tinh so lan xuat hien cua ki tu s[i+j*nn] tai vi tri i trong xau w;
        int j=0;
        while (i+j*nn<=n){ ++c[i][s[i+j*nn]];
            j++;
        }
    }
    //========================
    for (int i=0; i<=nn-1; i++) /// tinh tong so ki tu tai vi tri i;
        for (int j='a'; j<='z'; j++)
            t[i]+=c[i][j];
    //==========================
    if (k>1){ xuly1(); ///=== so loi > 1
        return;
    }
    if (k==0){ /// so loi == 0.
        int res=0;
        for (int i=0; i<=nn-1; i++)
            res+=t[i]-c[i][w[i]]; /// so loi tai vi tri i == so ki tu khac w[i] nam tai vi tri i;
        fo<<res<<endl;
        return;

    }
   // fo<<c[0]['a'];
  //  for (int i=0; i<=nn-1; i++) fo<<t[i]<<" "; fo<<endl;
    if (k==1){
        int res=0;
        for (int i=0; i<=nn-1; i++)
            res+=t[i]-c[i][w[i]];
        //==========================
        for (int i=0; i<=nn-1; i++){
            int mm=-1,m1,kq=0;
            int cc,ii;
            ii=(int) w[i];
            for (int j='a'; j<='z'; j++)
                if (c[i][j]>mm )
              //    if ((int)j!=ii)
                {  //cout << j << endl;
                     mm=c[i][j];
                     cc=j;
                }
              //  fo<<(char)cc<<"&"<<endl;;
            for (int j=0;j<=nn-1; j++){
                if (j!=i)kq+=t[j]-c[j][w[j]];
                else kq+=t[j]-c[j][cc];
               // cout<<t[j]<<endl;
                }
            if (kq<res) res=kq;
            if (kq==0) {fo<<kq<<endl; return;}
        }
        fo<<res<<endl;
        return;

    }
}
int main()
{ fi>>m>>k;
  fi>>s; n=s.size();
  for (int i=1; i<=m; i++) {fi>>w; xuly();}

}
