#include<iostream>
#include<algorithm>

using namespace std;

int D[100][100], MaxSave[100][100];
int n;

int MaxSum(int i,int j)
{
	if(MaxSave[i][j]!=-1)
		return MaxSave[i][j];
	if(i==n-1)
		MaxSave[i][j] = D[i][j];
	else{
		int y = MaxSum(i+1,j);
		int x = MaxSum(i+1,j+1);
		MaxSave[i][j] = D[i][j] + max(x,y);
	}
	return MaxSave[i][j];
}

int main()
{
	cin>>n;
	for(int i = 0; i<n ; i++)
	{
		for(int j = 0;j<=i; j++)
		{
			cin>>D[i][j];
			MaxSave[i][j] = -1;
		}
	}
	cout<<MaxSum(0,0)<<endl;
	return 0;
 } 
