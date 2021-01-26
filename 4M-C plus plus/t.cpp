#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits\stdc++.h>
using namespace std;

int card[6][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
int n , t;
int main(){
    cin >> n >> t;
    cout << card[n%6][t] << endl;;
    return 0;
}
