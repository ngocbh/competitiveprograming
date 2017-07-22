#include <iostream>
//#include <cmath>
#define fi cin
#define fo cout
using namespace std;
//ifstream fi("dseq.inp");
//ofstream fo("dseq.out");
int64_t a[1000010],f[1000010],fj[1000010];
int n;
pair <int64_t,int64_t> fmax[1000010],fmin[1000010];
void nhap()
{ fi>>n;
 for (int i=1; i<=n; ++i) fi>>a[i];


}
int64_t abs1(int64_t x)
{ if (x>=0) return x;
  else return -x;

}
void khoitao()
{ for (int i=1; i<=n; ++i) f[i]=f[i-1] + a[i];
  for (int j=n; j>=1; --j) fj[j]=fj[j+1]+a[j];
  for (int i=1; i<=n+1; ++i) fmax[i].first=-1000000010;
  //====================
  for (int i=n; i>=1; --i)
  { if (fj[i]>fmax[i+1].first)
      { fmax[i].first=fj[i];
        fmax[i].second=1;
      }
    else
    { if (fj[i]==fmax[i+1].first)
        { fmax[i].first=fj[i];
        fmax[i].second=fmax[i+1].second +1;
        }
     else
        { fmax[i].first=fmax[i+1].first;
       fmax[i].second=fmax[i+1].second;

        }
    }
  }
  //===================
   for (int i=n; i>=1; --i)
  { if (fj[i]<fmin[i+1].first)
      { fmin[i].first=fj[i];
        fmin[i].second=1;
      }
    else
    { if (fj[i]==fmin[i+1].first)
        { fmin[i].first=fj[i];
        fmin[i].second=fmin[i+1].second +1;
        }
     else
        { fmin[i].first=fmin[i+1].first;
       fmin[i].second=fmin[i+1].second;

        }
    }
  }

}
void xuly()
 { int64_t maxn,dem,maxn1,dem1;
   int bcl=100000000;
   maxn=(long long)-bcl*bcl; maxn1=(long long)-bcl*bcl;
      for (int i=1; i<=n-1; ++i)
      { if  (abs1(f[i]-fmax[i+1].first)>maxn)
            { maxn=abs1(f[i]-fmax[i+1].first);
                dem=fmax[i+1].second;
            }
        else
            if ((abs1(f[i]-fmax[i+1].first)==maxn))
                dem=dem+fmax[i+1].second;
            //================
        if  (abs1(f[i]-fmin[i+1].first)>maxn1)
            { maxn1=abs1(f[i]-fmin[i+1].first);
                dem1=fmin[i+1].second;
            }
        else
            if ((abs1(f[i]-fmin[i+1].first)==maxn1))
                dem1=dem1+fmin[i+1].second;
      }
if (maxn1<maxn)
 fo<<maxn<<" "<<dem;
 else fo<<maxn1<<" "<<dem1;
 }
int main()
{ nhap();
 khoitao();
 //for (int i=1; i<=n; ++i) fo<<fmin[i].second<<" "; fo<<endl;
 xuly();

 return 0;
}


