#include <bits/stdc++.h>

using namespace std;
ifstream fi("exam.inp");
ofstream fo("exam.out");
int64_t l,r,res;
int main()
{   fi>>l>>r;
    for (int i=0; i<=174 ; i++){
        int64_t m;
        m=pow(i,6)*36000;
        if (m<=r && m>=l) ++res;
    }
    fo<<res;
}
