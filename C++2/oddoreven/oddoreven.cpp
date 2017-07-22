#include <fstream>
#include <cmath>
using namespace std;
ifstream fi("oddoreven.inp");
ofstream fo("oddoreven.out");
string sop="+-*",soe="02468..13579..",s,v;
int n,r,p,x,y,kq=0;
int ston(char c)
{
    return (int) (c-'0');
}
char ntos(int x)
{
    return (char) (x+48);
}
int main()
{  fi>>s; n=s.size();
   for (int i=1; i<=n; i++)
     if (sop.find(s[i])<=2) {v+=s[i-1]; v+=s[i];}
   v+=s[n-1]; v+="+";
   fi>>s;
   if (s=="Odd") {soe[5]='x';x=1;} else {soe[12]='x';x=0; }
   fi>>s;
   if (s=="Odd") {soe[6]='y'; y=1;}else {soe[13]='y'; y=0; }
   n=v.size(); r=0; p=1;
   for (int i=0; i<=n; i++)
     if (v[i]=='x') v[i]=ntos(x);

    for (int i=0; i<=n; i++)
     if (v[i]=='y') v[i]=ntos(y);
//fo<<v<<endl;

   int i=1;
    while (i<=n){
       int j=i,x;
      // fo<<v[j]<<" ";
       while (v[j]=='*'){
            int x,y;
            x=ston(v[j-1]);
            y=ston(v[j+1]);
            x=(x*y) % 2;
            v[j]='.';
            v[j-1]='.';
            v[j+1]=ntos(x);
            v[i-1]=ntos(x);
            j+=2;
       }

        i=j+2;
    }
    v+='0';
    kq=ston(v[0]);
    for (int i=1; i<=n; i+=2){
        if (v[i]=='.') continue;
        else {
            int x=0,y=0;
            if (v[i]=='+') {
                x=ston(v[i+1]);
                kq=kq+x;
            }
            else {
                x=ston(v[i+1]);
                kq=kq-x;
            }
        }
    }
   kq=abs(kq);
   kq=kq%2;
 //  fo<<v<<endl;
   if (kq==1)
    fo<<"Odd";
   else fo<<"Even";
}
