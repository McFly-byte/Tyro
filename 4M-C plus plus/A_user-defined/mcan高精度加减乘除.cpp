#include<iostream>
#include<cstring> 

using namespace std;

int ans[100] = {0};
int s[100] = {0}, t[100] = {0};

int main()							//ʱ��С��������ʱ��дΪ�ַ����� 
{
	char a[100],b[100];
	char ch;
	while(cin>>a>>b>>ch){											//�������� 
		
		int alen = strlen(a);
		for(int i = 0; i<alen; i++)
		{
			s[i] = a[alen-i-1] -  '0';				
		 } 
		int blen = strlen(b);					
		for(int j = 0; j<blen; j++)
		{
			t[j] = b[blen-1-j] - '0';			
		}										    			//�������
		
		int i = 0;
		
		if(ch=='+'){											//�߾��ȼӷ�
			
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
		
		else if(ch=='-'){										//�߾��ȼ��� ����������ǰ�� 
			
			int len = alen;
			for(i; i<len; i++)
			{
				if(s[i]>=t[i])					//�ǵ��� ">=" 
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
					break;				//for������ͬʱ��ֹ������������� 
		}
		
		else if(ch=='*')											//�߾��ȳ˷� 
		{
			
			int sum = 0, relay = 0;
			for(int j = 0;j<blen; j++)
			{
				for(int i = 0; i<alen||relay; i++)		//relay��Ϊ0������ 
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
		
		else if(ch=='/'){												//�߾��ȳ��� 
			
			
			
			��
			
			��
			
			�� 
			
			
			
			
			
			
		}

		
		for(i; i>=0; i--)
			cout<<ans[i];
		cout<<endl;												 //������ 
		
		memset(ans,0,400);
		memset(s,0,400);
		memset(t,0,400); 
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));									//Ϊ��һ�ֳ�ʼ�� 
	}
	return 0; 
}

