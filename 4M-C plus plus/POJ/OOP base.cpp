#include<iostream>

/* 
#include<memory>
#include<cstring>
#include<string>
using namespace std;

char oriLights[5];
char lights[5];
char result[5];

int getBit(char ch,int i)
{
	return (ch>>i) & 1;
}

void setBit(char &ch,int i,int k)
{
	if(k){
		ch |= ( 1 << i );
	}	
	else{
		ch &= ~( 1 << i );
	}
}

void exeBit(char& ch,int i)
{
	ch^=(1<<i);
}

void printResult(int t,char result[])
{
	cout<<"PUZZLE #"<<t<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<getBit(result[i],j);
			if(j<5)
			{
				cout<<' ';
			}
		}
		cout<<endl;
	}
}

int main()
{
	int N;cin>>N;
	for(int n=1;n<=N;n++)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<6;j++)
			{
				int s;cin>>s;
				setBit(oriLights[i],j,s); 
			}
		}//输入
		 
		for(int k=0;k<64;++k)
		{
			int switches = k;
			memcpy(lights,oriLights,sizeof(oriLights));
			for(int i=0;i<5;i++)
			{
				result[i]=switches;
				for(int j=0;j<6;j++)
				{
					if(getBit(switches,j))
					{
						if(j>0)
							exeBit(lights[i],j-1);
						exeBit(lights[i],j);
						if(j<5)
							exeBit(lights[i],j+1);
					}
				}
				if(i<4)
				{
					lights[i+1] ^= switches;
				}	
				switches=lights[i];
				
			}
			if(lights[4]==0)
				{
					printResult(n,result);
					break;
				}
		}
	}
	return 0;
}4开关灯1022*/ 


/*#include<cstring>

char Left[3][7],Right[3][7],gogogo[3][7];
bool isFake(char w,bool kg);

int main()
{
	int round;cin>>round;
	while(round--){
		for(int i=0;i<3;i++)
			cin>>Left[i]>>Right[i]>>gogogo[i];
		for(char word='A';word<='L';word++)
		{
			if(isFake(word,true))
			{
				cout<<word<<" is the counterfeit coin and it is light.\n";
				break;
			}
			else if(isFake(word,false))
			{
				cout<<word<<" is the counterfeit coin and it is heavy.\n";
				break;
			}
		}
	}
	return 0;
 } 
 
bool isFake(char w,bool kg)
{
	for(int i=0;i<3;++i)
	{
		char *plft,*prgt;
		if(kg)
		{
			plft = Left[i];
			prgt = Right[i];
		}
		else
		{
			plft = Right[i];
			prgt = Left[i];
		}
		
		switch(gogogo[i][0])
		{
			case 'e':
				if(strchr(plft,w)||strchr(prgt,w))
					return false;
				break;
			case 'u':
				if(strchr(prgt,w)==NULL)
					return false;
				break;
			case 'd':
				if(strchr(plft,w)==NULL)
					return false;
				break;
		}
	}
	return true;
}3称硬币*/ 

/*int main()
{
	#define tri(a) (a*a*a)
	int n;cin>>n;
	for(int a=2;a<=n;++a)
	{
		for(int b=2;b<a;++b)
		{
			for(int c=b;c<a;++c)
			{
				for(int d=c;d<a;d++)
				{
					if(tri(a)==tri(b)+tri(c)+tri(d))
					{
						cout<<"Cube:"<<a<<",Triple("<<b<<','<<c<<','<<d<<");"<<endl;					}
				}
			}
		}
	 } 
}1完美立方*/ 

/*int main()
{
	int p,e,i,d;
	while(cin>>p>>e>>i>>d)
	{
		int aim;
		for(aim=d+1;(aim-p)%23;++aim);
		for(;(aim-e)%28;aim+=23);
		for(;(aim-i)%33;aim+=23*28);
		cout<<aim-d; 
	}
}//2生理周期*/ 

