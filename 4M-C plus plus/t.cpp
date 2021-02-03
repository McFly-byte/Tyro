#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    string a;
    a.resize(100); //需要预先分配空间
    scanf("%s", &a[0]);
    printf("%s\n", a.c_str());
    return 0;
}
