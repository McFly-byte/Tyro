//���鼯.cpp
#include<bits/stdc++.h>
using namespace std;//���ڱ����ǰ������£����Բ���������
int dp[100005];//dp[i]��¼������dp[i]Ϊ��β�����ֵ��
int main()
{
	int n;cin>>n;
	for(int kk=1;kk<=n;kk++){
		int t;cin>>t;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=t;i++)
		{
			scanf("%d",&dp[i]);
		}
		int l=1,r=1;//��¼����
		int temp=1;//��¼���
		int MAx=dp[1];
		for(int i=2;i<=t;i++)
		{
            if(dp[i-1]>=0)//dp[i-1]����0�����dp[i]�й���
            {
                dp[i]=dp[i-1]+dp[i];
            }else{temp=i;}
            if(dp[i]>MAx)
            {
            	MAx=dp[i];
            	l=temp;
         	    r=i;
            }
		}
		if(kk>=2){printf("\n");}
		printf("Case %d:\n",kk);
		printf("%d %d %d\n",MAx,l,r);
	}
}
