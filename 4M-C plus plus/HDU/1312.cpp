#include<iostream>//����DFS�����д�˿���Сʱ2.19�� 

using namespace std;

struct node{
	char bit;
	bool isNew;
};

int W,H;
int path = 0;
int pathcop = 0; 
node maze[21][21] = {0};					 //���ö�̬���飬�ȿ�����Ĺ̶����� 
bool flag;									//�������������

bool dfs(int ai,int aj)//H�У�W��; 
{
	if(maze[ai][aj].isNew == false)
		return false;
	if(maze[ai][aj].bit=='#')
		return false;
	maze[ai][aj].isNew = false;		
	pathcop++;
	if(ai!=0)
		flag = dfs(ai-1,aj);//�� 
		
	if(aj!=0)								//������if����else if 
		flag = dfs(ai,aj-1);//�� 
		
	if(ai!=H-1)
		flag = dfs(ai+1,aj);//�� 
			
	if(aj!=W-1)
		flag = dfs(ai,aj+1);//�� 

	path = max(path,pathcop);				//�����ʵ���� 
	return false;
 } 

int main()
{
	while(cin>>W>>H&&(W||H)){
	
	pathcop = path = 0;
	int ati,atj;
	for(int i = 0; i<H; i++)
		for(int j = 0; j<W; j++)
			{
				cin>>maze[i][j].bit;
				maze[i][j].isNew = true;
				if(maze[i][j].bit=='@')
				{
					ati = i;
					atj = j;
				}
			
			}
	dfs(ati,atj);
	cout<<path<<endl;
			
	}
	return 0;
}
