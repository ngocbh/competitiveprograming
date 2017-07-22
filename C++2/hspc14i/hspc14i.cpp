#include <bits/stdc++.h>

using namespace std;
int a[4],ta[1000000],cs=0;
void xuly()
{int dem=0;
    cin>>a[1]>>a[2]>>a[3];
 /*  while ( a[3]-a[2]>1 || a[2]-a[1]>1 ){
        if (a[3]-a[2]>a[2]-a[1]) a[1]=a[2]+1;
        else a[3]=a[2]-1;
        sort(a+1,a+3+1);
        ++dem;
   }*/
  // ++cs;
  // ta[cs]=dem;
  cout<<max(a[2]-a[1],a[3]-a[2])-1<<endl;




}
int main()
{
while (!cin.eof())
xuly();
//for(int i=1; i<=cs; i++) cout<<ta[i]<<endl;
}
