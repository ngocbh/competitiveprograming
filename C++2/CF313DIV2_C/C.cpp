#include <bits/stdc++.h>

//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
using namespace std;
int a1 , a2 , a3, a4, a5, a6;
int s(int x)
{
    return x*x;
}
int main()
{
        cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
        //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        cout << s(a1 + a2 + a3) - s(a1) - s(a3) - s(a5);
        //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

}
