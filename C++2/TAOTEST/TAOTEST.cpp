#include <stdio.h>

using namespace std;

int main()
{       freopen("in.inp","w",stdout);
        printf("100000 100000\n");
        for (int i = 1; i <= 100000; i++) printf("1 "); printf("\n");
        printf("4 1 100000\n");
        for (int i = 1; i <= 100000-2; i++) printf("1 1 2 1\n");
        printf("4 1 100000\n");
}
