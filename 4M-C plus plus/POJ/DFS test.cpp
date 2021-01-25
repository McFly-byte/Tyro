#include<iostream>

using namespace std;

struct node{
	bool isNew;//falseÎª¾Éµã; 
	bool isEnd;
	node* a;
	node* b;
	node* c;
	node* d;
}; 

bool dfs(node*s);

int main()
{
	node v[11];
	for(int i = 1; i<11; i++)
	{
		v[i].isNew = true;
		v[i].isEnd = false;
		v[i].a = NULL;
		v[i].b = NULL;
		v[i].c = NULL;
		v[i].d = NULL;
	}
	v[1].a = &v[2];v[1].b = &v[3];
	v[2].a = &v[1];v[2].b = &v[4];
	v[3].a = &v[1];v[3].b = &v[4];v[3].c = &v[4];v[3].d = &v[7];
	v[4].a = &v[2];v[4].b = &v[3];v[4].c = &v[8];
	v[5].a = &v[3];v[5].b = &v[4];v[5].c = &v[6];
	v[6].a = &v[5];v[6].b = &v[8];
	v[7].a = &v[3];v[7].a = &v[9];v[7].a = &v[10];
	v[8].isEnd = true;
	v[9].a = &v[7];
	v[10].a = &v[7];
	
	if(dfs(&v[1]))
		cout<<"Yes, I finally find it."<<endl;
	return 0;
}

bool dfs(node* v)
{
	if(v==NULL)
		return false;
	if(v->isNew == false)
		return false;
	if(v->isEnd)
		return true;
	v->isNew = false;
	if(dfs(v->a))
	 return true;	
	else if(dfs(v->b))
	 return true;
	else if(dfs(v->c))
	 return true;
	else if(dfs(v->d))
	 return true;
	else
		return false;
}
