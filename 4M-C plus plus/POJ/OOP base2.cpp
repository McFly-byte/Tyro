#include<iostream>
#define N 21252
using namespace std;
int main()
{
	int p,e,i,d,caseNO=0;
	while(cin>>p>>e>>i>>d&&p!=-1)
	{
		caseNO++;
		int aim;
		for(aim=d+1;(aim-p)%23;++aim);
		for(;(aim-e)%28;aim+=23);
		for(;(aim-i)%33;aim+=23*28);
		cout<<"Case "<<caseNO<<": the next triple peak occurs in "<<aim-d<<" days."<<endl;
	}
	return 0;
}

