#include <stdio.h>
#include <cmath>
#include <iostream>
//#define lamtron(x) x<(int) x + 0.5 ? (int)x : (int)x +1
using namespace std;

double b,c;
int main()
{ cin>>c>>b;
  double a;
  for (int i=1; i<=100;++i)
  {  a=( double) ((b*pow(10,i-1)-b*c)/(10*c-1)) ;
//a=int(a);
     if ((int)a==a) {cout<<a<<b; return 0;}
     cout<<a<<endl;
  }
// a=(long double)12820;
 // if ((int)a==a)
  cout<<0;;
}

