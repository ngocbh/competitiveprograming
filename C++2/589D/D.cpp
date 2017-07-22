#include <bits/stdc++.h>
#include<string>

using namespace std;

const int nt = (int)3e4+10;
int n, ss=0;
vector<int> f[nt];

struct data{
       string x, y;
       int c;
};

string reset(string s){
       string s1;
       for (int i = 1; i<=s.size();++i){
           char c = s[i-1];
           if (c<='Z' && c>='A') c += 32;
           s1+=c;
       }
       return s1;
}

string p[nt], mau="bmail.com";
data a[nt];

void gan(int k){
     string s1 = "";
     for (int i = 1; i<=a[k].x.size(); ++i)
     { if (a[k].x[i-1]=='+') break;
       if (a[k].x[i-1]!='.') s1+=a[k].x[i-1];
     }
     a[k].x= s1;
}

bool check(data x, data y){
     if (x.y<y.y) return true;
     if (x.y==y.y && x.x <=y.x) return true;
     return false;
}

int main(){
    freopen("d.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i =1 ; i<= n; ++i){
        cin >> p[i];
        int g = p[i].find('@');
        a[i].x = reset(p[i].substr(0,g));
        a[i].y = reset(p[i].substr(g+1,p[i].size()));
        a[i].c = i;
    }
    for (int i =1 ; i<= n; ++i)
        if (a[i].y == mau) gan(i);
    sort(a+1,a+n+1,check);
    for (int i =1 ; i<= n; ++i) {
        if (i==1 || (a[i].y!=a[i-1].y or a[i].x!=a[i-1].x)) ++ss;
        f[ss].push_back(a[i].c);
    }
    cout << ss << endl;
    for (int i = 1; i<=ss ; ++i){
        cout << f[i].size() << " ";
        for (int j = 1; j<=f[i].size();++j) cout << p[f[i][j-1]] << " " ;
        cout << endl;
    }
}
