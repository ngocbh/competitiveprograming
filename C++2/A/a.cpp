#include <string>
#include <iostream>
#include <stdio.h>
#define maxn 1000+10
using namespace std;
string sh,sa;
int n,m,t;
char lh[maxn],la[maxn];
void xlyc2(char c1, char c2,int t,int m)
{
    if (c1=='h') if (lh[m]=='r') return; else
    {if (c2=='r') { cout<<sh<<" "<<m<<" "<<t<<endl; lh[m]='r';}
        else {
            if (c2=='y')
               {  if (lh[m]=='q') lh[m]='y';
                  else {cout<<sh<<" "<<m<<" "<<t<<endl; lh[m]='r'; }

        }
    }
    }
    else if (la[m]=='r') return ; else {
        if (c2=='r')  {cout<<sa<<" "<<m<<" "<<t<<endl;la[m]='r'; }
        else {
            if (c2=='y')
               {  if (la[m]=='q') la[m]='y';
                  else {cout<<sa<<" "<<m<<" "<<t<<endl;la[m]='r';}
               }
        }
    }

}
void inp()
{
    cin>>sh;
    cin>>sa;
    cin>>n;
    for (int i=1; i<=99; i++) { lh[i]='q'; la[i]='q'; }
    for (int i=1; i<=n; i++){
        int t,m;
        char c1,c2;
        cin>>t>>c1>>m>>c2;
            xlyc2(c1,c2,t,m);
    }
}

int main()
{ ///freopen("a.inp","r",stdin);
  ///freopen("a.out","w",stdout);
    inp();

}
