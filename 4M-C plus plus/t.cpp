#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    string a;
    a.resize(100); //��ҪԤ�ȷ���ռ�
    scanf("%s", &a[0]);
    printf("%s\n", a.c_str());
    return 0;
}
