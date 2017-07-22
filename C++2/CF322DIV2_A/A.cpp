#include <bits/stdc++.h>


using namespace std;
int a, b;
int main()
{
    cin >> a >> b;
    if ( a > b ) swap(a,b);
    cout << a << " " << (b-a)/2;
}
