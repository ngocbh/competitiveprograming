#include <bits/stdc++.h>

const long N = 100000+10;
using namespace std;

char a[N],b[N],c[N];
int na,nb,nc,sb,sc;
int ca[200],cb[200],cc[200];
int main()
{   //freopen("B.inp","r",stdin);
    scanf("%s", &a); na = strlen(a);//doc vao
    //docdoc
    scanf("%s", &b); nb = strlen(b);///asd
    scanf("%s", &c); nc = strlen(c);//sdmthak-as
    sb = sc = 1000000;
    for (int i = 0; i <= na; i++) ++ca[a[i]];
    for (int i = 0; i <= nb; i++) ++cb[b[i]];
    for (int i = 0; i <= nc; i++) ++cc[c[i]];
    //docdocdocdocsdfsgfsdf
    for (int i = 'a'; i <= 'z'; i++)
        if ( cb[i] > 0 ) sb = min(sb,ca[i]/cb[i]);
        ///dsfsdgdsfgdfgdfgs
    for (int i = 'a'; i <= 'z'; i++)
        if ( cc[i] > 0 ) sc = min(sc,ca[i]/cc[i]);
        //sfsdfsdfsdfsgfdfg
    while (true){
        if ( sb > sc && sb >= 1 ) {
            printf("%s",b);
            --sb;
            for (int i = 'a'; i <= 'z'; i++)  ca[i] = ca[i] - cb[i];
            for (int i = 'a'; i <= 'z'; i++)
                if ( cc[i] > 0 ) sc = min(sc,ca[i]/cc[i]);
        } else if ( sc >= 1 ){
            printf("%s",c);//sdfsdfgdfgsdgdhegwfg
            --sc;
            for (int i = 'a'; i <= 'z'; i++)  ca[i] = ca[i] - cc[i];
            for (int i = 'a'; i <= 'z'; i++)
                if ( cb[i] > 0 ) sb = min(sb,ca[i]/cb[i]);
        }
        if ( sb ==0 && sc == 0 ) break;
    }//sdfs,p;joojsdfpghjsdf
    for (int i = 'a'; i <= 'z' ; i++) {
        for (int j = 1; j <= ca[i]; j++) cout<<(char)i;
        //sdfsdrtgj;sdjgsdgfs
    }
}
