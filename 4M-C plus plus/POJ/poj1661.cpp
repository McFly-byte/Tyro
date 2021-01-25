#include<iostream>
#include<algorithm>

using namespace std;

int time;
int t;
int N;
int MAX;

struct location{
	int X;
	int Z;
} jimmy;

struct board{
	int leftLct;
	int rightLct;
	int height;
};

void swapBD(board &a,board &b);
void order(board a[],int n);
int isABoard(int X,int Z,board *bd,int n);//返回板的高度； 
int leftime(int X, int Z,board *bd,int n,int no);
int rightime(int X,int Z,board *bd,int n,int no);

int main()
{	cin>>t;
for(int id=0;id<t;id++){
	
	time = 0;
	cin>>N>>jimmy.X>>jimmy.Z>>MAX;
	board bd[N];
	for(int i=0;i<N;i++)
		cin>>bd[i].leftLct>>bd[i].rightLct>>bd[i].height;
	
	order(bd,N);
	int tmp = bd[0].height - jimmy.Z;
	jimmy.Z = bd[0].height;  
	time+=min(leftime(jimmy.X, jimmy.Z, bd, N,0),
	rightime(jimmy.X, jimmy.Z, bd, N,0));
		
	cout<<time<<endl;
		
	}
	return  0;
}

void swapBD(board *a,board *b)
{
	int tmp = b->height;
	b->height = a->height;
	a->height = tmp;
	tmp = b->leftLct;
	b->leftLct = a->leftLct;
	a->leftLct = tmp;
	tmp = b->rightLct;
	b->rightLct = a->rightLct;
	a->rightLct = b->rightLct;
}

void order(board a[],int n)
{
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--)
			if(a[j].height>a[j-1].height)
				swap(a[j],a[j-1]);
	}
}

int isABoard(int X,int Z,board *bd,int n)
{
	for(int i=0;i<n;i++)
	{
		if(Z-bd[i].height<=MAX&&Z>bd[i].height
			&&bd[i].leftLct<=X&&bd[i].rightLct>=X)
			return i;
	}
	return -1;
}

int leftime(int X, int Z,board *bd,int n,int NO)
{
	int tiktok = 0;
	int isaboard = isABoard(X,Z,bd,n);
	if(isaboard==-1)
		return min(X-bd[NO].leftLct,X-bd[NO].rightLct) + Z;
	else
	 	tiktok += min(leftime(X,Z,bd,n,isaboard),rightime(X,Z,bd,n,isaboard));
	return tiktok;
}

int rightime(int X, int Z,board *bd,int n,int NO)
{
	int tiktok = 0;
	int isaboard = isABoard(X,Z,bd,n);
	if(isaboard==-1)
		return min(X-bd[NO].leftLct,X-bd[NO].rightLct) + Z;
	else
	 	tiktok += min(leftime(X,Z,bd,n,isaboard),rightime(X,Z,bd,n,isaboard));
	return tiktok;
}
