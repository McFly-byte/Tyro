#include<iostream>
#include<cstring> 

using namespace std;

int ans[100] = {0};
int s[100] = {0}, t[100] = {0};

int main()							//时常小心数组用时误写为字符数组 
{
	char a[100],b[100];
	char ch;
	while(cin>>a>>b>>ch){											//输入数据 
		
		int alen = strlen(a);
		for(int i = 0; i<alen; i++)
		{
			s[i] = a[alen-i-1] -  '0';				
		 } 
		int blen = strlen(b);					
		for(int j = 0; j<blen; j++)
		{
			t[j] = b[blen-1-j] - '0';			
		}										    			//反向读入
		
		int i = 0;
		
		if(ch=='+'){											//高精度加法
			
			int sum = 0,relay = 0;								 
			int len = max(alen,blen);
			for( i = 0; i<len||relay; i++)
			{
				sum = s[i] + t[i] + relay;	
				ans[i] = sum%10;
				relay = sum/10; 
			}
			i--;	
		}
		
		else if(ch=='-'){										//高精度减法 （被减数在前） 
			
			int len = alen;
			for(i; i<len; i++)
			{
				if(s[i]>=t[i])					//记得是 ">=" 
					ans[i] = s[i] - t[i];
				else
				{
					s[i+1]--;
					s[i] += 10;
					ans[i] = s[i] - t[i];  
				}
			}
			i--;
			for(i; ans[i]==0; i--)
				if(i==0)
					break;				//for减法，同时防止减数被减数相等 
		}
		
		else if(ch=='*')											//高精度乘法 
		{
			
			int sum = 0, relay = 0;
			for(int j = 0;j<blen; j++)
			{
				for(int i = 0; i<alen||relay; i++)		//relay不为0不能退 
				{
					sum = s[i] * t[j] + ans[i+j] + relay;		
					ans[i+j] = sum%10;						
					relay = sum/10;
				}
			}
			i = alen + blen - 1;
			for(i; ans[i]==0;i--)
				if(i==0)
					break;	
		}
		
		else if(ch=='/'){												//高精度除法 
			
			
			
			存
			
			疑
			
			。 
			
			
			
			
			
			
		}

		
		for(i; i>=0; i--)
			cout<<ans[i];
		cout<<endl;												 //输出结果 
		
		memset(ans,0,400);
		memset(s,0,400);
		memset(t,0,400); 
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));									//为下一轮初始化 
	}
	return 0; 
}

