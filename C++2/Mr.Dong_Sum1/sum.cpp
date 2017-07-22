#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>
#define maxn 50+10

using namespace std;
ifstream fi("sum.inp");
ofstream fo("sum.out");
int k;
string s1,s;
int stringtonum(char c)
{
    return (int) (c - '0');
}
char numtostring(int n)
{
    return (char) (n+48);
}
void chuanhoa(string &a, string &b)
{
    int l1=a.length(),l2=b.length();
    if (l1>=l2)  b.insert(0,l1-l2,'0');
    else a.insert(0,l2-l1,'0');


}
string sum(string a,string b)
{
   string s="";
   chuanhoa(a,b);
   int l=a.length();
   int temp = 0;
   for (int i=l-1; i>=0; i--)
   {
      temp =stringtonum(a[i])+stringtonum(b[i])+temp;
      s.insert(0,1,numtostring(temp%10));
      temp=temp/10;
   }
   if (temp>0)
   {
       s.insert(0,1,numtostring(temp));
   }
   return s;
}
int main()
{
    fi>>k;

    s="0";
    while ( !fi.eof() ){
       fi>>s1;
       s=sum(s,s1);
       s1="0";
    }
    for (int i=0; i<=k-1; i++) fo<<s[i];

}
